#pragma once
#include "types.h"
namespace Instructions {
   //Functions for Decoding Opcodes
    int decode_execute(BYTE opcode);
    
    //Functions for Helping Do Instructions

    //x8/lsm
    int load_register(int reg);
    int load_register_immediate(int reg, BYTE data);
    int load_register_hl(int reg);
    int load_from_register_hl(int reg);
    int load_hl_immediate(BYTE data);
    int load_accumulator_bc();
    int load_accumulator_de();
    int load_from_accumulator_bc();
    int load_from_accumulator_de();
    int load_accumulator(WORD address);
    int load_from_accumulator(WORD address);
    int load_accumulator_c();//This is Offsetted by 0xFF00
    int load_from_accumulator_c();//This is Offsetted by 0xFF00
    int load_accumulator(BYTE address); //This is Offsetted by 0xFF00
    int load_from_accumulator(BYTE address); //This is Offsetted by 0xFF00
    int load_accumulator_hl_decrement();
    int load_from_accumulator_hl_decrement();
    int load_accumulator_hl_increment();
    int load_from_accumulator_hl_increment();
    
    //x16/lsm
    int load_register_immediate(int reg_16bit, WORD data);
    int load_from_stack(WORD address);
    int load_stack_hl();
    int push(int reg_16bit);
    int pop(int reg_16bit);
    int load_hl_sp_plus_e(SIGNED_BYTE e); //Wtf is this used for

    //x8/alu 
    int add_register(int reg);
    int add_hl();
    int add_immediate(BYTE data);
    int add_with_carry_register(int reg);
    int add_with_carry_hl();
    int add_with_carry_immediate(BYTE data);
    int sub_register(int reg);
    int sub_hl();
    int sub_immediate(BYTE data);
    int sub_with_carry_register(int reg);
    int sub_with_carry_hl();
    int sub_with_carry_immediate(BYTE data);
    int compare_register(int reg);
    int compare_hl();
    int compare_immediate(BYTE data);
    int increment_register(int reg);
    int increment_hl();
    int decrement_register(int reg);
    int decrement_hl();
    int bit_and_register(int reg);
    int bit_and_hl();
    int bit_and_immediate(BYTE data);
    int bit_or_register(int reg);
    int bit_or_hl();
    int bit_or_immediate(BYTE data);
    int bit_xor_register(int reg);
    int bit_xor_hl();
    int bit_xor_immediate(BYTE data);
    int complement_carry();
    int set_carry();
    int decimal_adjust_accumulator();
    int complement_accumulator();

    //x16/alu
    int increment_register_16bit(int reg_16bit);
    int decrement_register_16bit(int reg_16bit);
    int add_register_hl_16bit(int reg_16bit);
    int add_stack_16bit(SIGNED_BYTE e);

    //x8/rsb
    int rotate_left_circular_accumulator();
    int rotate_right_circular_accumulator();
    int rotate_left_accumulator();
    int rotate_right_accumulator();
    int rotate_left_circular_register(int reg);
    int rotate_left_circular_hl();
    int rotate_right_circular_register(int reg);
    int rotate_right_circular_hl();
    int rotate_left(int reg);
    int rotate_left_hl();
    int rotate_right(int reg);
    int rotate_right_hl();
    int shift_left_register(int reg);
    int shift_left_hl();
    int shift_right_register(int reg);
    int shift_right_hl();
    int swap_nibbles_register(int reg);
    int swap_nibbles_hl();
    int shift_right_logical_register(int reg);
    int shift_right_logical_hl();
    int test_bit_register(int reg, int bit);
    int test_bit_hl();
    int reset_bit_register(int reg, int bit);
    int reset_bit_hl();
    int set_bit_register(int reg, int bit);
    int set_bit_hl();

    //control/br
    int jump(WORD address);
    int jump_hl();
    int jump_conditional(WORD address, WORD condition);
    int jump_relative(BYTE e);
    int jump_relative_conditional(BYTE e, WORD condition);
    int call(WORD address);
    int ret();
    int ret_conditional(WORD condition);
    int ret_interrupt();
    int restart(BYTE n); //What?

    //control/misc
    int halt();
    int stop();
    int enable_interrupts();
    int nop();
}
