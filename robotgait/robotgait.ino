void setup() {
  // put your setup code here, to run once:
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

 //  KAKI 4

  Dynamixel.moveSpeed(12, (710) ,200);
  delay(10);
  Dynamixel.moveSpeed(18, (400) ,200);
  delay(10);
  Dynamixel.moveSpeed(6, (350) ,200);
  delay(10);

 // kaki 5

  Dynamixel.moveSpeed(20, (720) ,200);
  delay(10);
  Dynamixel.moveSpeed(5, (400) ,200);
  delay(10);
  Dynamixel.moveSpeed(2, (512) ,200);
  delay(10);


// kaki 6
   Dynamixel.moveSpeed(13,(308) ,200);
  delay(10);
  Dynamixel.moveSpeed(8, (610) ,200);
  delay(10);
  Dynamixel.moveSpeed(11, (370) ,200);
  delay(10);

  // gait berjalan
}

void loop() {
  // put your main code here, to run repeatedly:
    // kaki 1
  Dynamixel.moveSpeed(3, (350),200);
  delay(10);
  Dynamixel.moveSpeed(1, (512),200);
  delay(10);
  Dynamixel.moveSpeed(9, (250),200); //sudut dikurangi dari sudut center
  delay(10); 


  KAKI 3
 
  Dynamixel.moveSpeed(10, (320) ,200);
  delay(10);
  Dynamixel.moveSpeed(7, (512) ,200);
  delay(10);
  Dynamixel.moveSpeed(14, (470),200);
  delay(10);

 kaki 5

  Dynamixel.moveSpeed(20, (720) ,200);
  delay(10);
  Dynamixel.moveSpeed(5, (512) ,200);
  delay(10);
  Dynamixel.moveSpeed(2, (612) ,200);
  delay(10);

  kaki 2
#SWINGPHASE
  Dynamixel.moveSpeed(4, (330) ,200);
  delay(10);
  Dynamixel.moveSpeed(16, (512) ,200);
  delay(10);
  Dynamixel.moveSpeed(15, (412) ,200); // ssudut dikurani dari posisi center
  delay(10);

  KAKI 4

  Dynamixel.moveSpeed(12, (710) ,200);
  delay(10);
  Dynamixel.moveSpeed(18, (512) ,200);
  delay(10);
  Dynamixel.moveSpeed(6, (450) ,200);
  delay(10);

// kaki 6
   Dynamixel.moveSpeed(13,(308) ,200);
  delay(10);
  Dynamixel.moveSpeed(8, (512) ,200);
  delay(10);
  Dynamixel.moveSpeed(11, (470) ,200);
  delay(10);



}
