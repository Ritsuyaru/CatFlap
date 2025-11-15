#include "esp32-hal-gpio.h"
#include "led.hpp"

Led::Led()
{

}

Led::~Led()
{

}

void Led::init(u_char pin_led)
{
  m_led = pin_led;
  pinMode(m_led, OUTPUT);
  digitalWrite(m_led, LOW);
}


void Led::ligth()
{
  digitalWrite(m_led, HIGH);
}

void Led::blinck(u_long current_millis)
{
  if (current_millis - m_previous_millis >= m_pulse_blinck)
  {
    if (m_led_previous)
    {
      digitalWrite(m_led, LOW);
      m_led_previous = false;
    }
    else
    {
      digitalWrite(m_led, HIGH);
      m_led_previous = true;
    }
  }
}

void Led::off()
{
  digitalWrite(m_led, LOW);
}
