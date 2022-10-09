#ifndef DEB_H_
#define DEB_H_

/**
 * Struct InputType
 * used to define the parameters required in order to configure a filtered input.
 */
typedef struct
{
    uint8_t pin;
    uint8_t threshold;
    uint8_t lvl_cnt;
    uint8_t filtered_lvl;
} Deb_Input_Type;

typedef struct
{
    uint8_t size;
    Deb_Input_Type * inputs;
} Deb_Cfg_Type;

#ifdef __cplusplus
extern "C"{
#endif

void Deb_Init(Deb_Cfg_Type * cfg_ptr);
void Deb_Task_10ms(void);
uint8_t Deb_GetInput(uint8_t in_handle);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DEB_H_ */