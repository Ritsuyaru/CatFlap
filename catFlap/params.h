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
#define LIST_ADDR 1
#define CAT_ADDR 2
// static const u_char logger = LOGGER_DEBUG;

static const u_char pinRstButton  = 1;
static const u_char pinSaveButton = 2;
static const u_char pinRedLed     = 3;
static const u_char pinGreenLed   = 4;

static const u_char pinRFID_Rst   = 5;
static const u_char pinRFID_Tx    = 6;
