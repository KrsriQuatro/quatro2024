#include <DynamixelSerial.h>
#include <HardwareSerial.h>

// leg 1 kaki kiri depan
#define kakiKiriDepan_0 15
#define kakiKiriDepan_1 16
#define kakiKiriDepan_2 4
// leg 2 kaki kiri tengah
#define kakiKiriTengah_0 2
#define kakiKiriTengah_1 5
#define kakiKiriTengah_2 20
// leg 3 kaki kiri belakang
#define kakiKiriBelakang_0 11
#define kakiKiriBelakang_1 8
#define kakiKiriBelakang_2 13
// leg 4 kaki kanan belakang
#define kakiKananBelakang_0 14
#define kakiKananBelakang_1 7
#define kakiKananBelakang_2 10
// leg 5 kaki kanan tengah
#define kakiKananTengah_0 6
#define kakiKananTengah_1 14
#define kakiKananTengah_2 12
// leg 6 kaki kanan depan
#define kakiKananDepan_0 9
#define kakiKananDepan_1 1
#define kakiKananDepan_2 3

#define femur 60
#define tibia 63.70
#define coxa 73.90

float x = 90;
float y =90;
float z =90;
float Length;
int sudutServo;

void setup() {
  // put your setup code here, to run once:
Dynamixel.setSerial(&Serial3); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1 Mbps and Pin Control 2
Serial.begin(9600);
Serial.println(x);
Serial.println(y);
Serial.println(z);
}

void loop() {
  // Serial.println("masukkan berapa nilai dari sudut x,y dan z di bawah: ");

  //   while (Serial.available() == 0) {
  // }

  // int sudutServo = Serial.parseInt();

  // switch (sudutServo) {
  //   case 1:
  //     // temp sensor code goes here
  //     Serial.print("tentukan posisi dari sudut x: ");
  //     Serial.println(x);
  //     break;

  //   case 2:
  //     // humidity sensor code goes here
  //     Serial.print("tentukan posisi dari sudut y: ");
  //     Serial.println(y);
  //     break;

  //   case 3:
  //     // pressure sensor code goes here
  //     Serial.print("Tentukan posisi dari sudut z: ");
  //     Serial.println(z);
  //     break;

  //   default:
  //     Serial.println("Please choose a valid selection");
  // }
float Length = sqrt(y * y + z * z); 
float j3 = acos(femur * femur + tibia * tibia - Length * Length / 2 * femur * tibia);
float sudutB = acos(Length * Length + femur * femur - tibia * tibia  / 2 * Length * femur);
float sudutA = atan(z / y);
float j2 = (sudutB - sudutA);

Serial.print(Length); Serial.print(" \t");
delay(1000);
Serial.print(j3); Serial.print(" \t");
delay(1000);
Serial.print(sudutB); Serial.print(" \t");
delay(1000);
Serial.print(sudutA); Serial.print(" \t");
delay(1000);
Serial.println(j2); Serial.print(" \t");
delay(1000);

// // kaki 1
// dynamixel.move = (kakiKiriDepan_0, () ); //oxsa
// dynamixel.move = (kakiKiriDepan_1, (j3)); //tibia
// dynamixel.move = (kakiKiriDepan_2, (j2)); //femur

// // kaki 2
// dynamixel.move = (kakiKiriTengah_0, () ); //oxsa
// dynamixel.move = (kakiKiriTengah_1, (j3)); //tibia
// dynamixel.move = (kakiKiriTengah_2, (j2)); //femur

// // kaki 3
// dynamixel.move = (kakiKiriBelakang_0, () );//oxsa
// dynamixel.move = (kakiKiriBelakang_1, (j3)); //tibia
// dynamixel.move = (kakiKiriBelakang_2, (j2)); //femur

// // kaki 4
// dynamixel.move = (kakiKananDepan_0, () );//oxsa
// dynamixel.move = (kakiKananDepan_1, (j3)); //tibia
// dynamixel.move = (kakiKananDepan_2, (j2)); //femur

// // kaki 5
// dynamixel.move = (kakiKananTengah_0, () );//oxsa
// dynamixel.move = (kakiKananTengah_1, (j3)); //tibia
// dynamixel.move = (kakiKananTengah_2, (j2)); //femur

// // kaki 6
// dynamixel.move = (kakiKananBelakang_0, () );//oxsa
// dynamixel.move = (kakiKananBelakang_1, (j3)); //tibia
// dynamixel.move = (kakiKananBelakang_2, (j2)); //femur

}

