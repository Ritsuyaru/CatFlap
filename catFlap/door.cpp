#include "door.hpp"

Door::Door()
{
  // servo_door.attach(pinServoDoor);

}

Door::~Door()
{

}

void Door::init()
{
  pinMode(pinServoDoor, OUTPUT);
  digitalWrite(pinServoDoor, LOW);
  // servo_door.attach(pinServoDoor);
  m_pulse = 0;
  m_begin_period = 0;
}

void Door::process(u_long current_millis)
{

  if (current_millis >= 4294967295) //prevent Overflow problems
  {
    m_begin_period = 0;
  } 

  if (current_millis - m_begin_period >= m_pulse)
  {
    digitalWrite(pinServoDoor, LOW);
  }
  else
  {
    digitalWrite(pinServoDoor, HIGH);
  }
  if (current_millis - m_begin_period >= PERIOD_PULSE)
  {
    m_begin_period = current_millis;
  }
}
