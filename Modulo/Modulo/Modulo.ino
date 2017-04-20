#include <DHT.h>
#include <Wire.h>          // required by BMP085 library
#include <BMP085_t.h>      // import BMP085 template library

/*
Both readFloatData and readRawData takes 2 pointers as arguments.
 That means you need to have these variables locally already and then prefix them with a &.
 The result of the function will be put into those variables if successful, and you can use the return value of the function to test for errors.
 */
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


const int sensorLUZ = A3;
const int sensorFC = A0;
const int pinWifi = 11;
BMP085<3> PSensor;         // instantiate sensor, 0 = low precision pressure reading
//static const String getR = "GET http://186.155.238.250/recibir_datos.php?mod=2" ;
//static const String getR = "GET http://186.155.238.250:8149/recibir_datos.php?mod=2" ;
static const String getR = "GET http://192.168.42.1:80/recibir_datos.php?mod=2" ;


void setup()
{
  Serial.begin(9600);
  dht.begin();
  Serial.println("Init Module 0");
  pinMode(P2_5,OUTPUT);
  Wire.begin();            // initialize I2C that connects to sensor
  PSensor.begin();         // initalize pressure sensor  
  digitalWrite(pinWifi, LOW);
}

void loop()
{     
  ConnectWifi();
  delay(1000);
  int temp = dht.readTemperature();
  delay(1000);
  int humA = dht.readHumidity();
  delay(1000);
  int lumi = luzsensor();
  delay(1000);
  int humS = humsensor();
  delay(1000);
  int pres = bmpsensor();
  delay(1000);
  //sendData((int)(t), (int)PorHumedad, (int)(h), (int)press, (int)Luz);
  
  String Ptemp = String(temp); 
  String Phums = String(humS);
  String Phuma = String(humA);
  String Ppres = String(pres);
  String Plumi = String(lumi);

  int size = getR.length() + 6 + Ptemp.length() + 
    7 + Phums.length() + 7 + Phuma.length() + 6 + Ppres.length() + 5 + Plumi.length() + 2;
 
  Serial.print("AT+CIPSEND=");  
  Serial.println(size);
  delay(500);
  Serial.print(getR);
  Serial.print("&temp=");
  Serial.print(Ptemp);
  Serial.print("&hum_s=");
  Serial.print(Phums);
  Serial.print("&hum_a=");
  Serial.print(Phuma); 
  Serial.print("&pres=");
  Serial.print(Ppres); 
  Serial.print("&lum=");
  Serial.println(Plumi);
  
  //delay(5000);    
  delay(5000);    
  WDTCTL = 0x00;

}

void ConnectWifi()
{
  //encender wifi
  delay(3000);  //Wait 3s to the module esp8266 start
  //Serial.println("AT+CWJAP=\"raspberry\",\"123456789\"");  //Connect to the raspberry pi network
  Serial.println("AT+CWJAP=\"embebidos\",\"raspberry\"");  //Connect to the raspberry pi network
  //delay(5000);
//  Serial.println("AT+CIFSR");
  delay(5000);
  //Serial.println("AT+CIPSTART=\"TCP\",\"186.155.238.250\",8149");
  Serial.println("AT+CIPSTART=\"TCP\",\"192.168.42.1\",80");

}

void sendData(int temp, int humS, int humA, int pres, int lumi)
{

}

int luzsensor()
{
  int Luz = analogRead(sensorLUZ);
  int PorLuz = (100-(Luz/10.2));
  return int(PorLuz);
}

int humsensor()
{
  int humedad = analogRead(sensorFC);
  int PorHumedad = humedad;
  return int(PorHumedad);
}

int bmpsensor()
{
  PSensor.refresh();                    // read current sensor data
  PSensor.calculate();
  return int((PSensor.pressure+50)/100);
}

void WifiEn()
{
  digitalWrite(pinWifi, HIGH);  
  delay(5000);
  digitalWrite(pinWifi, LOW);
}

