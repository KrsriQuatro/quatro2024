// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
#include "DynamixelSerial.h"S
#include "Wire.h"
#include "MPU6050.h"
#include "MadgwickAHRS.h"
#include "HMC5883L.h"

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

long timeNow, timeLast = 0, periode = 500;

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
 int potpin = A0;  // analog pin used to connect the potentiometer
 float val;    // variable to read the value from the analog pin
int degPos;// degree symbol position
#define LED_PIN 13
bool blinkState = false;

HMC5883L mag;
int16_t mx, my, mz;
#define LED_PIN 13
bool blinkState = false;

// madgwick filter
Madgwick filter;
unsigned long microsPerReading, microsPrevious;
float accelScale, gyroScale;

void setup() {
  Wire.begin();
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
     Dynamixel.setSerial(&Serial3); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
     Dynamixel.begin(1000000,2);  // Inicialize the servo at 1 Mbps and Pin Control 2
     delay(1000);
     Serial.begin(38400);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    filter.begin(25);

  // initialize variables to pace updates to correct rate
  microsPerReading = 1000000 / 25;
  microsPrevious = micros();

    // use the code below to change accel/gyro offset values
    /*
    Serial.println("Updating internal sensor offsets...");
    // -76	-2359	1688	0	0	0
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    accelgyro.setXGyroOffset(220);
    accelgyro.setYGyroOffset(76);
    accelgyro.setZGyroOffset(-85);
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    */
    // magnetometer kompas
    // configure Arduino LED pin for output
       Serial.println("Initializing I2C devices...");
    mag.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(mag.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");

    // configure Arduino LED pin for output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    float AX =((float)ax/16384.0);
    float AY =((float)ay/16384.0);
    float AZ =((float)az/16384.0);
    float GX = ((float)gx/131.0);
    float GY = ((float)gy/131.0);
    float GZ = ((float)gz/131.0); 

    //accelgyro.getAcceleration(&ax, &ay, &az);
    //accelgyro.getRotation(&gx, &gy, &gz);
        // display tab-separated accel/gyro x/y/z values
        // Serial.print("a/g:\t");
        // Serial.print(ax); Serial.print("\t");
        // Serial.print(ay); Serial.print("\t");
        // Serial.print(az); Serial.print("\t");
        // Serial.print(gx); Serial.print("\t");
        // Serial.print(gy); Serial.print("\t");
        // Serial.println(gz);
        
    // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
  timeNow = millis();
   if(timeNow - timeLast > periode){
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    // Serial.print (AX); Serial.print("AX\t");
    // Serial.print (AY); Serial.print("AY\t");
    // Serial.print (AZ); Serial.print("AZ\t");
    // Serial.print (GX); Serial.print("GX\t");
    // Serial.print (GY); Serial.print("GY\t");
    // Serial.println (GZ); Serial.print("GZ");
    // Serial.print(val);
    // Serial.println();
    timeLast = timeNow;
   }

int aix, aiy, aiz;
  int gix, giy, giz;
  float ax, ay, az;
  float gx, gy, gz;
  float roll, pitch, heading;
  unsigned long microsNow;

  // check if it's time to read data and update the filter
  microsNow = micros();
  if (microsNow - microsPrevious >= microsPerReading) {

    // read raw data from CurieIMU
    // CurieIMU.readMotionSensor(aix, aiy, aiz, gix, giy, giz);

    // convert from raw data to gravity and degrees/second units

    // update the filter, which computes orientation
    filter.updateIMU(AX, AY, AZ, GX, GY, GZ);

    // print the heading, pitch and roll
    roll = filter.getRoll();
    pitch = filter.getPitch();
    heading = filter.getYaw();
    Serial.print("Orientation: ");
    Serial.print(heading);
    Serial.print(" ");
    Serial.print(pitch);
    Serial.print(" ");
    Serial.println(roll);

    // increment previous time, so we keep proper pace
    microsPrevious = microsPrevious + microsPerReading;
  }
// magnetometer kompas
  mag.getHeading(&mx, &my, &mz);

    // display tab-separated gyro x/y/z values
    
    Serial.print("mag:\t");
    Serial.print(mx); Serial.print("\t");
    Serial.print(my); Serial.print("\t");
    Serial.print(mz); Serial.print("\t"); 
    
// To calculate heading in degrees. 0 degree indicates North
    float heading = atan2(my, mx);
    if(heading < 0)
      heading += 2 * M_PI;
    Serial.print("heading:\t");
    Serial.println(heading * 180/M_PI);


    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

Dynamixel.moveSpeed(5,val,512); 
Dynamixel.moveSpeed(17,val,512); 
}
