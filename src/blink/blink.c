#include "Arduino.h"
#include "stdint.h"
#include "deb.h"
#include "deb_cfg.h"

// static uint8_t lvl;

typedef  enum  {
  BLINK_LOW,
  BLINK_HIGH
} Blink_State_Type;

static Blink_State_Type state;
static uint32_t time;
static boolean on_entry;

void Blink_Init(void) {
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  state = BLINK_LOW;
  on_entry = true;

}

// void Blink_Task_1s(void)
// {
//   if (Deb_GetInput(DEB_BLINK_BTN)) {
//     digitalWrite(LED_BUILTIN, lvl);
//     lvl = ~lvl & HIGH; //toggle lvl 0->1 or 1->0
//   }
// }

void Blink_Task(void)
{
  switch (state)
  {
  case BLINK_LOW:
    if (on_entry) {
      digitalWrite(LED_BUILTIN, LOW);
      time = millis();
      on_entry = false;
    }

    if(millis() - time >= 1000) {
      on_entry = true;
      state = BLINK_HIGH;
    }
    break;

  case BLINK_HIGH:
    if (on_entry) {
      digitalWrite(LED_BUILTIN, HIGH);
      time = millis();
      on_entry = false;
    }

    if(millis() - time >= 1000) {
      state = BLINK_HIGH;
    }

    break;
  
  default:
    break;
  }

}
