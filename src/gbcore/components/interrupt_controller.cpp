#include <vector>
#include "../types.h"
#include "../mmu.h"

BYTE interrupt_enable = 0;

void MMU::write_interrupt_enable(WORD address, BYTE data){
    interrupt_enable = data;
}
BYTE MMU::read_interrupt_enable(WORD address){
    return interrupt_enable;
} //Pwede ba to? Who knows, someone pero like di ko rinesearch
