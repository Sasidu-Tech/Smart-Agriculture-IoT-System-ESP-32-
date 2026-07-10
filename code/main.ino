
#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "YOUR TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

char ssid[] = "Infinix HOT 40 Pro";
char pass[] = "12345678";

#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SOIL_PIN 34
#define RED_LED 2
#define GREEN_LED 4
#define BLUE_LED 16
#define BUZZER 25
#define TRIG_PIN 27
#define ECHO_PIN 26
#define RELAY 23 // Relay Pin 23 එකේම තියන්න

long duration;
int waterLevel;
int soilValue;
float temperature;
float humidity;

int manualPumpState = 0; // V4 බටන් එකේ ස්ටේටස් එක
bool toggleScreen = true; 

BlynkTimer timer;

// BLYNK V4 BUTTON CONTROL
BLYNK_WRITE(V4)
{
  manualPumpState = param.asInt(); // බටන් එක එබුවම 1 හෝ 0 කෙලින්ම ගන්නවා
  
  // බටන් එක ඔන් කරපු ගමන්ම සෙන්සර් එක දුවනකල් ඉන්නැතුව කෙලින්ම රිලේ එක ඔන් කරනවා
  if (manualPumpState == 1) {
    digitalWrite(RELAY, HIGH); // Button ON -> Relay ON
    Serial.println("Blynk Manual: Pump ON");
  } else {
    digitalWrite(RELAY, LOW);  // Button OFF -> Relay OFF
    Serial.println("Blynk Manual: Pump OFF");
  }
}

void sendSensor()
{
  soilValue = analogRead(SOIL_PIN);
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Ultrasonic Sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  waterLevel = (duration * 0.034 / 2);

  int waterPercent = map(waterLevel, 15, 2, 0, 100);
  waterPercent = constrain(waterPercent, 0, 100);

  // Blynk Send Data
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, soilValue);
  Blynk.virtualWrite(V3, waterPercent);

  if (waterLevel >= 12) {
    tone(BUZZER, 1000, 100); 
  } else {
    noTone(BUZZER);
  }

  // --- AUTOMATIC PUMP CONTROL (දුවන්නේ V4 බටන් එක OFF නම් විතරයි) ---
  if (manualPumpState == 0) 
  {
    if (soilValue > 2400) {
      digitalWrite(RELAY, HIGH); // පස වේලිලා නම් ON
      Serial.println("Auto Mode: Pump ON (Dry)");
    } else {
      digitalWrite(RELAY, LOW);  // පස තෙතයි නම් OFF
      Serial.println("Auto Mode: Pump OFF (Wet)");
    }
  }

  // --- LCD Display ---
  lcd.clear();
  if (toggleScreen) {
    lcd.setCursor(0, 0);
    lcd.print("T:"); lcd.print(temperature); lcd.print("C H:"); lcd.print(humidity);
    lcd.setCursor(0, 1);
    lcd.print("Soil:"); lcd.print(soilValue);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Tank:"); lcd.print(waterPercent); lcd.print("%");
    lcd.setCursor(0, 1);
    
    // Active-High නිසා HIGH කියන්නේ ON විදිහට LCD එක නිවැරදි කළා
    if (digitalRead(RELAY) == HIGH) {
      lcd.print("Pump: ON");
    } else {
      lcd.print("Pump: OFF");
    }
  }
  toggleScreen = !toggleScreen; 
}

void setup()
{
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetPinAttenuation(SOIL_PIN, ADC_11db);

  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW); // මුලින්ම පම්ප් එක OFF (Active-High නිසා LOW)

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, sendSensor); 

  lcd.setCursor(0, 0);
  lcd.print("Smart Agriculture");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000); 
  lcd.clear();
}

void loop()
{
  Blynk.run();
  timer.run();
}
