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

    class DMG{
        public:
            Registers regs{};
            WORD pc_sp[2]{};
            BYTE memory[0x10000];

            BYTE get_register(BYTE reg);
            WORD get_register_pair(BYTE reg);
    };
}
