#pragma once

#include <cstdarg>
#include <EEPROM.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <Arduino.h>

#include "params.h"
#include "door.hpp"
#include "led.hpp"
#include "button.hpp"
// #include "librairies/StandardCplusplus-master/StandardCplusplus.h"

// #include <list>
// #include <Types.h>

class ConnectedDoor {
  public:
    ConnectedDoor();
    ~ConnectedDoor();

    void init();
    void process();

  private:
    Door m_door;
    Led m_red_led;
    Led m_green_led;
    //Button m_reset_button;
    Button m_save_button;

    // RfidReader m_reader;
    std::vector<u_char> m_savedIdList;
    bool m_save_mode=false; //Mode for saving cat id

    u_char m_step_saving;

    void processSaveCat(u_long current_millis);
};

