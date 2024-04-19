#include <DynamixelSerial.h>

//#include <dynamixel.h>
//#include <wire.h>
//#include <mpu6050.h>

int bit1, bit2, bit3;
float sudut1, sudut2, sudut3;

const float fm=60.00; //femur
const float tb=63.70; // tibia
const float cx=73.90; //coxa

float Length, L1;
// float alpha, alpha1,alpha2,beta,gama;
void setup()
{
  Dynamixel.setSerial(&Serial); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
  Dynamixel.begin(1000000,2);  // Inicialize the servo at 1 Mbps and Pin Control 2
  delay(1000);
  Serial.begin(38400); 
}
void loop()
{
  trigono_xyz(1, 5, 0, &sudut1, &sudut2, &sudut3); //contoh x,y,z
  bit1 = SudutkeBit(sudut1);
  bit2 = SudutkeBit(sudut2);
  bit3 = SudutkeBit(sudut3);

  //  kaki 1
  Dynamixel.move(6, bit3); //gamma
  Dynamixel.move(18, bit1); //femur
  Dynamixel.move(12, bit2);//coxa

  Serial.print("gama= ");
  Serial.print(sudut1);
  Serial.print(", alpha= ");
  Serial.print(sudut2);
  Serial.print(", beta= ");
  Serial.print(sudut3);
  Serial.println();

    Serial.print("bit 1= ");
  Serial.print(bit1);
  Serial.print(", bit 2= ");
  Serial.print(bit2);
  Serial.print(", bit 3= ");
  Serial.print(bit3);
  Serial.println();
}

void trigono_xyz(float x, float y, float z, float *alpha, float *beta, float *gama)
{
  float L1=sqrt(sq(x)+sq(y));
  *gama=atan(x/y)/PI*180;
  float L=sqrt(sq(L1-cx)+sq(z));
  *beta=acos((sq(tb)+sq(fm)-sq(L))/(2*tb*fm))/PI*180;
  float alpha1=acos(z/L)/PI*180;
  float alpha2=acos((sq(fm)+sq(L)-sq(tb))/(2*fm*L))/PI*180;
  *alpha=alpha1+alpha2;
}

int SudutkeBit(float sudut){
  int bit = sudut/300 * 1023;
  return bit;
}


