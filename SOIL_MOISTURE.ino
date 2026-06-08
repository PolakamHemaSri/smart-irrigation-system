#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pin=A0;
int relay_pin = 7;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(HIGH);        
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  int sensor_data= analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  if(sensor_data>950)
  {
    Serial.println("No moisture,Soil is Dry");
    digitalWrite(relay_pin, HIGH);
     lcd.setCursor(0,0);
     lcd.print("Soil Dry ");
     lcd.setCursor(0,1);
     lcd.print("Motor ON ");

  }
  else if(sensor_data>= 400 && sensor_data<= 700)
  {
    Serial.println("There is some moisture");
    digitalWrite(relay_pin, LOW);
    lcd.setCursor(0,0);
    lcd.print("Moisture-Medium ");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");

  }
  else if( sensor_data< 500)
  {
    Serial.println("Soil is Wet");
    digitalWrite(relay_pin, LOW);
    lcd.setCursor(0,0);
    lcd.print(" Soil WET");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
  }
  delay(2000);
}
