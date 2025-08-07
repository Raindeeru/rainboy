#pragma once
#include "types.h"

#define FLAG_Z 7
#define FLAG_N 6
#define FLAG_H 5
#define FLAG_C 4

namespace CPU {
    extern BYTE registers[8];
    extern WORD pc;
    extern WORD sp;

    extern WORD ir;
    extern WORD ie;

    BYTE get_register(BYTE reg);
    WORD get_register_pair(BYTE reg);
}
