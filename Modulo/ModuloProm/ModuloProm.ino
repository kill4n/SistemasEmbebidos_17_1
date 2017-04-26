//Librerias a Cargar
#include <DHT.h>
#include <Wire.h>          // required by BMP085 library
#include <BMP085_t.h>      // import BMP085 template library

//Declaracion del sensor DHT11
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Pines declarados a usar
const int sensorLUZ = A3;
const int sensorFC = A0;
const int pinWifi = 11;
BMP085<3> PSensor;        // instantiate sensor, 0 = low precision pressure reading, 
                          //3 = highprecision pressure reading 
//Se debe de nodificar el valor posterior a mod para dar el id del modulo.
static const String getR = "GET http://192.168.42.1/recibir_datos.php?mod=2" ;

void setup()
{
  Serial.begin(9600);
  Serial.println("Init Module 0");
  pinMode(pinWifi,OUTPUT);
  digitalWrite(pinWifi, HIGH); 
  delay(1000);
  Wire.begin();            // Inicializacion I2C
  delay(1000);
  PSensor.begin();         // Inicializacion Sensor presion
  delay(1000);
  dht.begin();
  delay(1000);
}

void loop()
{ 
  int n = 0;
  int temp = 0;
  int humA = 0;
  int lumi = 0;
  int humS = 0;
  int pres = 0;
  
  while(n < 90)
  {
    n += 1;
    delay(1000);
    temp += dht.readTemperature();
    delay(1000);
    humA += dht.readHumidity();
    delay(1000);
    lumi = luzsensor();
    delay(1000);
    humS += humsensor();
    delay(1000);
    pres += bmpsensor();
    delay(5000);
  }
  temp = temp/n;
  humA = humA/n;
  lumi = lumi/n;
  humS = humS/n;
  pres = pres/n;
  
  n = 0;
  delay(2000);
  ConnectWifi();

  String Ptemp = String(temp); 
  String Phums = String(humS);
  String Phuma = String(humA);
  String Ppres = String(pres);
  String Plumi = String(lumi);

  int size = getR.length() + 6 + Ptemp.length() + 
    7 + Phums.length() + 7 + Phuma.length() + 6 + Ppres.length() + 5 + Plumi.length() + 2;

  Serial.print("AT+CIPSEND=");  
  Serial.println(size);
  delay(1000);
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
  delay(3000);

  digitalWrite(pinWifi, LOW);  
  delay(5000);    

}

void ConnectWifi()
{
  //Encender wifi
  delay(3000);  //Wait 3s to the module esp8266 start
  Serial.println("AT+CWJAP=\"embebidos\",\"raspberry\"");  //Connect to the raspberry pi network
  delay(10000);
  Serial.println("AT+CIFSR");
  delay(5000);
  Serial.println("AT+CIPSTART=\"TCP\",\"192.168.42.1\",80");
  delay(5000);
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
  int PorHumedad = (100-(humedad/10.2));
  return int(PorHumedad);
}

int bmpsensor()
{
  PSensor.refresh();                    // read current sensor data
  PSensor.calculate();
  return int((PSensor.pressure+50)/100);
}

