#include <sys/types.h>
#pragma once

// #include <Types.h>
// #include <list>
/*
#define LOGGER_TRACE 1
#define LOGGER_DEBUG 2
#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3

#define LOGGER_LEVEL LOGGER_DEBUG
*/
// interrupt variable
// volatile byte activeButton = 0;
#define DEBOUNCE_TIME 100 // milliseconds
#define TIMEOUT 15000 // milliseconds
#define DEBOUND 10
#define LIST_ADDR 1
#define CAT_ADDR 2

#define DOOR_LOCK 0
#define DOOR_UNLOCK 90
#define DOOR_OUT_ENABLE 180
#define DOOR_IN_ENABLE 270

#define PULSE_LOCK 1
#define PULSE_UNLOCK 9
#define PULSE_ENABLE_OUT 15 
#define PULSE_ENABLE_IN 19
#define PERIOD_PULSE 20


//Step fo saving a cat
#define STEP_SAVE_WAIT_CAT  1
#define STEP_SAVE_READY     2
#define STEP_SAVE_SUCCESS   3
#define STEP_SAVE_WRONG     4
#define STEP_SAVE_ENDING    5
#define STEP_SAVING         0

// static const u_char logger = LOGGER_DEBUG;

static const u_char pinRstButton  = 1;
static const u_char pinSaveButton = 2;
static const u_char pinRedLed     = 3;
static const u_char pinGreenLed   = 4;
static const u_char pinServoDoor  = 5;

static const u_char pinRFID_Rst   = 5;
static const u_char pinRFID_Tx    = 6;

static const u_char pinDetectorMvt = 7;

