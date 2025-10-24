/**
 * @file EDUBOX_knihovny-servo.cpp
 * @brief Simple, well-documented example library for controlling a hobby servo on ESP32 (PlatformIO).
 *
 * This file is written as a compact, educational example showing:
 *  - how to include a servo library,
 *  - a small wrapper class with both blocking and non-blocking sweep routines,
 *  - Doxygen-style comments that explain usage and integration with PlatformIO.
 *
 * NOTES:
 *  - Recommended PlatformIO dependency (add to platformio.ini):
 *      lib_deps =
 *        ESP32Servo    ; commonly used Servo library compatible with ESP32
 *
 *  - Include in your sketch (example below) as:
 *      #include "EDUBOX_knihovny-servo.cpp"
 *    For a real library, split into .h/.cpp and include the header. This single-file example is for learning.
 *
 *  - This example uses the Arduino-style Servo API:
 *      attach(pin), write(angle), writeMicroseconds(us), detach(), attached()
 *
 *  - Keep this file in your project's lib/EDUBOX_knihovny-servo/ folder for PlatformIO to compile it automatically.
 */

#include <Arduino.h>
#include <Servo.h>

/**
 * @class EDUBOX_Servo
 * @brief Small wrapper around the Servo library with extra helpers and Doxygen documentation.
 *
 * Purpose:
 *  - Demonstrate typical library structure and usage for PlatformIO + ESP32
 *  - Provide blocking and non-blocking sweep examples for a hobby servo
 *
 * Usage:
 *  - Create an instance, call begin(), attach(pin), then use writeAngle() / writeMicroseconds().
 *  - For non-blocking motion call startSweepNonBlocking(...) and then call update() frequently
 *    from loop().
 */
class EDUBOX_Servo {
public:
    /**
     * @brief Construct a new EDUBOX_Servo object.
     *
     * The underlying Servo object is created here. Nothing is attached yet.
     */
    EDUBOX_Servo()
        : _attached(false),
          _pin(-1),
          _currentAngle(0),
          _sweepRunning(false),
          _sweepStart(0),
          _sweepEnd(0),
          _sweepStep(1),
          _sweepIntervalMs(20),
          _lastSweepMillis(0),
          _sweepDirection(1)
    {
    }

    /**
     * @brief Initialize library internals (optional for this simple wrapper).
     *
     * Call this in setup() if you want a clear initialization point.
     */
    void begin() {
        // Nothing required for Servo library on ESP32, but keep API consistent.
        _attached = false;
        _pin = -1;
        _currentAngle = 0;
    }

    /**
     * @brief Attach servo signal wire to a GPIO pin.
     * @param pin GPIO pin number (use a PWM-capable pin recommended for ESP32).
     * @return true if attach succeeded (servo reports attached), false otherwise.
     */
    bool attach(int pin) {
        _pin = pin;
        _servo.attach(pin);
        _attached = _servo.attached();
        return _attached;
    }

    /**
     * @brief Detach the servo to free the PWM channel.
     */
    void detach() {
        _servo.detach();
        _attached = false;
        _pin = -1;
    }

    /**
     * @brief Write an angle in degrees (0..180) to the servo.
     * @param angle Angle in degrees. Values are constrained to [0, 180].
     */
    void writeAngle(int angle) {
        if (!_attached) return;
        angle = constrain(angle, 0, 180);
        _servo.write(angle);
        _currentAngle = angle;
    }

    /**
     * @brief Write microseconds directly to the servo (useful for raw pulse control).
     * @param microseconds Pulse width in microseconds (typically ~500..2500 for servos).
     */
    void writeMicroseconds(int microseconds) {
        if (!_attached) return;
        _servo.writeMicroseconds(microseconds);
        // No reliable conversion to angle here; leave _currentAngle unchanged.
    }

    /**
     * @brief Read last written angle (track only if writeAngle() used).
     * @return int Last written angle or -1 if unknown.
     */
    int readAngle() const {
        return _currentAngle;
    }

    /**
     * @brief Check if servo is attached.
     * @return true if attached.
     */
    bool attached() const {
        return _attached;
    }

