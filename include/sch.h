#ifndef SCH_H_
#define SCH_H_

/**
 * Struct TaskType
 * TaskType structure is used to define the parameters required in order to
 * configure a task.
 */

typedef struct
{
    uint16_t interval;          /* Defines how often a task will run  */
    uint32_t next_tick;         /* Stores the last tick task was ran  */
    void (*func)(void);         /* Function pointer to the task  */
} Sch_Task_Type;

typedef struct
{
    uint8_t size;
    Sch_Task_Type * tasks;
} Sch_Cfg_Type;

#ifdef __cplusplus
extern "C"{
#endif

void Sch_Init(Sch_Cfg_Type * cfg_ptr);
void Sch_Main(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* SCH_H_ */