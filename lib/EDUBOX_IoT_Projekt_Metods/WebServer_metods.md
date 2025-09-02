# WebServer.h – Přehled metod (ESP32 Arduino Core)

## 📌 1. Spuštění a základní obsluha
| Metoda | Popis |
|--------|-------|
| `WebServer(uint16_t port)` | Konstruktor, vytvoří server na zadaném portu (např. `WebServer server(80)`) |
| `begin()` | Spustí server (začne poslouchat na portu) |
| `close()` | Ukončí server |
| `stop()` | Alias pro `close()` (zastaví server) |
| `handleClient()` | Zpracuje příchozí HTTP požadavky (volat pravidelně v `loop()`) |

---

## 📌 2. Registrace rout
| Metoda | Popis |
|--------|-------|
| `on(uri, handler)` | Registruje obsluhu pro GET požadavek na danou cestu (`server.on("/", handleRoot)`) |
| `on(uri, method, handler)` | Registruje obsluhu pro konkrétní HTTP metodu (`HTTP_GET`, `HTTP_POST`, ...) |
| `onNotFound(handler)` | Funkce, která se zavolá, když není nalezena odpovídající route |
| `onFileUpload(handler)` | Nastaví handler pro nahrávání souborů (POST s `multipart/form-data`) |

---

## 📌 3. Odesílání odpovědi
| Metoda | Popis |
|--------|-------|
| `send(code, content_type, content)` | Odešle odpověď (`server.send(200, "text/plain", "OK")`) |
| `send_P(code, content_type, PSTR)` | Odeslání dat uložených v PROGMEM |
| `sendHeader(name, value, first)` | Přidá HTTP hlavičku do odpovědi |
| `sendContent(content)` | Odeslání části obsahu (streamování dat po kouskách) |
| `setContentLength(len)` | Nastaví `Content-Length` hlavičku |

---

## 📌 4. Práce s požadavkem
| Metoda | Popis |
|--------|-------|
| `method()` | Vrátí HTTP metodu (`HTTP_GET`, `HTTP_POST`, …) |
| `uri()` | Vrátí požadovanou cestu (`String`) |
| `arg(name)` | Vrátí hodnotu parametru z query stringu nebo POST (`server.arg("teplota")`) |
| `argName(i)` | Název parametru podle indexu |
| `args()` | Vrátí počet argumentů |
| `hasArg(name)` | Zjistí, zda požadavek obsahuje argument |
| `hasHeader(name)` | Zjistí, zda požadavek obsahuje konkrétní hlavičku |
| `header(name)` | Vrátí hodnotu hlavičky |
| `upload()` | Vrátí strukturu s informacemi o nahrávaném souboru |

---

## 📌 5. Autentizace
| Metoda | Popis |
|--------|-------|
| `authenticate(username, password)` | HTTP Basic Auth, vrátí `true`/`false` |
| `requestAuthentication()` | Vyžádá přihlášení (odešle `401 Unauthorized`) |
