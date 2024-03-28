// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and HMC5883L must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "HMC5883L.h"
#include "MPU6050.h"
#include <DynamixelSerial.h>

// class default I2C address is 0x1E
// specific I2C addresses may be passed as a parameter here
// this device only supports one I2C address (0x1E)

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high
//MPU6050 accelgyro(0x68, &Wire1); // <-- use for AD0 low, but 2nd Wire (TWI/I2C) object

#define LED_PIN 13
bool blinkState = false;

HMC5883L mag;

int16_t mx, my, mz;
int16_t ax, ay, az;
int16_t gx, gy, gz;

#define LED_PIN 13


void setup() {
       // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
    mag.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(mag.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");

    // configure Arduino LED pin for output
    pinMode(LED_PIN, OUTPUT);
    // servo 
Dynamixel.setSerial(&Serial3); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1 Mbps and Pin Control 2
delay(1000);

// accelgryo
        // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
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


    // these methods (and a few others) are also available
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
        Serial.print (AX); Serial.print("\t");
        Serial.print (AY); Serial.print("\t");
        Serial.print (AZ); Serial.print("\t");
        Serial.print (GX); Serial.print("\t");
        Serial.print (GY); Serial.print("\t");
        Serial.println (GZ); 


    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
    delay(500);
    // read raw heading measurements from device

        #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(600, true);
    #endif

    

    mag.getHeading(&mx, &my, &mz);

    // display tab-separated gyro x/y/z values
    
    Serial.print("mag:\t");
        Serial.print (AX); Serial.print("AX:\t");
        Serial.print (AY); Serial.print("AY:\t");
        Serial.print (AZ); Serial.print("AZ:\t");
        Serial.print (GX); Serial.print("GX:\t");
        Serial.print (GY); Serial.print("GY:\t");
        Serial.print (GZ);  Serial.print("GZ:\t"); 
    Serial.print(mx); Serial.print("MX\t");
    Serial.print(my); Serial.print("MY\t");
    Serial.print(mz); Serial.print("MZ\t");

    // servo
      Dynamixel.moveSpeed(5,random(200,800),random(200,800)); 
  delay(100);
   Dynamixel.moveSpeed(18,random(200,800),random(200,800)); 
  delay(100);


// To calculate heading in degrees. 0 degree indicates North
    float heading = atan2(my, mx);
    if(heading < 0)
      heading += 2 * M_PI;
    Serial.print("heading:\t");
    Serial.println(heading * 180/M_PI);


    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
