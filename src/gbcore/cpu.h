#pragma once
#include "types.h"

#define FLAG_Z 128
#define FLAG_N 64
#define FLAG_H 32
#define FLAG_C 16

//8 Bit Register Macros
#define REG_A 1
#define REG_F 0
#define REG_B 3
#define REG_C 2
#define REG_D 5
#define REG_E 4
#define REG_H 7
#define REG_L 6

//16 Bit Register Macros
#define REG_AF 0
#define REG_BC 1
#define REG_DE 2
#define REG_HL 3

#define CONDITION_C 0
#define CONDITION_NC 1
#define CONDITION_Z 2
#define CONDITION_NZ 3
#define PC 0
#define SP 1


namespace CPU {
    union Registers{
        BYTE byte[8];
        WORD word[4];
    };

    extern Registers regs;
    extern WORD reg_special[2];
    extern BYTE ime;
    extern BYTE ir;

    extern int current_step;

    extern int system_clock;

    void init_dmg();

    BYTE get_register(BYTE reg);
    WORD get_register_pair(BYTE reg); 
    
    void fetch();

    void cycle();
}
