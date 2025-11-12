-WiFi.h
WiFi.begin(ssid, password);
WiFi.status() != WL_CONNECTED
WiFi.localIP()

-WebServer.h
WebServer server_TempHum_Module(80);
server_TempHum_Module.on("/data", hadleData);
server_TempHum_Module.begin();
server_TempHum_Module.handleClient();

-pgmspace.h
const char LIGHT_MODULE_HTML[] PROGMEM = R"HTML( )HTML";

# ESP32: `WiFi.h`, `WebServer.h` – stručné vysvětlivky

Níže najdeš praktické poznámky k uvedeným voláním: co dělají, kdy je použít, co vracejí a na co si dát pozor.

## `WiFi.h` (ESP32/ESP8266)

### `WiFi.begin(ssid, password);`
- **Co dělá:** Spustí proces připojení k Wi-Fi síti se zadanými přihlašovacími údaji.
- **Kdy volat:** Typicky v `setup()`.
- **Návratová hodnota:** `void` (samotné připojení probíhá asynchronně).
- **Tip:** SSID/heslo měj jako `const char*` nebo použij `String.c_str()`.

### `WiFi.status() != WL_CONNECTED`
- **Co dělá:** Vrací stav Wi-Fi (`wl_status_t`). S `WL_CONNECTED` víš, že jsi připojen.
- **Běžné stavy:** `WL_IDLE_STATUS`, `WL_NO_SSID_AVAIL`, `WL_CONNECT_FAILED`, `WL_DISCONNECTED`, `WL_CONNECTED`.
- **Použití:** V `while`/`if` k čekání s timeoutem.

### `WiFi.localIP()`
- **Co dělá:** Vrací lokální IP adresu zařízení (typ `IPAddress`).
- **Pozn.:** Dává smysl až po úspěšném připojení.
- **Výpis:** `Serial.println(WiFi.localIP());` → formát `x.x.x.x`.

---

## `WebServer.h` (ESP32/ESP8266 WebServer)

### `WebServer server_TempHum_Module(80);`
- **Co dělá:** Vytvoří HTTP server naslouchající na portu 80.
- **Pozn.:** Můžeš zvolit jiný port (např. 8080), pokud 80 koliduje.

### `server_TempHum_Module.on("/data", handleData);`
- **Co dělá:** Registruje obsluhu (callback) pro GET požadavky na cestě `/data`.
- **Signatura handleru:** `void handleData()`; odpověď posílej pomocí `server.send(...)`.
- **Pozn.:** Správný název je `handleData` (ne `hadleData`).

### `server_TempHum_Module.begin();`
- **Co dělá:** Spustí server (otevře sockety a zaregistruje routy).
- **Kdy volat:** V `setup()` po připojení k Wi-Fi.

### `server_TempHum_Module.handleClient();`
- **Co dělá:** Zpracuje příchozí HTTP požadavky.
- **Důležité:** Musí se volat *často* (každý průchod `loop()`), jinak server nereaguje.
