#pragma once

class ConnectedDoor {
  public:
    ConnectedDoor();
    ~ConnectedDoor();

    void init();
    void process();

  private:
    Door m_door;
    RfidReader m_reader;
    std::list<u_char> m_savedIdList
    bool m_save_mode=false; //Mode for saving cat id

    void processSaveCat();
}
