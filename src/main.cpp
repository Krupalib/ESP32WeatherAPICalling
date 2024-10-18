#include <Arduino.h>
#include<WiFi.h>
#include<HTTPClient.h>


const char* ssid = "VIRGIN269";
const char* password = "562C9362E2F6";
const char* apiKey = "a31acecaccf9228f7e25b7a7db3a429b";
const char* city = "Montreal"; // e.g., "London"
const char* apiEndpoint = "http://api.openweathermap.org/data/2.5/weather?q=";




void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}


void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = String(apiEndpoint) + city + "&appid=" + apiKey + "&units=metric"; // Metric for Celsius
        http.begin(url);

        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(response); // Print the response
        } else {
            Serial.print("Error on HTTP request: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }

    delay(60000); // Update every minute
}


// put function definitions here:
