/* Entire Code and Electronic Setup written and developed by - 
Aditya Swaroop 
Project 2 - Smart temperature and Humidity Monitoring System
ROBO-AI Program - Electrical and Electronics Project-2 */

#include "DHT.h" // include dht library
#include <LiquidCrystal.h> // include liquid Crystal library

#define DHTPIN 2     // defines (2) digitial pin to which dht is connected
#define DHTTYPE DHT22   // defines dht22 sensor 

DHT dht(DHTPIN, DHTTYPE); // creates a dht object with defined pins 
LiquidCrystal lcd(12,11,10,9,8,7); // creates lcd object with defined pins

void setup() 
{
  lcd.begin(16,2); // initialises the lcd display to 16*2 
  dht.begin(); // initialises the dht sensor 
}

void loop() 
{
  float temp = dht.readTemperature(); // calculates the room temperature
  float hum = dht.readHumidity(); // calculates the room humidity

  // Check if any reads failed and exit early (to try again).
  if (isnan(temp) || isnan(hum)) 
  {
    lcd.print("Failed to read from DHT sensor!");
    return; // return the compiler to the end of the class loop()
  }
lcd.setCursor(0,0); // sets the pointer to row 0 and column 0
lcd.print("Humidity:" ); 
lcd.print(hum); // prints the humidity
lcd.setCursor(0,1); // sets the pointer to row 1 and column 0
lcd.print("Temperature:");
lcd.print(temp); // prints the temperature

delay(100); // delays the setup by 100 milli-seconds
}