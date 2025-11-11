#pragma once

#include <cstdarg>
#include <EEPROM.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "params.h"
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
    // Door m_door;
    // RfidReader m_reader;
    std::vector<u_char> m_savedIdList;
    bool m_save_mode=false; //Mode for saving cat id

    void processSaveCat();
};
