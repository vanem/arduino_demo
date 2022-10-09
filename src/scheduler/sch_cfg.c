/*
 * sch_cfc.c
 *
 *  Created on: Nov 19, 2018
 *      Author: uia94411
 */
#include "stdint.h"
#include "sch.h"
#include "sch_cfg.h"

/************** Begin - Edit - Module initialization headers */
#include "deb.h"
#include "blink.h"
/************** End - Edit - Module initialization headers */

static Sch_Task_Type tasks[] = {
/************** Begin - Edit - Tasks definitions */    
    /************** Begin - Example
    {
        1000,        //interval in milliseconds
        0,           // offset: set equal to interval so the task is called on the first recurrence
        Blink_Task_1s  //Task container; implement in your application
    },
    *************** End - Example */ 
    {
        10,          //interval in milliseconds
        0,           // offset: set equal to interval so the task is called on the first recurrence
        Deb_Task_10ms  //Task container; implement in your application
    },
    {
        100,        //interval in milliseconds
        5,           // offset: set equal to interval so the task is called on the first recurrence
        Blink_Task  //Task container; implement in your application
    },
/************** End - Edit - Tasks definitions */
};
/* End of Configuration - edit to add new tasks */

/* Scheduler configuration; call Sch_Init(&Sch_Cfg) at startup */
Sch_Cfg_Type Sch_Cfg = {
    sizeof(tasks)/sizeof(tasks[0]),
    tasks
};
