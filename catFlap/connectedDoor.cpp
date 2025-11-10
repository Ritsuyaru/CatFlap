#include "connectedDoor.hpp"

ConnectedDoor::ConnectedDoor() {}

void ConnectedDoor::init()
{

}

void ConnectedDoor::process()
{
  if (m_saveMode)
  {
    processSaveCat();
  }
  char id = m_reader.readId();
  if (id != null)
  {
    for (char savedId : m_savedIdList)
    {
      if (id == savedId)
      {
        m_door.open();
        break;
      }
    }
  }
}

void ConnectedDoor::processSaveCat()
{
  // blink Red Led
  // Read Cat
  // light green led
}