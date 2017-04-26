#include <Wire.h>          // required by BMP085 library
static const String getR = "GET http://192.168.42.1/recibir_datos.php?mod=3&temp=10&hum_s=10&hum_a=10&pres=10&lum=10" ;

void setup()
{
  // put your setup code here, to run once:
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("Init Module 0");
  delay(1000);
}

void loop()
{
    //encender wifi
  delay(3000);  //Wait 3s to the module esp8266 start
  Serial.println("AT+CWJAP=\"embebidos\",\"raspberry\"");  //Connect to the raspberry pi network
  
  delay(5000);
  Serial.println("AT+CIFSR");
  delay(1000);
  Serial.println("AT+CIPSTART=\"TCP\",\"192.168.42.1\",80");
  delay(2000);
  Serial.print("AT+CIPSEND=");
  Serial.println((getR.length()+2));
  delay(2000);
  Serial.println(getR);
  delay(5000);
}
