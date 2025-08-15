#include <vector>
#include "../types.h"
#include "../mmu.h"

extern std::vector<BYTE> external_ram;
extern std::vector<BYTE> external_rom;

void MMU::handle_mbc(WORD address){

}
BYTE MMU::read_cart_rom(WORD address){
    return 0;
}
void MMU::write_external_ram(WORD address, BYTE data){

}
BYTE MMU::read_external_ram(WORD address){
    return 0;
}
