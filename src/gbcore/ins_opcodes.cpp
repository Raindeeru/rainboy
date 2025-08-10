#include "instructions.h"
int Instructions::decode_execute(BYTE opcode){
    switch (opcode) {
        default:
            //Unimplemented Opcodes
            return 0;
    }
    //The function shouldn't reach here
    return 0;
}

int prefix_0xcb(BYTE opcode){
    switch (opcode) {
        default:
            //The function shouldn't reach here
            return 0;
    }
    //The function shouldn't reach here
    return 0;
}
