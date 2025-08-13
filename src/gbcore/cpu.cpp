#include "common.h"

void MMU::write_memory(BYTE data, WORD address){
    if (address >= 0x0000 && address <= 0x7FFF){        //Memory Banking Handling
        MMU::handle_mbc(address);
    }else if (address >= 0x8000 && address <= 0x9FFF){  //Video Ram, switchable if CGB
        MMU::write_vram(address, data);
    }else if (address >= 0xA000 && address <= 0xBFFF){  //External Ram
        MMU::write_external_ram(address, data);
    }else if (address >= 0xC000 && address <= 0xDFFF){  //Work Ram
        MMU::write_wram(address, data);
    }else if (address >= 0xE000 && address <= 0xFDFF){  //Echo Ram (Copies from Work Ram), prohibited daw

    }else if (address >= 0xFE00 && address <= 0xFE9F){  //OAM
        MMU::write_oam(address, data); 
    }else if (address >= 0xFEA0 && address <= 0xFEFF){ //Not Useable Daw idk
        MMU::handle_not_useable_writes(address, data);
    }else if (address >= 0xFF00 && address <= 0xFF7F){  //I/0 Registers
        MMU::write_io(address, data);
    }else if (address >= 0xFF80 && address <= 0xFFFE){  //High Ram
        MMU::write_hram(address, data);
    }else{                                              //Interrupt Enable register
        MMU::write_interrupt_enable(address, data);
    }
}

BYTE MMU::read_memory(WORD address){
    if (address >= 0x0000 && address <= 0x7FFF){        //Rom MBC Here
        return MMU::read_cart_rom(address);
    }else if (address >= 0x8000 && address <= 0x9FFF){  //Video Ram, switchable if CGB
        return MMU::read_vram(address);
    }else if (address >= 0xA000 && address <= 0xBFFF){  //External Ram
        return MMU::read_external_ram(address);
    }else if (address >= 0xC000 && address <= 0xDFFF){  //Work Ram
        return MMU::read_wram(address);
    }else if (address >= 0xE000 && address <= 0xFDFF){  //Echo Ram (Copies from Work Ram), prohibited daw
        return MMU::read_echo(address);
    }else if (address >= 0xFE00 && address <= 0xFE9F){  //OAM
       return read_oam(address); 
    }else if (address >= 0xFEA0 && address <= 0xFEFF){  //Not Usable daw
        return MMU::handle_not_useable_reads(address);
    }else if (address >= 0xFF00 && address <= 0xFF7F){  //I/0 Registers
        return MMU::read_io(address);
    }else if (address >= 0xFF80 && address <= 0xFFFE){ //High Ram
        return MMU::read_hram(address);
    }else{                                              //Interrupt Enable register
        return MMU::read_interrupt_enable(address);
    }

}
