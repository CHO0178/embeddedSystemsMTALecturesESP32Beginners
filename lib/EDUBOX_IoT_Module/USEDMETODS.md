Knihovna:
#include <WebServer.h>

Definice třídy:
WebServer server_HTML(80);
  WebServer(IPAddress addr, int port = 80);
  WebServer(int port = 80);

Metody:
server_HTML.send(200, "text/html; charset=utf-8", page);
  void send(int code, const char* content_type = NULL, const String& content = String(""));
  void send(int code, char* content_type, const String& content);
  void send(int code, const String& content_type, const String& content);
  void send(int code, const char* content_type, const char* content);

server_HTML.on("/", handleRoot);
  void on(const Uri &uri, THandlerFunction fn);
  void on(const Uri &uri, HTTPMethod method, THandlerFunction fn); 
  void on(const Uri &uri, HTTPMethod method, THandlerFunction fn, THandlerFunction ufn);


server_HTML.begin();
  virtual void begin();
  virtual void begin(uint16_t port);

server_HTML.handleClient();
  virtual void handleClient();


Knihovna:
#include <DHT.h>

Definice třídy:
DHT dht(DHTPIN, DHTTYPE);

Metody:
dht.begin();
  void DHT::begin(uint8_t usec) 

dht.readHumidity();
  float DHT::readHumidity(bool force)
dht.readTemperature();
  float DHT::readTemperature(bool S, bool force)


Knihovna:
#include <ESPAsyncWebServer.h>

Definice třídy:
AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

Metody:
ws.textAll(pressed ? "1" : "0");
  AsyncWebSocket::SendStatus AsyncWebSocket::textAll(const uint8_t *message, size_t len)
  AsyncWebSocket::SendStatus AsyncWebSocket::textAll(const char *message, size_t len)
  AsyncWebSocket::SendStatus AsyncWebSocket::textAll(const char *message)
  AsyncWebSocket::SendStatus AsyncWebSocket::textAll(const String &message)

ws.onEvent(onWsEvent);
  void onEvent(AwsEventHandler handler)

server_Button_Module.addHandler(&ws);
  AsyncWebHandler &AsyncWebServer::addHandler(AsyncWebHandler *handler)

server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req))
  AsyncCallbackWebHandler &AsyncWebServer::on(
  AsyncURIMatcher uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest, ArUploadHandlerFunction onUpload, ArBodyHandlerFunction onBody
  )

server_Button_Module.begin();
  void AsyncWebServer::begin() 


Knihovna:
#include <AsyncTCP.h>
??
Definice třídy:
??
Metody:
??