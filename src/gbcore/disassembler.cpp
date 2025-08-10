#include "disassembler.h"
#include <cstdio>
#include <fstream>

BYTE* Disassembler::disassemble_file(std::string filename){
    char* rom;

    std::ifstream file(filename, std::ios::binary);
    file.seekg(0, std::ios::end);
    auto size = file.tellg();
    file.seekg(0, std::ios::beg);
    rom = new char[size];
    file.read(rom, size);
    file.close();

    return (BYTE*)rom;
}
