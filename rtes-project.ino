//Project name: Egg incubation project
//DISCLAIMER: Code will be explained in the form of comments when needed.
#include "DHT.h" //using DHT.h library in " " as brackets do not work, gives error

#define DHTPIN 2     // Digital pin connected to the DHT sensor this will be used to provide arduino input

#define DHTTYPE DHT11   // Using 3 pin DHT11
int relaypin = 10; //relay pin for bulb
int relaypin2 = 11; //relay pin bulb for ac fan

DHT dht(DHTPIN, DHTTYPE); //defining pin and type

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!")); //this is where DHT11 will start initializing
  pinMode(relaypin,OUTPUT);
  pinMode(relaypin2,OUTPUT);

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  float h = dht.readHumidity(); //humidity
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature(); //temperature in celcius
  if (t>32.90)
  {
    digitalWrite(relaypin, LOW);
    digitalWrite(relaypin2, HIGH);
  }
  else
  {
    digitalWrite(relaypin,HIGH);
    digitalWrite(relaypin2, LOW);
  }
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true); //temperature in farenheit

  // Checks values if they are proper values if not then it will send an error message
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit
  //Heat index is a combination of air temperature and relative humdidty or in short what the temperature seems to the user
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

//Now printing the data as calculated
//Where F() is basically a method to pass flsh memory based strings meaning your string which you are printing does not utilize any RAM
  Serial.print(F(" Humidity: "));
  Serial.print(h); //printing humidity
  Serial.print(F("%  Temperature: "));
  Serial.print(t); //printing temperature in celcius
  Serial.print(F("C "));
  Serial.print(f); //printing temperature in farenheit
  Serial.print(F("F  Heat index: "));
  Serial.print(hic); //printing heat index in Celcius
  Serial.print(F("C "));
  Serial.print(hif); //printing heat index in Farenheit
  Serial.println(F("F"));
}
