#pragma once
#include "types.h"

#define FLAG_Z 7
#define FLAG_N 6
#define FLAG_H 5
#define FLAG_C 4

//8 Bit Register Macros
#define A 0
#define F 1
#define B 2
#define C 3
#define D 4
#define E 5
#define H 6
#define L 7

//16 Bit Register Macros
#define AF 0
#define BC 1
#define DE 2
#define HL 3

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
