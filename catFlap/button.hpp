#pragma once

#include <Arduino.h>

#include "params.h"

class Button
{
  public:
    Button();
    ~Button();

    void init(u_char pin_button);

    bool isPush() { return m_state; };

    void process(u_long current_millis);

  private:
    bool m_state;
    u_char m_button;
    u_long m_previous_millis;
};