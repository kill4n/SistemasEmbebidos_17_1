#define S1  P1_0
#define S2  P1_3
#define S3  P1_4
#define S4  P1_5
#define S5  P2_0
#define S6  P2_1
#define S7  P2_2
#define S8  P2_3
#define S9  P2_4
#define S10 P2_5
#define S11 P2_6

int sen[11];
int msg[6];
byte Low;
byte High;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  sen[0]=0;
}
unsigned char readBlock()
{
  while (Serial.available() == 0)
    /* just wait */    ;
  return Serial.read(); 
}
void loop()
{
  if(Serial.available()>0)
  {
    unsigned char d1=Serial.read();
    switch(d1)
    {
    case 0xA0://isAlive
      {
        d1 = readBlock();
        if(d1 != 0xC0)
          break;
        msg[0] = 0xA0;
        msg[1] = 0xC0;
        msg[2] = 0xFF;
        msg[3] = 0xFF;
        msg[4] = ((msg[2]+msg[3])^0x88);
        msg[5] = 0xA;//EOL SALTO DE LINEA
        break;
      }
    case 0xB0://data
      {
        readSensors();  
        d1 = readBlock();
        if(d1 != 0xC0)
          break;
        msg[0] = 0xB0;
        msg[1] = 0xC0;
        msg[2] = Low;
        msg[3] = High;
        msg[4] = ((msg[2]+msg[3])^0x88);
        msg[5]= 0x0A; //EOL SALTO DE LINEA
        break;
      }
    default:
      break;
    } 
  }
}

void readSensors(){
  sen[0]  = digitalRead(S1 )&0x01;
  sen[1]  = digitalRead(S2 )&0x01;
  sen[2]  = digitalRead(S3 )&0x01;
  sen[3]  = digitalRead(S4 )&0x01;
  sen[4]  = digitalRead(S5 )&0x01;
  sen[5]  = digitalRead(S6 )&0x01;
  sen[6]  = digitalRead(S7 )&0x01;
  sen[7]  = digitalRead(S8 )&0x01;
  sen[8]  = digitalRead(S9 )&0x01;
  sen[9]  = digitalRead(S10)&0x01;
  sen[10] = digitalRead(S11)&0x01;

  Low  = (sen[0])|(sen[1]<<1)|(sen[2]<<2)|(sen[3]<<3)|(sen[4]<<4)|(sen[5]<<5)|(sen[6]<<6)|(sen[7]<<7);
  High = (sen[8])|(sen[9]<<9)|(sen[10]<<10)|(sen[11]<<11);
}









