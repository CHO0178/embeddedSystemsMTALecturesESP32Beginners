#include <WebServer.h>

WebServer server_HTML(80);
  WebServer(IPAddress addr, int port = 80);
  WebServer(int port = 80);

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

