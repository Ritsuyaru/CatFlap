//#include <Types.h>

// #include "Servo.h" //need to include and instanciate here because arduino
#include "connectedDoor.hpp"
#include "params.h"
// #include <Types.h>

ConnectedDoor m_connectedDoor;
// Servo servo_door;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // servo_door.attach(pinServoDoor);
  m_connectedDoor.init();
}

void loop() {
  // put your main code here, to run repeatedly:

  m_connectedDoor.process();
  

}