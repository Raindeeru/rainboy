#pragma once
#include "types.h"

#define FLAG_Z 7
#define FLAG_N 6
#define FLAG_H 5
#define FLAG_C 4

//8 Bit Register Macros
#define REG_A 0
#define REG_F 1
#define REG_B 2
#define REG_C 3
#define REG_D 4
#define REG_E 5
#define REG_H 6
#define REG_L 7

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

    extern bool fetch_enable; //Set by the Executing Opcode to signify it can start fetching
    extern BYTE current_opcode;

    void init_dmg();

    BYTE get_register(BYTE reg);
    WORD get_register_pair(BYTE reg); 
    
    BYTE fetch();


    void cycle();
}
