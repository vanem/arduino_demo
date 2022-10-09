#include "Arduino.h"
#include "stdint.h"
#include "sch.h"
#include "sch_cfg.h"

static Sch_Cfg_Type * Sch_Cfg_Ptr;

void Sch_Init(Sch_Cfg_Type * cfg_ptr) {

    Sch_Cfg_Ptr = cfg_ptr;
    #ifdef SCH_DEBUG
        pinMode(SCH_LOAD_PIN, OUTPUT);
    #endif

}

void Sch_Main(void) {
    uint32_t tick;
    uint8_t num_tasks;
    Sch_Task_Type *tasks;

    num_tasks = Sch_Cfg_Ptr->size;
    tasks = Sch_Cfg_Ptr->tasks;

    // The main while loop.  This while loop will run the program forever
    while(1) {
        //Sys_TimerHandler();
        //tick = Sys_GetTimer();       // Get current system tick
        tick = millis();       // Get current system tick

        // Loop through all tasks.  First, run all continuous tasks.  Then,
        // if the number of ticks since the last time the task was run is
        // greater than or equal to the task interval, execute the task.
        for(uint8_t task_index = 0; task_index < num_tasks; task_index++) {
            if(tasks[task_index].interval == 0) {
                // Run continuous tasks.
                (*tasks[task_index].func)();
            }
            else if(tick >= tasks[task_index].next_tick) {
#ifdef SCH_DEBUG
                digitalWrite(SCH_LOAD_PIN, HIGH);
#endif
                (*tasks[task_index].func)();         // Execute Task
#ifdef SCH_DEBUG
                digitalWrite(SCH_LOAD_PIN, LOW);
#endif
                tasks[task_index].next_tick = tick + tasks[task_index].interval;  // Save last tick the task was ran.
            }
        }
    }
}
