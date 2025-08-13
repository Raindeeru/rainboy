#pragma once
#include "types.h"

//Conditions
#define Z 0
#define C 1
#define NZ 2
#define NC 3

namespace Instructions {
   //Functions for Decoding Opcodes
    int decode_execute(BYTE opcode, int step);
    
    int prefix_0xcb(BYTE opcode, int step);
    //Functions for Helping Do Instructions

    //x8/lsm
    int load_register(int reg, int reg_prime, int step);
    int load_register_immediate(int reg, int step);
    int load_register_hl(int reg, int step);
    int load_from_register_hl(int reg, int step);
    int load_hl_immediate(int step);
    int load_accumulator_bc(int step);
    int load_accumulator_de(int step);
    int load_from_accumulator_bc(int step);
    int load_from_accumulator_de(int step);
    int load_accumulator(int step);
    int load_from_accumulator(int step);
    int load_accumulator_c(int step);//This is Offsetted by 0xFF00
    int load_from_accumulator_c(int step);//This is Offsetted by 0xFF00
    int load_accumulator_offset(int step); //This is Offsetted by 0xFF00
    int load_from_accumulator_offset(int step); //This is Offsetted by 0xFF00
    int load_accumulator_hl_decrement(int step);
    int load_from_accumulator_hl_decrement(int step);
    int load_accumulator_hl_increment(int step);
    int load_from_accumulator_hl_increment(int step);
    
    //x16/lsm
    int load_register_immediate_16bit(int reg_16bit, int step);
    int load_from_stack(int step);
    int load_stack_hl(int step);
    int push(int reg_16bit, int step);
    int pop(int reg_16bit, int step);
    int load_hl_sp_plus_e(int step); //Wtf is this used for

    //x8/alu 
    int add_register(int reg, int step);
    int add_hl(int step);
    int add_immediate(int step);
    int add_with_carry_register(int reg, int step);
    int add_with_carry_hl(int step);
    int add_with_carry_immediate(int step);
    int sub_register(int reg, int step);
    int sub_hl(int step);
    int sub_immediate(int step);
    int sub_with_carry_register(int reg, int step);
    int sub_with_carry_hl(int step);
    int sub_with_carry_immediate(int step);
    int compare_register(int reg, int step);
    int compare_hl(int step);
    int compare_immediate(int step);
    int increment_register(int reg, int step);
    int increment_hl(int step);
    int decrement_register(int reg, int step);
    int decrement_hl(int step);
    int bit_and_register(int reg, int step);
    int bit_and_hl(int step);
    int bit_and_immediate(int step);
    int bit_or_register(int reg, int step);
    int bit_or_hl(int step);
    int bit_or_immediate(int step);
    int bit_xor_register(int reg, int step);
    int bit_xor_hl(int step);
    int bit_xor_immediate(int step);
    int complement_carry(int step);
    int set_carry(int step);
    int decimal_adjust_accumulator(int step);
    int complement_accumulator(int step);

    //x16/alu
    int increment_register_16bit(int reg_16bit, int step);
    int decrement_register_16bit(int reg_16bit, int step);
    int add_register_hl_16bit(int reg_16bit, int step);
    int add_stack_16bit(int step);

    //x8/rsb
    int rotate_left_circular_accumulator(int step);
    int rotate_right_circular_accumulator(int step);
    int rotate_left_accumulator(int step);
    int rotate_right_accumulator(int step);
    int rotate_left_circular_register(int reg, int step);
    int rotate_left_circular_hl(int step);
    int rotate_right_circular_register(int reg, int step);
    int rotate_right_circular_hl(int step);
    int rotate_left_register(int reg, int step);
    int rotate_left_hl(int step);
    int rotate_right_register(int reg, int step);
    int rotate_right_hl(int step);
    int shift_left_register(int reg, int step);
    int shift_left_hl(int step);
    int shift_right_register(int reg, int step);
    int shift_right_hl(int step);
    int swap_nibbles_register(int reg, int step);
    int swap_nibbles_hl(int step);
    int shift_right_logical_register(int reg, int step);
    int shift_right_logical_hl(int step);
    int test_bit_register(int reg, int bit, int step);
    int test_bit_hl(int bit, int step);
    int reset_bit_register(int reg, int bit, int step);
    int reset_bit_hl(int bit, int step);
    int set_bit_register(int reg, int bit, int step);
    int set_bit_hl(int bit, int step);

    //control/br
    int jump(int step);
    int jump_hl(int step);
    int jump_conditional(int condition, int step);
    int jump_relative(int step);
    int jump_relative_conditional(int condition, int step);
    int call(int step);
    int call_conditional(int condition, int step);
    int ret(int step);
    int ret_conditional(int condition, int step);
    int ret_interrupt(int step);
    int restart(WORD n, int step); //What?

    //control/misc
    int halt(int step);
    int stop(int step);
    int disable_interrupts(int step);
    int enable_interrupts(int step);
    int nop(int step);
}
