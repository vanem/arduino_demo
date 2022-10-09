#include "Arduino.h"
#include "stdint.h"
#include "deb.h"


static Deb_Cfg_Type * Deb_Cfg_Ptr;

void Deb_Init(Deb_Cfg_Type * cfg_ptr) {
    uint8_t num_inputs;
    Deb_Input_Type *inputs;

    Deb_Cfg_Ptr = cfg_ptr;

    num_inputs = Deb_Cfg_Ptr->size;
    inputs = Deb_Cfg_Ptr->inputs;

    for(uint8_t i = 0; i < num_inputs; i++) {
        pinMode(inputs[i].pin, INPUT_PULLUP);
    }

}

uint8_t Deb_GetInput(uint8_t in_handle) {
    Deb_Input_Type *inputs = Deb_Cfg_Ptr->inputs;

    return inputs[in_handle].filtered_lvl;

}

void Deb_Task_10ms(void)
{
    uint8_t num_inputs = Deb_Cfg_Ptr->size;
    Deb_Input_Type *inputs = Deb_Cfg_Ptr->inputs;

    for(uint8_t i = 0; i < num_inputs; i++) {

        switch (inputs[i].filtered_lvl)
        {
        case LOW:
            if (digitalRead(inputs[i].pin) == HIGH) {
                inputs[i].lvl_cnt++;
            }
            else {
                inputs[i].lvl_cnt = 0;
            }
            if (inputs[i].lvl_cnt >= inputs[i].threshold) {
                inputs[i].lvl_cnt = 0;
                inputs[i].filtered_lvl = HIGH;
            }
            break;
        case HIGH:
            if (digitalRead(inputs[i].pin) == LOW) {
                inputs[i].lvl_cnt++;
            }
            else {
                inputs[i].lvl_cnt = 0;
            }
            if (inputs[i].lvl_cnt >= inputs[i].threshold) {
                inputs[i].lvl_cnt = 0;
                inputs[i].filtered_lvl = LOW;
            }
            break;
        default:
            break;
        }
    }
}
