#pragma once

#include <Arduino.h>

class TimeUp
{
  public:
    TimeUp(u_long time_up, u_long current_millis)
    {
      m_time_up = time_up;
      m_previous_millis = current_millis;
    };
    ~Timeup();
    void init(u_long current_millis)
    {
      m_previous_millis = current_millis;
    };
    bool isTimeUp(u_long current_millis)
    {
      if (current_millis - m_previous_millis >= m_time_up) return true;
      return false
    };
  private:
    u_long m_time_up;
    u_long m_previous_millis;
};