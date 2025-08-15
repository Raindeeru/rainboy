#include "common.h"

int Instructions::load_register(int reg, int reg_prime, int step){
    return 0;
}
int Instructions::load_register_immediate(int reg, int step){
    return 0;
}
int Instructions::load_register_hl(int reg, int step){
    return 0;
}
int Instructions::load_from_register_hl(int reg, int step){
    return 0;
}
int Instructions::load_hl_immediate(int step){
    return 0;
}
int Instructions::load_accumulator_bc(int step){
    return 0;
}
int Instructions::load_accumulator_de(int step){
    return 0;
}
int Instructions::load_from_accumulator_bc(int step){
    return 0;
}
int Instructions::load_from_accumulator_de(int step){
    return 0;
}
int Instructions::load_accumulator(int step){
    return 0;
}
int Instructions::load_from_accumulator(int step){
    return 0;
}
int Instructions::load_accumulator_c(int step){
    return 0;
}//This is Offsetted by 0xFF00
int Instructions::load_from_accumulator_c(int step){
    return 0;
}//This is Offsetted by 0xFF00
int Instructions::load_accumulator_offset(int step){
    return 0;
} //This is Offsetted by 0xFF00
int Instructions::load_from_accumulator_offset(int step){
    return 0;
} //This is Offsetted by 0xFF00
int Instructions::load_accumulator_hl_decrement(int step){
    return 0;
}
int Instructions::load_from_accumulator_hl_decrement(int step){
    return 0;
}
int Instructions::load_accumulator_hl_increment(int step){
    return 0;
}
int Instructions::load_from_accumulator_hl_increment(int step){
    return 0;
}
int Instructions::load_hl_sp_plus_e(int step){
    return 0;
} //Wtf is this used for

//x16/lsm
int Instructions::load_register_immediate_16bit(int reg_16bit, int step){
    return 0;
}
int Instructions::load_from_stack(int step){
    return 0;
}
int Instructions::load_stack_hl(int step){
    return 0;
}
int Instructions::push(int reg_16bit, int step){
    return 0;
}
int Instructions::pop(int reg_16bit, int step){
    return 0;
}
int load_hl_sp_plus_e(int step){
    return 0;
} //Wtf is this used for

//x8/alu 
int Instructions::add_register(int reg, int step){
    return 0;
}
int Instructions::add_hl(int step){
    return 0;
}
int Instructions::add_immediate(int step){
    return 0;
}
int Instructions::add_with_carry_register(int reg, int step){
    return 0;
}
int Instructions::add_with_carry_hl(int step){
    return 0;
}
int Instructions::add_with_carry_immediate(int step){
    return 0;
}
int Instructions::sub_register(int reg, int step){
    return 0;
}
int Instructions::sub_hl(int step){
    return 0;
}
int Instructions::sub_immediate(int step){
    return 0;
}
int Instructions::sub_with_carry_register(int reg, int step){
    return 0;
}
int Instructions::sub_with_carry_hl(int step){
    return 0;
}
int Instructions::sub_with_carry_immediate(int step){
    return 0;
}
int Instructions::compare_register(int reg, int step){
    return 0;
}
int Instructions::compare_hl(int step){
    return 0;
}
int Instructions::compare_immediate(int step){
    return 0;
}
int Instructions::increment_register(int reg, int step){
    return 0;
}
int Instructions::increment_hl(int step){
    return 0;
}
int Instructions::decrement_register(int reg, int step){
    return 0;
}
int Instructions::decrement_hl(int step){
    return 0;
}
int Instructions::bit_and_register(int reg, int step){
    return 0;
}
int Instructions::bit_and_hl(int step){
    return 0;
}
int Instructions::bit_and_immediate(int step){
    return 0;
}
int Instructions::bit_or_register(int reg, int step){
    return 0;
}
int Instructions::bit_or_hl(int step){
    return 0;
}
int Instructions::bit_or_immediate(int step){
    return 0;
}
int Instructions::bit_xor_register(int reg, int step){
    return 0;
}
int Instructions::bit_xor_hl(int step){
    return 0;
}
int Instructions::bit_xor_immediate(int step){
    return 0;
}
int Instructions::complement_carry(int step){
    return 0;
}
int Instructions::set_carry(int step){
    return 0;
}
int Instructions::decimal_adjust_accumulator(int step){
    return 0;
}
int Instructions::complement_accumulator(int step){
    return 0;
}

//x16/alu
int Instructions::increment_register_16bit(int reg_16bit, int step){
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