    /**
     * @brief Blocking sweep between two angles.
     *
     * This routine performs a blocking sweep. It should not be used if your sketch needs
     * to remain responsive to other tasks (network, sensors, UI) during the sweep.
     *
     * @param startAngle Starting angle (degrees).
     * @param endAngle Ending angle (degrees).
     * @param step Step size in degrees (positive non-zero).
     * @param delayMs Delay between steps in milliseconds.
     */
    void sweepBlocking(int startAngle, int endAngle, int step = 1, unsigned long delayMs = 15) {
        if (!_attached) return;
        if (step <= 0) step = 1;
        startAngle = constrain(startAngle, 0, 180);
        endAngle = constrain(endAngle, 0, 180);

        if (startAngle <= endAngle) {
            for (int a = startAngle; a <= endAngle; a += step) {
                writeAngle(a);
                delay(delayMs);
            }
        } else {
            for (int a = startAngle; a >= endAngle; a -= step) {
                writeAngle(a);
                delay(delayMs);
            }
        }
    }

    /**
     * @brief Start a non-blocking sweep between two angles.
     *
     * After calling this, call update() frequently (e.g., from loop()) to progress the sweep.
     *
     * @param startAngle Starting angle (degrees).
     * @param endAngle Ending angle (degrees).
     * @param step Step size in degrees (positive non-zero).
     * @param intervalMs Time in ms between steps.
     */
    void startSweepNonBlocking(int startAngle, int endAngle, int step = 1, unsigned long intervalMs = 20) {
        if (!_attached) return;
        if (step <= 0) step = 1;
        _sweepStart = constrain(startAngle, 0, 180);
        _sweepEnd = constrain(endAngle, 0, 180);
        _sweepStep = step;
        _sweepIntervalMs = intervalMs;
        _currentAngle = _sweepStart;
        _sweepDirection = (_sweepEnd >= _sweepStart) ? 1 : -1;
        _lastSweepMillis = millis();
        writeAngle(_currentAngle);
        _sweepRunning = true;
    }

    /**
     * @brief Stop a running non-blocking sweep.
     */
    void stopSweep() {
        _sweepRunning = false;
    }

    /**
     * @brief Progress the non-blocking sweep. Call this from loop() often.
     *
     * This method performs time checks and steps the servo when the interval has elapsed.
     */
    void update() {
        if (!_attached || !_sweepRunning) return;
        unsigned long now = millis();
        if (now - _lastSweepMillis < _sweepIntervalMs) return;

        _lastSweepMillis = now;

        // Advance angle respecting direction and step size
        int next = _currentAngle + (_sweepDirection * _sweepStep);

        // Check for overshoot and clamp to end
        if ((_sweepDirection > 0 && next >= _sweepEnd) || (_sweepDirection < 0 && next <= _sweepEnd)) {
            writeAngle(_sweepEnd);
            _sweepRunning = false; // finished
        } else {
            writeAngle(next);
        }
    }

    /**
     * @brief Check if a non-blocking sweep is running.
     * @return true if sweep running.
     */
    bool isSweepRunning() const {
        return _sweepRunning;
    }

private:
    Servo _servo;                    ///< Underlying Servo object
    bool _attached;                  ///< True if currently attached
    int _pin;                        ///< Attached pin or -1
    int _currentAngle;               ///< Last angle set via writeAngle()

    // Non-blocking sweep state
    bool _sweepRunning;
    int _sweepStart;
    int _sweepEnd;
    int _sweepStep;
    unsigned long _sweepIntervalMs;
    unsigned long _lastSweepMillis;
    int _sweepDirection;
};

/**
 * Example usage (copy into your sketch .ino or .cpp file):
 *
 * #include "EDUBOX_knihovny-servo.cpp"   // educational single-file include
 *
 * EDUBOX_Servo myServo;
 *
 * void setup() {
 *   Serial.begin(115200);
 *   myServo.begin();
 *   if (myServo.attach(18)) {           // attach to GPIO18 (example)
 *     Serial.println("Servo attached.");
 *   }
 *   // Blocking sweep:
 *   myServo.sweepBlocking(0, 180, 2, 10);
 *
 *   // Start a non-blocking sweep and return to doing other work
 *   myServo.startSweepNonBlocking(0, 180, 1, 15);
 * }
 *
 * void loop() {
 *   // Keep calling update to progress the non-blocking sweep
 *   myServo.update();
 *
 *   // Do other tasks (network, sensors, display updates, etc.)
 * }
 *
 * Doxygen tags in this file explain the available functions and typical usage.
 */