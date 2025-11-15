#include "esp32-hal-gpio.h"
#include "button.hpp"

Button::Button()
{

}

Button::~Button()
{

}

void Button::init(u_char pin_button)
{
  m_button = pin_button;
  pinMode(pin_button, INPUT);
  m_state = false;
  m_previous_millis = 0;
}

void Button::process(u_long current_millis)
{
  if (current_millis - m_previous_millis >= DEBOUND)
  {
    bool state = digitalRead(m_button);
    if (state != m_state)
    {
      m_state = state;
      m_previous_millis = current_millis;
    }
  }
  
}