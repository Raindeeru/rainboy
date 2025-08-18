#include "common.h"
#include "cpu.h"
#include "types.h"

int current_step = 0;

BYTE temp_buffer_z = 0;
BYTE temp_buffer_w = 0;

WORD temp_address = 0;

bool check_if_carry(BYTE op1, BYTE op2){
    if (((WORD)op1 + (WORD)op2) > 0xFF)
        return true;
    else
        return false;
}

int Instructions::load_register(int reg, int reg_prime, int step){
    CPU::regs.byte[reg] = CPU::regs.byte[reg_prime];
    CPU::reg_special[PC]++;
    CPU::fetch();
    return 0;
}
int Instructions::load_register_immediate(int reg, int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            CPU::regs.byte[reg] = MMU::read_memory(CPU::reg_special[PC]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_register_hl(int reg, int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            CPU::regs.byte[reg] = MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_register_hl(int reg, int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            MMU::write_memory(CPU::regs.byte[reg], CPU::regs.word[REG_HL]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_hl_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::regs.word[REG_HL]);
            return 2;
        case 2:
            MMU::write_memory(temp_buffer_z, CPU::regs.word[REG_HL]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_accumulator_bc(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            CPU::regs.byte[REG_A] = MMU::read_memory(CPU::regs.word[REG_BC]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_accumulator_de(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            CPU::regs.byte[REG_A] = MMU::read_memory(CPU::regs.word[REG_DE]);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_accumulator_bc(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            MMU::write_memory(CPU::regs.byte[REG_A],CPU::regs.word[REG_BC] );
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_accumulator_de(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            MMU::write_memory(CPU::regs.byte[REG_A],CPU::regs.word[REG_DE] );
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_accumulator(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            temp_address = MMU::read_memory(CPU::reg_special[PC]);
            CPU::reg_special[PC]++;
            return 2;
        case 2:
            temp_address |= ((WORD)MMU::read_memory(CPU::reg_special[PC])) << 8;
            return 3;
        case 3:
            temp_buffer_z = MMU::read_memory(temp_address);
            CPU::regs.word[REG_A] = temp_buffer_z;
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_accumulator(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            temp_address = MMU::read_memory(CPU::reg_special[PC]);
            CPU::reg_special[PC]++;
            return 2;
        case 2:
            temp_address |= ((WORD)MMU::read_memory(CPU::reg_special[PC])) << 8;
            return 3;
        case 3:
            temp_buffer_z = CPU::regs.byte[REG_A];
            MMU::write_memory(temp_buffer_z, temp_address);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_accumulator_c(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_address = 0xFF00 + CPU::regs.byte[REG_C];
            CPU::regs.byte[REG_A] = MMU::read_memory(temp_address);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 2;
        default:
            return 0;
    }
    return 0;
}//This is Offsetted by 0xFF00
int Instructions::load_from_accumulator_c(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_address = 0xFF00 + CPU::regs.byte[REG_C];
            MMU::write_memory(CPU::regs.byte[REG_A], temp_address);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 2;
        default:
            return 0;
    }
    return 0;
}//This is Offsetted by 0xFF00
int Instructions::load_accumulator_offset(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::reg_special[PC]);
            return 2;
        case 2:
            temp_address = 0xFF00 + temp_buffer_z;
            CPU::regs.byte[REG_A] = MMU::read_memory(temp_address);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
} //This is Offsetted by 0xFF00
int Instructions::load_from_accumulator_offset(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC]++;
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::reg_special[PC]);
            return 2;
        case 2:
            temp_address = 0xFF00 + temp_buffer_z;
            MMU::write_memory(CPU::regs.byte[REG_A], temp_address);
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
} //This is Offsetted by 0xFF00
int Instructions::load_accumulator_hl_decrement(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_A] = temp_buffer_z;
            CPU::regs.word[REG_HL] --;
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_accumulator_hl_decrement(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            MMU::write_memory(CPU::regs.byte[REG_A], CPU::regs.word[REG_HL]); 
            CPU::regs.word[REG_HL] --;
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_accumulator_hl_increment(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_A] = temp_buffer_z;
            CPU::regs.word[REG_HL] ++;
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_accumulator_hl_increment(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            MMU::write_memory(CPU::regs.byte[REG_A], CPU::regs.word[REG_HL]); 
            CPU::regs.word[REG_HL] ++;
            CPU::reg_special[PC]++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
} 

//x16/lsm
int Instructions::load_register_immediate_16bit(int reg_16bit, int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:
            CPU::regs.word[reg_16bit] = MMU::read_memory(CPU::reg_special[PC]);
            CPU::reg_special[PC] ++;
            return 2;
        case 2:
            CPU::regs.word[reg_16bit] |= (((WORD)(MMU::read_memory(CPU::reg_special[PC])) << 8));
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;

        default:
            return 0;
    }
    return 0;
}
int Instructions::load_from_stack(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:
            temp_address = MMU::read_memory(CPU::reg_special[PC]);
            CPU::reg_special[PC] ++;
            return 2;
        case 2:
            temp_address |= ( ((WORD)MMU::read_memory(CPU::reg_special[PC])) << 8);
            return 3;
        case 3:
            temp_buffer_z = (BYTE)CPU::reg_special[SP];
            MMU::write_memory(temp_buffer_z, temp_address);
            temp_address ++;
            return 4;
        case 4:
            temp_buffer_z = (BYTE)((CPU::reg_special[SP]) >> 8);
            MMU::write_memory(temp_buffer_z, temp_address);
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::load_stack_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            CPU::reg_special[SP] = CPU::regs.word[REG_HL];
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::push(int reg_16bit, int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            CPU::reg_special[SP]--;
            return 2;
        case 2:
            MMU::write_memory((CPU::regs.byte[reg_16bit*2 + 1]), CPU::reg_special[SP]);
            CPU::reg_special[SP]--;
            return 3;
        case 3:
            MMU::write_memory((BYTE)(CPU::regs.byte[reg_16bit*2]), CPU::reg_special[SP]);
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
}
int Instructions::pop(int reg_16bit, int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::reg_special[SP]);
            CPU::reg_special[SP]++;
            return 2;
        case 2:
            temp_buffer_w = MMU::read_memory(CPU::reg_special[SP]);
            CPU::reg_special[SP]++;
            return 3;
        case 3:
            CPU::regs.word[reg_16bit] = (WORD)temp_buffer_z | (((WORD)temp_buffer_w) << 8);
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
    }
    return 0;
}
int Instructions::load_hl_sp_plus_e(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:
            {
                SIGNED_BYTE e = (SIGNED_BYTE)MMU::read_memory(CPU::reg_special[PC]);
                WORD result = e + CPU::reg_special[SP];
                CPU::regs.word[REG_HL] = result;

                WORD carry_per_bit = CPU::reg_special[SP] ^ e ^ result;
                CPU::regs.byte[REG_F] = (carry_per_bit & 0x100 ? FLAG_C : 0) | 
                                        (carry_per_bit & 0x10 ? FLAG_H : 0);
            }
            return 2;
        case 2:
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        default:
            return 0;
    }
    return 0;
} //Wtf is this used for

//x8/alu 
int Instructions::add_register(int reg, int step){
    int a = CPU::regs.byte[REG_A]; 
    int r = CPU::regs.byte[reg]; 
    int result = a + r;

    bool flag_c = (a + r) > 0xFF;
    bool flag_h = ((a & 0xF) + (r & 0xF)) > 0xF;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[REG_A] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::add_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int hl = MMU::read_memory(CPU::regs.word[REG_HL]); 
            int result = a + hl;

            bool flag_c = (a + hl) > 0xFF;
            bool flag_h = ((a & 0xF) + (hl & 0xF)) > 0xF;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::add_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int n = MMU::read_memory(CPU::reg_special[PC]); 
            int result = a + n;

            bool flag_c = (a + n) > 0xFF;
            bool flag_h = ((a & 0xF) + (n & 0xF)) > 0xF;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::add_with_carry_register(int reg, int step){
    int a = CPU::regs.byte[REG_A]; 
    int r = CPU::regs.byte[reg]; 
    int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
    int result = a + r + c;

    bool flag_c = (a + r + c) > 0xFF;
    bool flag_h = ((a & 0xF) + (r & 0xF) + (c & 0xF)) > 0xF;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[REG_A] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::add_with_carry_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int hl = MMU::read_memory(CPU::regs.word[REG_HL]); 
            int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
            int result = a + hl + c;

            bool flag_c = (a + hl + c)> 0xFF;
            bool flag_h = ((a & 0xF) + (hl & 0xF) + c) > 0xF;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::add_with_carry_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int n = MMU::read_memory(CPU::reg_special[PC]); 
            int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
            int result = a + n + c;

            bool flag_c = (a + n + c) > 0xFF;
            bool flag_h = ((a & 0xF) + (n & 0xF) + c) > 0xF;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::sub_register(int reg, int step){
    int a = CPU::regs.byte[REG_A]; 
    int r = CPU::regs.byte[reg]; 
    int result = a - r;

    bool flag_c = r > a ;
    bool flag_h = (r & 0xF) >(a & 0xF);
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 1;

    CPU::regs.byte[REG_A] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::sub_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int hl = MMU::read_memory(CPU::regs.word[REG_HL]); 
            int result = a - hl;

            bool flag_c = hl > a ;
            bool flag_h = (hl & 0xF) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::sub_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int n = MMU::read_memory(CPU::reg_special[PC]); 
            int result = a - n;

            bool flag_c = n > a ;
            bool flag_h = (n & 0xF) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::sub_with_carry_register(int reg, int step){
    int a = CPU::regs.byte[REG_A]; 
    int r = CPU::regs.byte[reg]; 
    int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
    int result = a - r - c;

    bool flag_c = (r + c) > a ;
    bool flag_h = ((r & 0xF) + c) >(a & 0xF);
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 1;

    CPU::regs.byte[REG_A] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::sub_with_carry_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int hl = MMU::read_memory(CPU::regs.word[REG_HL]); 
            int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
            int result = a - hl - c;

            bool flag_c = hl > a ;
            bool flag_h = ((hl & 0xF) + c) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::sub_with_carry_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int n = MMU::read_memory(CPU::reg_special[PC]); 
            int c = (CPU::regs.byte[REG_F] & FLAG_C) ? 1:0;
            int result = a - n - c;

            bool flag_c = (n + c) > a ;
            bool flag_h = ((n & 0xF) + c) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_A] = (BYTE)result;
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::compare_register(int reg, int step){
    int a = CPU::regs.byte[REG_A]; 
    int r = CPU::regs.byte[reg]; 
    int result = a - r;

    bool flag_c = r > a ;
    bool flag_h = (r & 0xF) >(a & 0xF);
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 1;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::compare_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int hl = MMU::read_memory(CPU::regs.word[REG_HL]); 
            int result = a - hl;

            bool flag_c = hl > a ;
            bool flag_h = (hl & 0xF) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::compare_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            int a = CPU::regs.byte[REG_A]; 
            int n = MMU::read_memory(CPU::reg_special[PC]); 
            int result = a - n;

            bool flag_c = n > a ;
            bool flag_h = (n & 0xF) >(a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::fetch();
            CPU::reg_special[PC] ++;
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::increment_register(int reg, int step){
    int a = CPU::regs.byte[reg]; 
    int result = a + 1;

    bool flag_c = CPU::regs.byte[REG_F] & FLAG_C;
    bool flag_h = ((a & 0xF) + 1) > 0xF;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[reg] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::increment_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::regs.word[REG_HL]);
            return 2;
        case 2:{
            int a = temp_buffer_z; 
            int result = a + 1;

            bool flag_c = CPU::regs.byte[REG_F] & FLAG_C;
            bool flag_h = ((a & 0xF) + 1) > 0xF;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            MMU::write_memory((BYTE)result, CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::decrement_register(int reg, int step){
    int a = CPU::regs.byte[reg]; 
    int result = a - 1;

    bool flag_c = CPU::regs.byte[REG_F] & FLAG_C;
    bool flag_h = 1 > (a & 0xF);
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 1;

    CPU::regs.byte[reg] = (BYTE)result;
    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                            (flag_z ? FLAG_Z:0)|
                            (flag_h ? FLAG_H:0)|
                            (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::decrement_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:
            temp_buffer_z = MMU::read_memory(CPU::regs.word[REG_HL]);
            return 2;
        case 2:{
            int a = temp_buffer_z; 
            int result = a - 1;

            bool flag_c = CPU::regs.byte[REG_F] & FLAG_C;
            bool flag_h = 1 > (a & 0xF);
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 1;

            MMU::write_memory((BYTE)result, CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                                    (flag_z ? FLAG_Z:0)|
                                    (flag_h ? FLAG_H:0)|
                                    (flag_n ? FLAG_N:0);
            CPU::reg_special[PC] ++;
            CPU::fetch();
            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_and_register(int reg, int step){
    BYTE result = CPU::regs.byte[REG_A] & CPU::regs.byte[reg];
    CPU::regs.byte[REG_A] = result;

    bool flag_c = 0;
    bool flag_h = 1;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();

    return 0;
}
int Instructions::bit_and_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] & MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_and_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] & MMU::read_memory(CPU::reg_special[PC]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_or_register(int reg, int step){
    BYTE result = CPU::regs.byte[REG_A] | CPU::regs.byte[reg];
    CPU::regs.byte[REG_A] = result;

    bool flag_c = 0;
    bool flag_h = 1;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();

    return 0;
}
int Instructions::bit_or_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] | MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_or_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] | MMU::read_memory(CPU::reg_special[PC]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_xor_register(int reg, int step){
    BYTE result = CPU::regs.byte[REG_A] ^ CPU::regs.byte[reg];
    CPU::regs.byte[REG_A] = result;

    bool flag_c = 0;
    bool flag_h = 1;
    bool flag_z = (BYTE)result == 0;
    bool flag_n = 0;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::bit_xor_hl(int step){
    switch (step) {
        case 0:
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] ^ MMU::read_memory(CPU::regs.word[REG_HL]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::bit_xor_immediate(int step){
    switch (step) {
        case 0:
            CPU::reg_special[PC] ++;
            return 1;
        case 1:{
            BYTE result = CPU::regs.byte[REG_A] ^ MMU::read_memory(CPU::reg_special[PC]);
            CPU::regs.byte[REG_A] = result;

            bool flag_c = 0;
            bool flag_h = 1;
            bool flag_z = (BYTE)result == 0;
            bool flag_n = 0;

            CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
                (flag_z ? FLAG_Z:0)|
                (flag_h ? FLAG_H:0)|
                (flag_n ? FLAG_N:0);

            CPU::reg_special[PC] ++;
            CPU::fetch();

            return 0;
        }
        default:
            return 0;
    }
    return 0;
}
int Instructions::complement_carry(int step){
    bool flag_c = !(CPU::regs.byte[REG_F] & FLAG_C);
    bool flag_h = 0;
    bool flag_z = CPU::regs.byte[REG_F] & FLAG_Z;
    bool flag_n = 0;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);
    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::set_carry(int step){
    bool flag_c = 1;
    bool flag_h = 0;
    bool flag_z = CPU::regs.byte[REG_F] & FLAG_Z;
    bool flag_n = 0;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);
    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::decimal_adjust_accumulator(int step){
    int result = CPU::regs.byte[REG_A];

    bool h = CPU::regs.byte[REG_F] & FLAG_H;
    bool c = CPU::regs.byte[REG_F] & FLAG_C;
    bool n = CPU::regs.byte[REG_F] & FLAG_N;
    
    int offset = 0;

    if ( (!n && ((result & 0xF)>0x09)) || h ) {
        offset |= 0x06; 

    } 
    if ( (!n && (result>0x99)) || c ) {
        offset |= 0x60; 
    }

    if (!n) {
        result += offset;
    }
    else{
        result -= offset;
    }

    CPU::regs.byte[REG_A] = (BYTE)result;

    bool flag_c = c || (result > 0x99);
    bool flag_h = 0;
    bool flag_z = (result == 0) ? 1:0;
    bool flag_n = CPU::regs.byte[REG_F] & FLAG_N;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);

    
    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::complement_accumulator(int step){
    CPU::regs.byte[REG_A] = ~CPU::regs.byte[REG_A];

    bool flag_c = CPU::regs.byte[REG_F] & FLAG_C;
    bool flag_h = 1;
    bool flag_z = CPU::regs.byte[REG_F] & FLAG_Z;
    bool flag_n = 1;

    CPU::regs.byte[REG_F] = (flag_c ? FLAG_C:0)|
        (flag_z ? FLAG_Z:0)|
        (flag_h ? FLAG_H:0)|
        (flag_n ? FLAG_N:0);

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}

//x16/alu
int Instructions::increment_register_16bit(int reg_16bit, int step){

    CPU::reg_special[PC] ++;
    CPU::fetch();
    return 0;
}
int Instructions::decrement_register_16bit(int reg_16bit, int step){
    return 0;
}
int Instructions::add_register_hl_16bit(int reg_16bit, int step){
    return 0;
}
int Instructions::add_stack_16bit(int step){
    return 0;
}

//x8/rsb
int Instructions::rotate_left_circular_accumulator(int step){
    return 0;
}
int Instructions::rotate_right_circular_accumulator(int step){
    return 0;
}
int Instructions::rotate_left_accumulator(int step){
    return 0;
}
int Instructions::rotate_right_accumulator(int step){
    return 0;
}
int Instructions::rotate_left_circular_register(int reg, int step){
    return 0;
}
int Instructions::rotate_left_circular_hl(int step){
    return 0;
}
int Instructions::rotate_right_circular_register(int reg, int step){
    return 0;
}
int Instructions::rotate_right_circular_hl(int step){
    return 0;
}
int Instructions::rotate_left_register(int reg, int step){
    return 0;
}
int Instructions::rotate_left_hl(int step){
    return 0;
}
int Instructions::rotate_right_register(int reg, int step){
    return 0;
}
int Instructions::rotate_right_hl(int step){
    return 0;
}
int Instructions::shift_left_register(int reg, int step){
    return 0;
}
int Instructions::shift_left_hl(int step){
    return 0;
}
int Instructions::shift_right_register(int reg, int step){
    return 0;
}
int Instructions::shift_right_hl(int step){
    return 0;
}
int Instructions::swap_nibbles_register(int reg, int step){
    return 0;
}
int Instructions::swap_nibbles_hl(int step){
    return 0;
}
int Instructions::shift_right_logical_register(int reg, int step){
    return 0;
}
int Instructions::shift_right_logical_hl(int step){
    return 0;
}
int Instructions::test_bit_register(int reg, int bit, int step){
    return 0;
}
int Instructions::test_bit_hl(int bit, int step){
    return 0;
}
int Instructions::reset_bit_register(int reg, int bit, int step){
    return 0;
}
int Instructions::reset_bit_hl(int bit, int step){
    return 0;
}
int Instructions::set_bit_register(int reg, int bit, int step){
    return 0;
}
int Instructions::set_bit_hl(int bit, int step){
    return 0;
}

//control/br
int Instructions::jump(int step){
    return 0;
}
int Instructions::jump_hl(int step){
    return 0;
}
int Instructions::jump_conditional(int condition, int step){
    return 0;
}
int Instructions::jump_relative(int step){
    return 0;
}
int Instructions::jump_relative_conditional(int condition, int step){
    return 0;
}
int Instructions::call(int step){
    return 0;
}
int Instructions::call_conditional(int condition, int step){
    return 0;
}
int Instructions::ret(int step){
    return 0;
}
int Instructions::ret_conditional(int condition, int step){
    return 0;
}
int Instructions::ret_interrupt(int step){
    return 0;
}
int Instructions::restart(WORD n, int step){
    return 0;
} //What?

//control/misc
int Instructions::halt(int step){
    return 0;
}
int Instructions::stop(int step){
    return 0;
}
int Instructions::disable_interrupts(int step){
    return 0;
}
int Instructions::enable_interrupts(int step){
    return 0;
}
int Instructions::nop(int step){
    return 0;
}
