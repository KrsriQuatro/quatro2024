#include <DynamixelSerial.h>

void setup() {
  // put your setup code here, to run once:
  Dynamixel.setSerial(&Serial3);
  Dynamixel.begin(1000000,46);
  delay(1000);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
// ######################################################    putar kanan   #####################################################################################

//   // kaki 1
//   Dynamixel.moveSpeed(3, (310),100);
//   delay(100);
//   Dynamixel.moveSpeed(1, (601),100);
//   delay(100);
//   Dynamixel.moveSpeed(9, (350),100);
//   delay(100);

//   // kaki 1
//   Dynamixel.moveSpeed(3, (310),100);
//   delay(100);
//   Dynamixel.moveSpeed(1, (601),100);
//   delay(100);
//   Dynamixel.moveSpeed(9, (450),100);
//   delay(100);

//     // kaki 2

//    Dynamixel.moveSpeed(4, (330) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(16, (601) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(15, (512) ,100);
//   delay(100);

//   // kaki 2
//    Dynamixel.moveSpeed(4, (330) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(16, (601) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(15, (612) ,100);
//   delay(100);


//  //  KAKI 3
 
//   Dynamixel.moveSpeed(10, (320) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(7, (601) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(14, (670),100); //570
//   delay(100);

//   // KAKI 3
 
//   Dynamixel.moveSpeed(10, (320) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(7, (601) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(14, (770),100); //570
//   delay(100); 


//  //  KAKI 4

//   Dynamixel.moveSpeed(12, (710) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(18, (400) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(6, (350) ,100);
//   delay(100);

//   //  KAKI 4
//   Dynamixel.moveSpeed(12, (710) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(18, (400) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(6, (450) ,100);
//   delay(100);

//  // kaki 5

//   Dynamixel.moveSpeed(20, (720) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(5, (400) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(2, (512) ,100);
//   delay(100);

//   // //  kaki 5
//   Dynamixel.moveSpeed(20, (720) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(5, (400) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(2, (612) ,100);
//   delay(100);

// // kaki 6
  //  Dynamixel.moveSpeed(13,(308) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(8, (610) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(11, (370) ,100);
  // delay(100);

// // // kaki 6
//    Dynamixel.moveSpeed(13,(308) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(8, (610) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(11, (470) ,100);
//   delay(100);






// #####################################    putar kiri ###########################################################
// kaki 4
  Dynamixel.moveSpeed(12, (710) ,100);
  delay(100);
  Dynamixel.moveSpeed(18, (400) ,100);
  delay(100);
  Dynamixel.moveSpeed(6, (350) ,100);
  delay(100);

 //  KAKI 4

  Dynamixel.moveSpeed(12, (710) ,100);
  delay(100);
  Dynamixel.moveSpeed(18, (400) ,100);
  delay(100);
  Dynamixel.moveSpeed(6, (250) ,100);
  delay(100);

  // //  kaki 5
  Dynamixel.moveSpeed(20, (720) ,100);
  delay(100);
  Dynamixel.moveSpeed(5, (400) ,100);
  delay(100);
  Dynamixel.moveSpeed(2, (512) ,100);
  delay(100)
  ;
 // kaki 5
  Dynamixel.moveSpeed(20, (720) ,100);
  delay(100);
  Dynamixel.moveSpeed(5, (400) ,100);
  delay(100);
  Dynamixel.moveSpeed(2, (412) ,100);
  delay(100);


   Dynamixel.moveSpeed(13,(308) ,100);
  delay(100);
  Dynamixel.moveSpeed(8, (610) ,100);
  delay(100);
  Dynamixel.moveSpeed(11, (370) ,100);
  delay(100);
// kaki 6
   Dynamixel.moveSpeed(13,(308) ,100);
  delay(100);
  Dynamixel.moveSpeed(8, (610) ,100);
  delay(100);
  Dynamixel.moveSpeed(11, (270) ,100);
  delay(100);

  // kaki 1
  Dynamixel.moveSpeed(3, (310),100);
  delay(100);
  Dynamixel.moveSpeed(1, (601),100);
  delay(100);
  Dynamixel.moveSpeed(9, (350),100);
  delay(100);

  // kaki 1
  Dynamixel.moveSpeed(3, (310),100);
  delay(100);
  Dynamixel.moveSpeed(1, (601),100);
  delay(100);
  Dynamixel.moveSpeed(9, (250),100);
  delay(100);

  //     // kaki 2

   Dynamixel.moveSpeed(4, (330) ,100);
  delay(100);
  Dynamixel.moveSpeed(16, (601) ,100);
  delay(100);
  Dynamixel.moveSpeed(15, (512) ,100);
  delay(100);

  // kaki 2
   Dynamixel.moveSpeed(4, (330) ,100);
  delay(100);
  Dynamixel.moveSpeed(16, (601) ,100);
  delay(100);
  Dynamixel.moveSpeed(15, (412) ,100);
  delay(100);

   //  KAKI 3
 
  Dynamixel.moveSpeed(10, (320) ,100);
  delay(100);
  Dynamixel.moveSpeed(7, (601) ,100);
  delay(100);
  Dynamixel.moveSpeed(14, (670),100); //570
  delay(100);

  // KAKI 3
 
  Dynamixel.moveSpeed(10, (320) ,100);
  delay(100);
  Dynamixel.moveSpeed(7, (601) ,100);
  delay(100);
  Dynamixel.moveSpeed(14, (570),100); //570
  delay(100); 
}
