#include "types.h"

namespace RAM {
    extern BYTE memory[0x10000];

    void write_memory(WORD address, BYTE data);
    void read_memory(WORD address);
}
