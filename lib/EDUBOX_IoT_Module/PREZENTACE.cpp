void exercise_blinking_handlerStartBlinking_LightModule() {
  // /blink/start?period=...
  if (server_Light_Module.hasArg("period")) {
    String p = server_Light_Module.arg("period");
    long val = p.toInt(); // jednoduché, pro cvičení stačí

    if (val < 50 || val > 5000) {
      server_Light_Module.send(400, "text/plain", "Invalid period (50..5000 ms)");
      return;
    }
    blinkPeriodMs = (uint32_t)val;
  }

  blinking = true;
  lastToggleMs = millis();

  server_Light_Module.send(200, "text/plain", "BLINKING");
}

int blinkPeriodMs = 0;
WebServer webServer(80);

// /blink?period=500

void handlerBlink() {
  if (!webServer.hasArg("period")) {
    webServer.send(400, "text/plain", "Missing value");
    return;
  }

  String p = webServer.arg("period");
  int period = p.toInt();
  blinkPeriodMs = period; // Globalní proměnná
  webServer.send(200, "text/plain", "DONE");
}



void handlerLEDon() {
    digitalWrite(LEDPIN, HIGH);
    webServer.send(200, "application/text", "ON");
}
