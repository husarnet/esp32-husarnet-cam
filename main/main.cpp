#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "husarnet.h"
#include "esp32cam.h"
#include "esp32cam-asyncweb.h"

#include "webpage.h"

#define HOSTNAME  "husarnet-esp32-cam"
#define JOIN_CODE "XXXXXXXXXXXXXXXXXX"

#define WIFI_SSID "your_ssid"
#define WIFI_PASS "your_password"

using namespace esp32cam;

AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);

    // Connect to the WiFi network
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi!");

    // Connect and join the Husarnet network
    HusarnetClient* client = new HusarnetClient();
    client->join(HOSTNAME, JOIN_CODE);

    while (!client->isJoined()) {
        delay(1000);
        Serial.println("Connecting to Husarnet...");
    }

    Serial.println("Connected to Husarnet!");

    // Configure the camera
    Config cfg;
    // Select your camera module here
    cfg.setPins(pins::M5CameraLED);

    cfg.setResolution(Resolution::find(320, 240));
    cfg.setJpeg(80);

    if (!Camera.begin(cfg)) {
        Serial.println("Camera initialization failed! Is the pinout in setPins correct? Rebooting...");
        delay(5000);
        ESP.restart();
    }
    Serial.println("Camera initialized!");

    Serial.print("Husarnet IP address: ");
    Serial.println(client->getIpAddress().c_str());

    // Configure the HTTP server
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html);
    });

    server.on("/cam.jpg", esp32cam::asyncweb::handleStill);
    server.on("/cam.mjpeg", esp32cam::asyncweb::handleMjpeg);
    
    // Start async webserver
    server.begin();
}
void loop() {
    // Main loop is empty, all the work is done in the background tasks
    delay(1000);
}
