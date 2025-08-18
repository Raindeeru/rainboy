#include <vector>
#include "../common.h"

std::vector<BYTE> vram{0};
std::vector<BYTE> wram{0}; //8kb, more if CGB
std::vector<BYTE> echo_ram{0};
std::vector<BYTE> hram{0};

#define VRAM_OFFSET 0x8000
#define WRAM_OFFSET 0xC000
#define ECHO_OFFSET 0xE000
#define HRAM_OFFSET 0xE000

void MMU::write_wram(WORD address, BYTE data){
    WORD wram_address = address - WRAM_OFFSET;
    wram[wram_address] = data;
} //Handle Switching when I implement CGB

BYTE MMU::read_wram(WORD address){
    WORD wram_address = address - WRAM_OFFSET;
    return wram[wram_address];
}
BYTE MMU::read_echo(WORD address){
    WORD echo_address = address - ECHO_OFFSET;
    return wram[echo_address];
}
void MMU::write_vram(WORD address, BYTE data){
    WORD vram_address = address - VRAM_OFFSET;
    vram[vram_address] = data;
}
BYTE MMU::read_vram(WORD address){
    WORD vram_address = address - VRAM_OFFSET;
    return vram[vram_address];
}
void MMU::write_hram(WORD address, BYTE data){
    WORD hram_address = address - HRAM_OFFSET;
    hram[hram_address] = data;
}
BYTE MMU::read_hram(WORD address){
    WORD hram_address = address - HRAM_OFFSET;
    return hram[hram_address];
}
