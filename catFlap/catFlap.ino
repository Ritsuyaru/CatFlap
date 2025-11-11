//#include <Types.h>

#include "connectedDoor.hpp"
// #include <Types.h>

ConnectedDoor m_connectedDoor = ConnectedDoor();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m_connectedDoor.init();
}

void loop() {
  // put your main code here, to run repeatedly:

  m_connectedDoor.process();

}