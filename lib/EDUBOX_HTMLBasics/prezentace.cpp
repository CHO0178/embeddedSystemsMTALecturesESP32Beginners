#include <WebServer.h>
#include "HTML_Basics.hpp"

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer webServer(80);


void handlerRoot() {
    String page = FPSTR(HTML_PAGE);
    webServer.send(200, "text/html; charset=utf-8", page);
}

void setupHTMLBasics() {
    webServer.on("/", handleRoot);
    webServer.begin();
    Serial.println("HTTP server spuštěn");
}

void loopHTMLBasics() {
    webServer.handleClient();
}

