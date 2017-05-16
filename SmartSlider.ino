
#include <CurieBLE.h>
#include <Servo.h> 

int servoPin = 9;
Servo runServo; 

BLEPeripheral blePer; 
BLEService motorTrigger("19B10000-E8F2-537E-4F6C-D104768A1214");

BLECharCharacteristic motorCom("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite); 

void setup() 
{
  runServo.attach(servoPin); 
   
  blePer.setLocalName("SmartSlider");
  blePer.setAdvertisedServiceUuid(motorTrigger.uuid()); 

  blePer.addAttribute(motorTrigger);
  blePer.addAttribute(motorCom);  

  motorCom.setValue(0); 

  blePer.begin(); 
}

void loop() 
{
  BLECentral central = blePer.central(); 
  
  while(central.connected())
  {
    if(motorCom.written())
    {
      if(motorCom.value() == 1)
      {
        runMotor(&runServo, true);  
      } 
      if(motorCom.value() == 2)
      {
       runMotor(&runServo, false);
      } 
    }
  }
  


}

void runMotor(Servo *runServo, boolean down)
{ 
  if(down)
  {
    runServo -> write(10); 
  }
  else
  {
    runServo -> write(170);
  }
}

