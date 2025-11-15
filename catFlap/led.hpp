#pragma once

#include <Arduino.h>
#include "params.h"

class Led {
  public:
    Led();
    ~Led();

    void init(u_char pin_led);

    void ligth();
    void blinck(u_long current_millis);
    void off();

  private:
    u_char m_led;
    u_long m_pulse_blinck;
    u_long m_previous_millis;
    bool m_led_previous;
};