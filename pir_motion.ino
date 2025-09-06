#define PIR_SENSOR_PIN D5  // PIR sensor output connected to D5 (GPIO14)
#define BUZZER_PIN D6      // Active buzzer connected to D6 (GPIO12)
#define LED_PIN D7         // LED connected to D7 (GPIO13)

#define BLYNK_TEMPLATE_ID   "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN    "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Beep pattern for a pleasant rhythm (ON duration in ms)
int melody[] = {200, 150, 250, 100, 300, 200, 350, 150, 400, 200};  
// Pause duration between beeps (OFF time)
int notePause[] = {100, 120, 130, 150, 170, 180, 150, 200, 220, 250};  

char auth[] = BLYNK_AUTH_TOKEN;  // Auth code from Blynk
const char *ssid = "YourWiFiSSID";     // Enter your Wi-Fi Name
const char *pass = "YourWiFiPassword"; // Enter your Wi-Fi Password

void playMelody() {
    for (int i = 0; i < 10; i++) {  
        digitalWrite(BUZZER_PIN, HIGH);
        delay(melody[i]);  // Play note
        digitalWrite(BUZZER_PIN, LOW);
        delay(notePause[i]);  // Pause between notes
    }
}

// Blynk function to control the LED
BLYNK_WRITE(V1) {
    int ledState = param.asInt(); // Read LED state from the Blynk app
    digitalWrite(LED_PIN, ledState);
}

void setup() {
    pinMode(PIR_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    
    Blynk.begin(auth, ssid, pass);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
}

void loop() {
    int motion = digitalRead(PIR_SENSOR_PIN);
    Blynk.run();
    
    if (motion == HIGH) { // Motion detected
        Serial.println("Motion detected! Playing pleasant melody...");
        playMelody(); // Play the short melody
        Blynk.logEvent("intruder_detected", "Someone has entered your house");
    }

    delay(2000); // Prevent rapid re-triggering
}
