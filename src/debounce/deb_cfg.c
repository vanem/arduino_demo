#include "stdint.h"
#include "deb.h"
#include "deb_cfg.h"

static Deb_Input_Type inputs[] = {
    {
        2, //uint8_t pin
        3, //uint8_t threshold
        0, //uint8_t lvl_cnt
        0, //uint8_t filtered_lvl
    },
    {
        3, //uint8_t pin
        3, //uint8_t threshold
        0, //uint8_t lvl_cnt
        0, //uint8_t filtered_lvl
    },
};

Deb_Cfg_Type Deb_Cfg = {
    sizeof(inputs)/sizeof(inputs[0]),
    inputs
};
