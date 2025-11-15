#include "params.h"
#include "connectedDoor.hpp"

ConnectedDoor::ConnectedDoor()
{
}

ConnectedDoor::~ConnectedDoor() {}

void ConnectedDoor::init()
{
  m_door.init();
  m_red_led.init(pinRedLed);
  m_green_led.init(pinGreenLed);
  // m_reset_button.init(pinRstButton);
  m_save_button.init(pinSaveButton);
  m_detector_mvt.init(pinDetectorMvt);

  m_step_saving = STEP_SAVE_READY;
  // m_readerId.init();

  u_char list_size = EEPROM.read(LIST_ADDR);
  for (u_char cat=0; cat<=list_size; cat++)
  {
    m_savedIdList.push_back(EEPROM.read(CAT_ADDR+cat));
  }

}

void ConnectedDoor::process()
{
  u_long millisec = millis();
  // m_reset_button.process(millisec);
  m_save_button.process(millisec);
  // if (m_detector_mvt.isPush) // go to sleep if nothing and economizing energy
  // if (m_save_button.isPush())
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
  // else
  // {
  //   sleep(50);
  // }
  }
}

void ConnectedDoor::processSaveCat(u_long current_millis)
{
  switch (m_step_saving)
  {
    case STEP_SAVE_READY:
      // blink Green Led / or ligth green LED
      m_green_led.blinck(current_millis);
      if (m_detector_mvt.isPush()) m_step_saving = STEP_SAVE_WAIT_CAT;
      break;
    case STEP_SAVE_WAIT_CAT:
    {
      m_green_led.blinck(current_millis);
      // Read cat Id
      u_char catId = NULL;
      m_step_saving = STEP_SAVING;
      break;
    }
    case STEP_SAVING:
    {
      m_green_led.ligth();
      m_red_led.ligth();
      // save cat id in a list / push back
      u_char list_size = 0;
      // Read Cat

      // Save cat id in EEPROM
      list_size = EEPROM.read(LIST_ADDR);
      EEPROM.write(LIST_ADDR, list_size++);
      EEPROM.write(CAT_ADDR+list_size, catId);
      m_step_saving = STEP_SAVE_SUCCESS;
      break;
    }
    case STEP_SAVE_SUCCESS:
      m_red_led.off();
      m_green_led.ligth();
      // if (timeup) m_step_saving = STEP_SAVE_ENDING;
      break;
    case STEP_SAVE_ENDING:
      m_green_led.off();
      m_save_mode = false;
      m_step_saving = STEP_SAVE_READY;
      break;
    case STEP_SAVE_WRONG:
    default:
      if (m_timer.isTimeUp(current_millis)) m_step_saving = STEP_SAVE_READY;
      m_red_led.blinck(current_millis);
      break;
  }
}