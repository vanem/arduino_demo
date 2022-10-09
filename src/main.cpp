/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "sch.h"
#include "sch_cfg.h"

/************** Begin - Edit - Module initialization headers */
#include "deb.h"
#include "deb_cfg.h"

#include "blink.h"
//#include "blink_cfg.h"
/************** End - Edit - Module initialization headers */



void setup()
{
  Sch_Init(&Sch_Cfg);

  /************** Begin - Edit - Initialization functions */
  Deb_Init(&Deb_Cfg);
  Blink_Init();
  /************** End - Edit-  Initialization functions */


  Sch_Main();

}

void loop()
{
}

