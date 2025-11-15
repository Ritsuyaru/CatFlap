#pragma once

// #include "Servo.h"
// #include <thread>

#include "params.h"
#include <Arduino.h>

class Door {
  public:
    Door();
    ~Door();

    void init();

    void lock() {       m_pulse = PULSE_LOCK; } ;
    void unlock() {     m_pulse = PULSE_UNLOCK; } ;
    void enableIn() {   m_pulse = PULSE_ENABLE_IN; } ;
    void enableOut() {  m_pulse = PULSE_ENABLE_OUT; } ;

    void process(u_long current_millis);

  private:
    u_long m_pulse;
    u_long m_begin_period;

    // Servo servo_door;
    
};