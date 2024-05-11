#include <DynamixelSerial.h>

 
void setup() {

  Dynamixel.setSerial(&Serial3);
  Dynamixel.begin(1000000,46);
  delay(1000);
   Serial.begin(9600);
}


void loop() {
  
//   // kaki 1
//   Dynamixel.moveSpeed(3, (350),200);
//   delay(10);
//   Dynamixel.moveSpeed(1, (601),200);
//   delay(10);
//   Dynamixel.moveSpeed(9, (350),200);
//   delay(10);

//   // kaki 2

//    Dynamixel.moveSpeed(4, (330) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(16, (601) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(15, (512) ,200);
//   delay(10);

//  //  KAKI 3
 
//   Dynamixel.moveSpeed(10, (320) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(7, (601) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(14, (670),200); //570
//   delay(10);

//  //  KAKI 4

//   Dynamixel.moveSpeed(12, (710) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(18, (400) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(6, (350) ,200);
//   delay(10);

//  // kaki 5

//   Dynamixel.moveSpeed(20, (720) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(5, (400) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(2, (512) ,200);
//   delay(10);


// // kaki 6
//    Dynamixel.moveSpeed(13,(308) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(8, (610) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(11, (370) ,200);
//   delay(10);
// }


// #tancePhase
  //   // kaki 1
  // Dynamixel.moveSpeed(3, (350),100);
  // delay(100);
  // Dynamixel.moveSpeed(1, (512),100);
  // delay(100);
  // Dynamixel.moveSpeed(9, (250),100); //sudut dikurangi dari sudut center
  // delay(100); 

  //   //Gait kaki 1
  // Dynamixel.moveSpeed(3, (350),100);
  // delay(100);
  // Dynamixel.moveSpeed(1, (601),100);
  // delay(100);
  // Dynamixel.moveSpeed(9, (350),100);
  // delay(100);

//  KAKI 3
  // Dynamixel.moveSpeed(10, (320) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(7, (601) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(14, (670),100); //570
  // delay(100);

    // KAKI 3
 
  // Dynamixel.moveSpeed(10, (320) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(7, (512) ,100);
  // delay(100);
  // Dynamixel.moveSpeed(14, (570),100);
  // delay(100);

   // kaki 5

//   Dynamixel.moveSpeed(20, (720) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(5, (400) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(2, (512) ,100);
//   delay(100);

// //  kaki 5
//   Dynamixel.moveSpeed(20, (720) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(5, (512) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(2, (612) ,100);
//   delay(100);

// #SWINGPHASE

// //kaki 2
//   Dynamixel.moveSpeed(4, (330) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(16, (512) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(15, (412) ,100); // ssudut dikurani dari posisi center
//   delay(100);

//   // kaki 2
//    Dynamixel.moveSpeed(4, (330) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(16, (601) ,100);
//   delay(100);
//   Dynamixel.moveSpeed(15, (512) ,100);
//   delay(100);

 //  KAKI 4

  // Dynamixel.moveSpeed(12, (710) ,150);
  // delay(100);
  // Dynamixel.moveSpeed(18, (400) ,150);
  // delay(100);
  // Dynamixel.moveSpeed(6, (350) ,150);
  // delay(100);

  // // KAKI 4
  // Dynamixel.moveSpeed(12, (710) ,150);
  // delay(100);
  // Dynamixel.moveSpeed(18, (512) ,150);
  // delay(100);
  // Dynamixel.moveSpeed(6, (450) ,150);
  // delay(100);

// // kaki 6
//    Dynamixel.moveSpeed(13,(308) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(8, (512) ,200);
//   delay(10);
//   Dynamixel.moveSpeed(11, (470) ,200);
//   delay(10);
}
  // for (swingPhase = 0, swingPhase <= stancePhase, swingPhase++) {
  // if (swingPhase = stancePhase) {
  //   return stancePhase;
  // }
  // else if (swingphase <= stancePhase)
  //   return swingPhase;

void putar_Kanan () {
      // kaki 1
  Dynamixel.moveSpeed(3, (350),200);
  delay(10);
  Dynamixel.moveSpeed(1, (601),200);
  delay(10);
  Dynamixel.moveSpeed(9, (350),200);
  delay(10);

  // kaki 2

   Dynamixel.moveSpeed(4, (330) ,200);
  delay(10);
  Dynamixel.moveSpeed(16, (601) ,200);
  delay(10);
  Dynamixel.moveSpeed(15, (512) ,200);
  delay(10);

 //  KAKI 3
 
  Dynamixel.moveSpeed(10, (320) ,200);
  delay(10);
  Dynamixel.moveSpeed(7, (601) ,200);
  delay(10);
  Dynamixel.moveSpeed(14, (670),200); //570
  delay(10);
  }

