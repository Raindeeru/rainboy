#include <vector>
#include "../types.h"
#include "../mmu.h"

extern std::vector<BYTE> vram;
extern std::vector<BYTE> wram;
extern std::vector<BYTE> echo_ram;
extern std::vector<BYTE> hram;

void MMU::write_wram(WORD address, BYTE data){

} //Handle Switching when I implement CGB
BYTE MMU::read_wram(WORD address){
    return 0;
}
BYTE MMU::read_echo(WORD address){
    return 0;
}
void MMU::write_vram(WORD address, BYTE data){

}
BYTE MMU::read_vram(WORD address){
    return 0;
}
void MMU::write_hram(WORD address, BYTE data){

}
BYTE MMU::read_hram(WORD address){
    return 0;
}
