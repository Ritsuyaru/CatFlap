#include "connectedDoor.hpp"

ConnectedDoor::ConnectedDoor() {}

ConnectedDoor::~ConnectedDoor() {}

void ConnectedDoor::init()
{
  pinMode(pinRedLed, OUTPUT);
  digitalWrite(pinRedLed, LOW);
  pinMode(pinGreenLed, OUTPUT);
  digitalWrite(pinGreenLed, LOW);

  u_char list_size = EEPROM.read(LIST_ADDR);
  for (u_char cat=0; cat<=list_size; cat++)
  {
    m_savedIdList.push_back(EEPROM.read(CAT_ADDR+cat));
  }

}

void ConnectedDoor::process()
{
  // if (m_save_mode)
  // {
  //   processSaveCat();
  // }
  // u_char id = m_reader.readId();
  // if (id != null)
  // {
  //   for (u_char savedId : m_savedIdList)
  //   {
  //     if (id == savedId)
  //     {
  //       // m_door.open();
  //       break;
  //     }
  //   }
  // }
}

void ConnectedDoor::processSaveCat()
{
  // blink Red Led / or ligth red LED
  digitalWrite(pinRedLed, HIGH);
  // Read Cat
  u_char catId = NULL;
  while (catId == NULL)
  {
    // catID = m_reader.readId();
  }
  // light green led
  digitalWrite(pinGreenLed, HIGH);
  // save cat id in a list / push back
  u_char list_size = 0;
  list_size = EEPROM.read(LIST_ADDR);
  EEPROM.write(LIST_ADDR, list_size++);

  EEPROM.write(CAT_ADDR+list_size, catId);
  // End process
  digitalWrite(pinRedLed, LOW);
}