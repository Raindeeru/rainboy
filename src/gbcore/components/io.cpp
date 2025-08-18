#include <vector>
#include "../types.h"
#include "../mmu.h"

#define IO_OFFSET 0xFF00

//Only DMG
BYTE joypad = 0;
std::vector<BYTE> serial{0};
std::vector<BYTE> timer{0};
BYTE interrupt_flag = 0;
std::vector<BYTE> audio{0};
std::vector<BYTE> wave_pattern{0};
std::vector<BYTE> lcd{0};
BYTE boot_room_control = 0;

void MMU::write_io(WORD address, BYTE data){
    if (address == 0xFF00){
        //Joypad
        joypad = data;
    }else if (address == 0xFF01 || address == 0xFF02){
        //Serial Transfer
        serial[address - 0xFF01] = data;
    }else if (address >= 0xFF04 && address <= 0xFF07){
        //Timer
        timer[address - 0xFF04] = data;
    }else if (address == 0xFF0F){
        //Interrupts
        interrupt_flag = data;
    }else if (address >= 0xFF10 && address <= 0xFF26){
        //Audio
        audio[address - 0xFF10] = data;
    }else if (address >= 0xFF30 && address <= 0xFF3F){
        //Wave Pattern
        wave_pattern[address - 0xFF30] = data;
    }else if (address >= 0xFF40 && address <= 0xFF4B){
        //LCD
        lcd[address - 0xFF40] = data;
    }else if (address == 0xFF4F){
        //CGB VRAM Bank Select
    }else if (address == 0xFF50){
        //Bot Rom Mapping
        boot_room_control = data;
    }else if (address >= 0xFF51 && address <= 0xFF55){
        //CGB VRAM DMA
    }else if (address >= 0xFF68 && address <= 0xFF6B){
        //CGB BG/OBJ Palletes
    }else if (address == 0xFF70){
        //CGB WRAM Bank Select
    }

}
BYTE MMU::read_io(WORD address){
    if (address == 0xFF00){
        //Joypad
        return joypad;
    }else if (address == 0xFF01 || address == 0xFF02){
        //Serial Transfer
        return serial[address - 0xFF01];
    }else if (address >= 0xFF04 && address <= 0xFF07){
        //Timer
        return timer[address - 0xFF04];
    }else if (address == 0xFF0F){
        //Interrupts
        return interrupt_flag;
    }else if (address >= 0xFF10 && address <= 0xFF26){
        //Audio
        return audio[address - 0xFF10];
    }else if (address >= 0xFF30 && address <= 0xFF3F){
        //Wave Pattern
        return wave_pattern[address - 0xFF30];
    }else if (address >= 0xFF40 && address <= 0xFF4B){
        //LCD
        return lcd[address - 0xFF40];
    }else if (address == 0xFF4F){
        //CGB VRAM Bank Select
    }else if (address == 0xFF50){
        //Bot Rom Mapping
        return boot_room_control;
    }else if (address >= 0xFF51 && address <= 0xFF55){
        //CGB VRAM DMA
    }else if (address >= 0xFF68 && address <= 0xFF6B){
        //CGB BG/OBJ Palletes
    }else if (address == 0xFF70){
        //CGB WRAM Bank Select
    }
    return 0;
} //Idk how this work
