#include "types.h"
#include <vector>
namespace MMU {
    void write_memory(BYTE data, WORD address); 
    BYTE read_memory(WORD address);

    //remove this stuff this is just for reference honestly
    //I will be using raw arrays and poi

    void handle_mbc(WORD address);
    BYTE read_cart_rom(WORD address);
    void write_external_ram(WORD address, BYTE data);
    BYTE read_external_ram(WORD address);
    void handle_io(WORD address);
    void write_wram(WORD address, BYTE data); //Handle Switching when I implement CGB
    BYTE read_wram(WORD address);
    BYTE read_echo(WORD address);
    void write_vram(WORD address, BYTE data);
    BYTE read_vram(WORD address);
    void write_hram(WORD address, BYTE data);
    BYTE read_hram(WORD address);
    void write_oam(WORD address, BYTE data); //Idk If this even possible
    BYTE read_oam(WORD address); //I think I should use DMA Transfers
    void write_io(WORD address, BYTE data);
    BYTE read_io(WORD address); //Idk how this work
    void write_interrupt_enable(WORD address, BYTE data);
    BYTE read_interrupt_enable(WORD address); //Pwede ba to? Who knows, someone pero like di ko rinesearch

    void handle_not_useable_writes(WORD address, BYTE data); //I think kailangan ko mag implement OAM corruption
    BYTE handle_not_useable_reads(WORD address);
}
