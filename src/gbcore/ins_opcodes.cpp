#include "instructions.h"
#include "cpu.h"
int Instructions::decode_execute(BYTE opcode, int step){
	switch(opcode){
		case 0x00:
			return nop(step);
		case 0x01:
			return load_register_immediate_16bit(REG_BC, step);
		case 0x02:
			return load_from_accumulator_bc(step);
		case 0x03:
			return increment_register_16bit(REG_BC, step);
		case 0x04:
			return increment_register(REG_B, step);
		case 0x05:
			return decrement_register(REG_B, step);
		case 0x06:
			return load_register_immediate(REG_B, step);
		case 0x07:
			return rotate_left_circular_accumulator(step);
		case 0x08:
			return load_from_stack(step);
		case 0x09:
			return add_register_hl_16bit(REG_BC, step);
		case 0x0a:
			return load_accumulator_bc(step);
		case 0x0b:
			return decrement_register_16bit(REG_BC, step);
		case 0x0c:
			return increment_register(REG_C, step);
		case 0x0d:
			return decrement_register(REG_C, step);
		case 0x0e:
			return load_register_immediate(REG_C, step);
		case 0x0f:
			return rotate_right_circular_accumulator(step);
		case 0x10:
			return stop(step);
		case 0x11:
			return load_register_immediate_16bit(REG_DE, step);
		case 0x12:
			return load_from_accumulator_de(step);
		case 0x13:
			return increment_register_16bit(REG_DE, step);
		case 0x14:
			return increment_register(REG_D, step);
		case 0x15:
			return decrement_register(REG_D, step);
		case 0x16:
			return load_register_immediate(REG_D, step);
		case 0x17:
			return rotate_left_accumulator(step);
		case 0x18:
			return jump_relative(step);
		case 0x19:
			return add_register_hl_16bit(REG_DE, step);
		case 0x1a:
			return load_accumulator_de(step);
		case 0x1b:
			return decrement_register_16bit(REG_DE, step);
		case 0x1c:
			return increment_register(REG_E, step);
		case 0x1d:
			return decrement_register(REG_E, step);
		case 0x1e:
			return load_register_immediate(REG_E, step);
		case 0x1f:
			return rotate_right_accumulator(step);
		case 0x20:
			return jump_relative_conditional(CONDITION_NZ, step);
		case 0x21:
			return load_register_immediate_16bit(REG_HL, step);
		case 0x22:
			return load_from_accumulator_hl_increment(step);
		case 0x23:
			return increment_register_16bit(REG_HL, step);
		case 0x24:
			return increment_register(REG_H, step);
		case 0x25:
			return decrement_register(REG_H, step);
		case 0x26:
			return load_register_immediate(REG_H, step);
		case 0x27:
			return decimal_adjust_accumulator(step);
		case 0x28:
			return jump_relative_conditional(CONDITION_Z, step);
		case 0x29:
			return add_register_hl_16bit(REG_HL, step);
		case 0x2a:
			return load_accumulator_hl_increment(step);
		case 0x2b:
			return decrement_register_16bit(REG_HL, step);
		case 0x2c:
			return increment_register(REG_L, step);
		case 0x2d:
			return decrement_register(REG_L, step);
		case 0x2e:
			return load_register_immediate(REG_L, step);
		case 0x2f:
			return complement_accumulator(step);
		case 0x30:
			return jump_relative_conditional(CONDITION_NC, step);
		case 0x31:
			return load_register_immediate_16bit(SP, step);
		case 0x32:
			return load_from_accumulator_hl_decrement(step);
		case 0x33:
			return increment_register_16bit(SP, step);
		case 0x34:
			return increment_hl(step);
		case 0x35:
			return decrement_hl(step);
		case 0x36:
			return load_hl_immediate(step);
		case 0x37:
			return set_carry(step);
		case 0x38:
			return jump_relative_conditional(CONDITION_C, step);
		case 0x39:
			return add_register_hl_16bit(SP, step);
		case 0x3a:
			return load_accumulator_hl_decrement(step);
		case 0x3b:
			return decrement_register_16bit(SP, step);
		case 0x3c:
			return increment_register(REG_A, step);
		case 0x3d:
			return decrement_register(REG_A, step);
		case 0x3e:
			return load_register_immediate(REG_A, step);
		case 0x3f:
			return complement_carry(step);
		case 0x40:
			return load_register(REG_B, REG_B, step);
		case 0x41:
			return load_register(REG_B, REG_C, step);
		case 0x42:
			return load_register(REG_B, REG_D, step);
		case 0x43:
			return load_register(REG_B, REG_E, step);
		case 0x44:
			return load_register(REG_B, REG_H, step);
		case 0x45:
			return load_register(REG_B, REG_L, step);
		case 0x46:
			return load_register_hl(REG_B, step);
		case 0x47:
			return load_register(REG_B, REG_A, step);
		case 0x48:
			return load_register(REG_C, REG_B, step);
		case 0x49:
			return load_register(REG_C, REG_C, step);
		case 0x4a:
			return load_register(REG_C, REG_D, step);
		case 0x4b:
			return load_register(REG_C, REG_E, step);
		case 0x4c:
			return load_register(REG_C, REG_H, step);
		case 0x4d:
			return load_register(REG_C, REG_L, step);
		case 0x4e:
			return load_register_hl(REG_C, step);
		case 0x4f:
			return load_register(REG_C, REG_A, step);
		case 0x50:
			return load_register(REG_D, REG_B, step);
		case 0x51:
			return load_register(REG_D, REG_C, step);
		case 0x52:
			return load_register(REG_D, REG_D, step);
		case 0x53:
			return load_register(REG_D, REG_E, step);
		case 0x54:
			return load_register(REG_D, REG_H, step);
		case 0x55:
			return load_register(REG_D, REG_L, step);
		case 0x56:
			return load_register_hl(REG_D, step);
		case 0x57:
			return load_register(REG_D, REG_A, step);
		case 0x58:
			return load_register(REG_E, REG_B, step);
		case 0x59:
			return load_register(REG_E, REG_C, step);
		case 0x5a:
			return load_register(REG_E, REG_D, step);
		case 0x5b:
			return load_register(REG_E, REG_E, step);
		case 0x5c:
			return load_register(REG_E, REG_H, step);
		case 0x5d:
			return load_register(REG_E, REG_L, step);
		case 0x5e:
			return load_register_hl(REG_E, step);
		case 0x5f:
			return load_register(REG_E, REG_A, step);
		case 0x60:
			return load_register(REG_H, REG_B, step);
		case 0x61:
			return load_register(REG_H, REG_C, step);
		case 0x62:
			return load_register(REG_H, REG_D, step);
		case 0x63:
			return load_register(REG_H, REG_E, step);
		case 0x64:
			return load_register(REG_H, REG_H, step);
		case 0x65:
			return load_register(REG_H, REG_L, step);
		case 0x66:
			return load_register_hl(REG_H, step);
		case 0x67:
			return load_register(REG_H, REG_A, step);
		case 0x68:
			return load_register(REG_L, REG_B, step);
		case 0x69:
			return load_register(REG_L, REG_C, step);
		case 0x6a:
			return load_register(REG_L, REG_D, step);
		case 0x6b:
			return load_register(REG_L, REG_E, step);
		case 0x6c:
			return load_register(REG_L, REG_H, step);
		case 0x6d:
			return load_register(REG_L, REG_L, step);
		case 0x6e:
			return load_register_hl(REG_L, step);
		case 0x6f:
			return load_register(REG_L, REG_A, step);
		case 0x70:
			return load_from_register_hl(REG_B, step);
		case 0x71:
			return load_from_register_hl(REG_C, step);
		case 0x72:
			return load_from_register_hl(REG_D, step);
		case 0x73:
			return load_from_register_hl(REG_E, step);
		case 0x74:
			return load_from_register_hl(REG_H, step);
		case 0x75:
			return load_from_register_hl(REG_L, step);
		case 0x76:
			return halt(step);
		case 0x77:
			return load_from_register_hl(REG_A, step);
		case 0x78:
			return load_register(REG_A, REG_B, step);
		case 0x79:
			return load_register(REG_A, REG_C, step);
		case 0x7a:
			return load_register(REG_A, REG_D, step);
		case 0x7b:
			return load_register(REG_A, REG_E, step);
		case 0x7c:
			return load_register(REG_A, REG_H, step);
		case 0x7d:
			return load_register(REG_A, REG_L, step);
		case 0x7e:
			return load_register_hl(REG_A, step);
		case 0x7f:
			return load_register(REG_A, REG_A, step);
		case 0x80:
			return add_register(REG_B, step);
		case 0x81:
			return add_register(REG_C, step);
		case 0x82:
			return add_register(REG_D, step);
		case 0x83:
			return add_register(REG_E, step);
		case 0x84:
			return add_register(REG_H, step);
		case 0x85:
			return add_register(REG_L, step);
		case 0x86:
			return add_hl(step);
		case 0x87:
			return add_register(REG_A, step);
		case 0x88:
			return add_with_carry_register(REG_B, step);
		case 0x89:
			return add_with_carry_register(REG_C, step);
		case 0x8a:
			return add_with_carry_register(REG_D, step);
		case 0x8b:
			return add_with_carry_register(REG_E, step);
		case 0x8c:
			return add_with_carry_register(REG_H, step);
		case 0x8d:
			return add_with_carry_register(REG_L, step);
		case 0x8e:
			return add_with_carry_hl(step);
		case 0x8f:
			return add_with_carry_register(REG_A, step);
		case 0x90:
			return sub_register(REG_B, step);
		case 0x91:
			return sub_register(REG_C, step);
		case 0x92:
			return sub_register(REG_D, step);
		case 0x93:
			return sub_register(REG_E, step);
		case 0x94:
			return sub_register(REG_H, step);
		case 0x95:
			return sub_register(REG_L, step);
		case 0x96:
			return sub_hl(step);
		case 0x97:
			return sub_register(REG_A, step);
		case 0x98:
			return sub_with_carry_register(REG_B, step);
		case 0x99:
			return sub_with_carry_register(REG_C, step);
		case 0x9a:
			return sub_with_carry_register(REG_D, step);
		case 0x9b:
			return sub_with_carry_register(REG_E, step);
		case 0x9c:
			return sub_with_carry_register(REG_H, step);
		case 0x9d:
			return sub_with_carry_register(REG_L, step);
		case 0x9e:
			return sub_with_carry_hl(step);
		case 0x9f:
			return sub_with_carry_register(REG_A, step);
		case 0xa0:
			return bit_and_register(REG_B, step);
		case 0xa1:
			return bit_and_register(REG_C, step);
		case 0xa2:
			return bit_and_register(REG_D, step);
		case 0xa3:
			return bit_and_register(REG_E, step);
		case 0xa4:
			return bit_and_register(REG_H, step);
		case 0xa5:
			return bit_and_register(REG_L, step);
		case 0xa6:
			return bit_and_hl(step);
		case 0xa7:
			return bit_and_register(REG_A, step);
		case 0xa8:
			return bit_xor_register(REG_B, step);
		case 0xa9:
			return bit_xor_register(REG_C, step);
		case 0xaa:
			return bit_xor_register(REG_D, step);
		case 0xab:
			return bit_xor_register(REG_E, step);
		case 0xac:
			return bit_xor_register(REG_H, step);
		case 0xad:
			return bit_xor_register(REG_L, step);
		case 0xae:
			return bit_xor_hl(step);
		case 0xaf:
			return bit_xor_register(REG_A, step);
		case 0xb0:
			return bit_or_register(REG_B, step);
		case 0xb1:
			return bit_or_register(REG_C, step);
		case 0xb2:
			return bit_or_register(REG_D, step);
		case 0xb3:
			return bit_or_register(REG_E, step);
		case 0xb4:
			return bit_or_register(REG_H, step);
		case 0xb5:
			return bit_or_register(REG_L, step);
		case 0xb6:
			return bit_or_hl(step);
		case 0xb7:
			return bit_or_register(REG_A, step);
		case 0xb8:
			return compare_register(REG_B, step);
		case 0xb9:
			return compare_register(REG_C, step);
		case 0xba:
			return compare_register(REG_D, step);
		case 0xbb:
			return compare_register(REG_E, step);
		case 0xbc:
			return compare_register(REG_H, step);
		case 0xbd:
			return compare_register(REG_L, step);
		case 0xbe:
			return compare_hl(step);
		case 0xbf:
			return compare_register(REG_A, step);
		case 0xc0:
			return ret_conditional(CONDITION_NZ, step);
		case 0xc1:
			return pop(REG_BC, step);
		case 0xc2:
			return jump_conditional(CONDITION_NZ, step);
		case 0xc3:
			return jump(step);
		case 0xc4:
			return call_conditional(CONDITION_NZ, step);
		case 0xc5:
			return push(REG_BC, step);
		case 0xc6:
			return add_immediate(step);
		case 0xc7:
			return restart(0, step);
		case 0xc8:
			return ret_conditional(CONDITION_Z, step);
		case 0xc9:
			return ret(step);
		case 0xca:
			return jump_conditional(CONDITION_Z, step);
		case 0xcb:
			return prefix_0xcb(opcode, step);
		case 0xcc:
			return call_conditional(CONDITION_Z, step);
		case 0xcd:
			return call(step);
		case 0xce:
			return add_with_carry_immediate(step);
		case 0xcf:
			return restart(8, step);
		case 0xd0:
			return ret_conditional(CONDITION_NC, step);
		case 0xd1:
			return pop(REG_DE, step);
		case 0xd2:
			return jump_conditional(CONDITION_NC, step);
		case 0xd4:
			return call_conditional(CONDITION_NC, step);
		case 0xd5:
			return push(REG_DE, step);
		case 0xd6:
			return sub_immediate(step);
		case 0xd7:
			return restart(16, step);
		case 0xd8:
			return ret_conditional(CONDITION_C, step);
		case 0xd9:
			return ret_interrupt(step);
		case 0xda:
			return jump_conditional(CONDITION_C, step);
		case 0xdc:
			return call_conditional(CONDITION_C, step);
		case 0xde:
			return sub_with_carry_immediate(step);
		case 0xdf:
			return restart(24, step);
		case 0xe0:
			return load_from_accumulator_offset(step);
		case 0xe1:
			return pop(REG_HL, step);
		case 0xe2:
			return load_from_accumulator_c(step);
		case 0xe5:
			return push(REG_HL, step);
		case 0xe6:
			return bit_and_immediate(step);
		case 0xe7:
			return restart(32, step);
		case 0xe8:
			return add_stack_16bit(step);
		case 0xe9:
			return jump_hl(step);
		case 0xea:
			return load_from_accumulator(step);
		case 0xee:
			return bit_xor_immediate(step);
		case 0xef:
			return restart(40, step);
		case 0xf0:
			return load_accumulator_offset(step);
		case 0xf1:
			return pop(REG_AF, step);
		case 0xf2:
			return load_accumulator_c(step);
		case 0xf3:
			return disable_interrupts(step);
		case 0xf5:
			return push(REG_AF, step);
		case 0xf6:
			return bit_or_immediate(step);
		case 0xf7:
			return restart(48, step);
		case 0xf8:
			return load_hl_sp_plus_e(step);
		case 0xf9:
			return load_from_stack(step);
		case 0xfa:
			return load_accumulator(step);
		case 0xfb:
			return enable_interrupts(step);
		case 0xfe:
			return compare_immediate(step);
		case 0xff:
			return restart(56, step);
		default:
			return 0;
	}
}

int Instructions::prefix_0xcb(BYTE opcode, int step){
	switch(opcode){
		case 0x00:
			return rotate_left_circular_register(REG_B, step);
		case 0x01:
			return rotate_left_circular_register(REG_C, step);
		case 0x02:
			return rotate_left_circular_register(REG_D, step);
		case 0x03:
			return rotate_left_circular_register(REG_E, step);
		case 0x04:
			return rotate_left_circular_register(REG_H, step);
		case 0x05:
			return rotate_left_circular_register(REG_L, step);
		case 0x06:
			return rotate_left_circular_hl(step);
		case 0x07:
			return rotate_left_circular_register(REG_A, step);
		case 0x08:
			return rotate_right_circular_register(REG_B, step);
		case 0x09:
			return rotate_right_circular_register(REG_C, step);
		case 0x0a:
			return rotate_right_circular_register(REG_D, step);
		case 0x0b:
			return rotate_right_circular_register(REG_E, step);
		case 0x0c:
			return rotate_right_circular_register(REG_H, step);
		case 0x0d:
			return rotate_right_circular_register(REG_L, step);
		case 0x0e:
			return rotate_right_circular_hl(step);
		case 0x0f:
			return rotate_right_circular_register(REG_A, step);
		case 0x10:
			return rotate_left_register(REG_B, step);
		case 0x11:
			return rotate_left_register(REG_C, step);
		case 0x12:
			return rotate_left_register(REG_D, step);
		case 0x13:
			return rotate_left_register(REG_E, step);
		case 0x14:
			return rotate_left_register(REG_H, step);
		case 0x15:
			return rotate_left_register(REG_L, step);
		case 0x16:
			return rotate_left_hl(step);
		case 0x17:
			return rotate_left_register(REG_A, step);
		case 0x18:
			return rotate_right_register(REG_B, step);
		case 0x19:
			return rotate_right_register(REG_C, step);
		case 0x1a:
			return rotate_right_register(REG_D, step);
		case 0x1b:
			return rotate_right_register(REG_E, step);
		case 0x1c:
			return rotate_right_register(REG_H, step);
		case 0x1d:
			return rotate_right_register(REG_L, step);
		case 0x1e:
			return rotate_right_hl(step);
		case 0x1f:
			return rotate_right_register(REG_A, step);
		case 0x20:
			return shift_left_register(REG_B, step);
		case 0x21:
			return shift_left_register(REG_C, step);
		case 0x22:
			return shift_left_register(REG_D, step);
		case 0x23:
			return shift_left_register(REG_E, step);
		case 0x24:
			return shift_left_register(REG_H, step);
		case 0x25:
			return shift_left_register(REG_L, step);
		case 0x26:
			return shift_left_hl(step);
		case 0x27:
			return shift_left_register(REG_A, step);
		case 0x28:
			return shift_right_register(REG_B, step);
		case 0x29:
			return shift_right_register(REG_C, step);
		case 0x2a:
			return shift_right_register(REG_D, step);
		case 0x2b:
			return shift_right_register(REG_E, step);
		case 0x2c:
			return shift_right_register(REG_H, step);
		case 0x2d:
			return shift_right_register(REG_L, step);
		case 0x2e:
			return shift_right_hl(step);
		case 0x2f:
			return shift_right_register(REG_A, step);
		case 0x30:
			return swap_nibbles_register(REG_B, step);
		case 0x31:
			return swap_nibbles_register(REG_C, step);
		case 0x32:
			return swap_nibbles_register(REG_D, step);
		case 0x33:
			return swap_nibbles_register(REG_E, step);
		case 0x34:
			return swap_nibbles_register(REG_H, step);
		case 0x35:
			return swap_nibbles_register(REG_L, step);
		case 0x36:
			return swap_nibbles_hl(step);
		case 0x37:
			return swap_nibbles_register(REG_A, step);
		case 0x38:
			return shift_right_logical_register(REG_B, step);
		case 0x39:
			return shift_right_logical_register(REG_C, step);
		case 0x3a:
			return shift_right_logical_register(REG_D, step);
		case 0x3b:
			return shift_right_logical_register(REG_E, step);
		case 0x3c:
			return shift_right_logical_register(REG_H, step);
		case 0x3d:
			return shift_right_logical_register(REG_L, step);
		case 0x3e:
			return shift_right_logical_hl(step);
		case 0x3f:
			return shift_right_logical_register(REG_A, step);
		case 0x40:
			return test_bit_register(0,REG_B, step);
		case 0x41:
			return test_bit_register(0,REG_C, step);
		case 0x42:
			return test_bit_register(0,REG_D, step);
		case 0x43:
			return test_bit_register(0,REG_E, step);
		case 0x44:
			return test_bit_register(0,REG_H, step);
		case 0x45:
			return test_bit_register(0,REG_L, step);
		case 0x46:
			return test_bit_hl(0, step);
		case 0x47:
			return test_bit_register(0,REG_A, step);
		case 0x48:
			return test_bit_register(1,REG_B, step);
		case 0x49:
			return test_bit_register(1,REG_C, step);
		case 0x4a:
			return test_bit_register(1,REG_D, step);
		case 0x4b:
			return test_bit_register(1,REG_E, step);
		case 0x4c:
			return test_bit_register(1,REG_H, step);
		case 0x4d:
			return test_bit_register(1,REG_L, step);
		case 0x4e:
			return test_bit_hl(1, step);
		case 0x4f:
			return test_bit_register(1,REG_A, step);
		case 0x50:
			return test_bit_register(2,REG_B, step);
		case 0x51:
			return test_bit_register(2,REG_C, step);
		case 0x52:
			return test_bit_register(2,REG_D, step);
		case 0x53:
			return test_bit_register(2,REG_E, step);
		case 0x54:
			return test_bit_register(2,REG_H, step);
		case 0x55:
			return test_bit_register(2,REG_L, step);
		case 0x56:
			return test_bit_hl(2, step);
		case 0x57:
			return test_bit_register(2,REG_A, step);
		case 0x58:
			return test_bit_register(3,REG_B, step);
		case 0x59:
			return test_bit_register(3,REG_C, step);
		case 0x5a:
			return test_bit_register(3,REG_D, step);
		case 0x5b:
			return test_bit_register(3,REG_E, step);
		case 0x5c:
			return test_bit_register(3,REG_H, step);
		case 0x5d:
			return test_bit_register(3,REG_L, step);
		case 0x5e:
			return test_bit_hl(3, step);
		case 0x5f:
			return test_bit_register(3,REG_A, step);
		case 0x60:
			return test_bit_register(4,REG_B, step);
		case 0x61:
			return test_bit_register(4,REG_C, step);
		case 0x62:
			return test_bit_register(4,REG_D, step);
		case 0x63:
			return test_bit_register(4,REG_E, step);
		case 0x64:
			return test_bit_register(4,REG_H, step);
		case 0x65:
			return test_bit_register(4,REG_L, step);
		case 0x66:
			return test_bit_hl(4, step);
		case 0x67:
			return test_bit_register(4,REG_A, step);
		case 0x68:
			return test_bit_register(5,REG_B, step);
		case 0x69:
			return test_bit_register(5,REG_C, step);
		case 0x6a:
			return test_bit_register(5,REG_D, step);
		case 0x6b:
			return test_bit_register(5,REG_E, step);
		case 0x6c:
			return test_bit_register(5,REG_H, step);
		case 0x6d:
			return test_bit_register(5,REG_L, step);
		case 0x6e:
			return test_bit_hl(5, step);
		case 0x6f:
			return test_bit_register(5,REG_A, step);
		case 0x70:
			return test_bit_register(6,REG_B, step);
		case 0x71:
			return test_bit_register(6,REG_C, step);
		case 0x72:
			return test_bit_register(6,REG_D, step);
		case 0x73:
			return test_bit_register(6,REG_E, step);
		case 0x74:
			return test_bit_register(6,REG_H, step);
		case 0x75:
			return test_bit_register(6,REG_L, step);
		case 0x76:
			return test_bit_hl(6, step);
		case 0x77:
			return test_bit_register(6,REG_A, step);
		case 0x78:
			return test_bit_register(7,REG_B, step);
		case 0x79:
			return test_bit_register(7,REG_C, step);
		case 0x7a:
			return test_bit_register(7,REG_D, step);
		case 0x7b:
			return test_bit_register(7,REG_E, step);
		case 0x7c:
			return test_bit_register(7,REG_H, step);
		case 0x7d:
			return test_bit_register(7,REG_L, step);
		case 0x7e:
			return test_bit_hl(7, step);
		case 0x7f:
			return test_bit_register(7,REG_A, step);
		case 0x80:
			return reset_bit_register(0,REG_B, step);
		case 0x81:
			return reset_bit_register(0,REG_C, step);
		case 0x82:
			return reset_bit_register(0,REG_D, step);
		case 0x83:
			return reset_bit_register(0,REG_E, step);
		case 0x84:
			return reset_bit_register(0,REG_H, step);
		case 0x85:
			return reset_bit_register(0,REG_L, step);
		case 0x86:
			return reset_bit_hl(0, step);
		case 0x87:
			return reset_bit_register(0,REG_A, step);
		case 0x88:
			return reset_bit_register(1,REG_B, step);
		case 0x89:
			return reset_bit_register(1,REG_C, step);
		case 0x8a:
			return reset_bit_register(1,REG_D, step);
		case 0x8b:
			return reset_bit_register(1,REG_E, step);
		case 0x8c:
			return reset_bit_register(1,REG_H, step);
		case 0x8d:
			return reset_bit_register(1,REG_L, step);
		case 0x8e:
			return reset_bit_hl(1, step);
		case 0x8f:
			return reset_bit_register(1,REG_A, step);
		case 0x90:
			return reset_bit_register(2,REG_B, step);
		case 0x91:
			return reset_bit_register(2,REG_C, step);
		case 0x92:
			return reset_bit_register(2,REG_D, step);
		case 0x93:
			return reset_bit_register(2,REG_E, step);
		case 0x94:
			return reset_bit_register(2,REG_H, step);
		case 0x95:
			return reset_bit_register(2,REG_L, step);
		case 0x96:
			return reset_bit_hl(2, step);
		case 0x97:
			return reset_bit_register(2,REG_A, step);
		case 0x98:
			return reset_bit_register(3,REG_B, step);
		case 0x99:
			return reset_bit_register(3,REG_C, step);
		case 0x9a:
			return reset_bit_register(3,REG_D, step);
		case 0x9b:
			return reset_bit_register(3,REG_E, step);
		case 0x9c:
			return reset_bit_register(3,REG_H, step);
		case 0x9d:
			return reset_bit_register(3,REG_L, step);
		case 0x9e:
			return reset_bit_hl(3, step);
		case 0x9f:
			return reset_bit_register(3,REG_A, step);
		case 0xa0:
			return reset_bit_register(4,REG_B, step);
		case 0xa1:
			return reset_bit_register(4,REG_C, step);
		case 0xa2:
			return reset_bit_register(4,REG_D, step);
		case 0xa3:
			return reset_bit_register(4,REG_E, step);
		case 0xa4:
			return reset_bit_register(4,REG_H, step);
		case 0xa5:
			return reset_bit_register(4,REG_L, step);
		case 0xa6:
			return reset_bit_hl(4, step);
		case 0xa7:
			return reset_bit_register(4,REG_A, step);
		case 0xa8:
			return reset_bit_register(5,REG_B, step);
		case 0xa9:
			return reset_bit_register(5,REG_C, step);
		case 0xaa:
			return reset_bit_register(5,REG_D, step);
		case 0xab:
			return reset_bit_register(5,REG_E, step);
		case 0xac:
			return reset_bit_register(5,REG_H, step);
		case 0xad:
			return reset_bit_register(5,REG_L, step);
		case 0xae:
			return reset_bit_hl(5, step);
		case 0xaf:
			return reset_bit_register(5,REG_A, step);
		case 0xb0:
			return reset_bit_register(6,REG_B, step);
		case 0xb1:
			return reset_bit_register(6,REG_C, step);
		case 0xb2:
			return reset_bit_register(6,REG_D, step);
		case 0xb3:
			return reset_bit_register(6,REG_E, step);
		case 0xb4:
			return reset_bit_register(6,REG_H, step);
		case 0xb5:
			return reset_bit_register(6,REG_L, step);
		case 0xb6:
			return reset_bit_hl(6, step);
		case 0xb7:
			return reset_bit_register(6,REG_A, step);
		case 0xb8:
			return reset_bit_register(7,REG_B, step);
		case 0xb9:
			return reset_bit_register(7,REG_C, step);
		case 0xba:
			return reset_bit_register(7,REG_D, step);
		case 0xbb:
			return reset_bit_register(7,REG_E, step);
		case 0xbc:
			return reset_bit_register(7,REG_H, step);
		case 0xbd:
			return reset_bit_register(7,REG_L, step);
		case 0xbe:
			return reset_bit_hl(7, step);
		case 0xbf:
			return reset_bit_register(7,REG_A, step);
		case 0xc0:
			return set_bit_register(0,REG_B, step);
		case 0xc1:
			return set_bit_register(0,REG_C, step);
		case 0xc2:
			return set_bit_register(0,REG_D, step);
		case 0xc3:
			return set_bit_register(0,REG_E, step);
		case 0xc4:
			return set_bit_register(0,REG_H, step);
		case 0xc5:
			return set_bit_register(0,REG_L, step);
		case 0xc6:
			return set_bit_hl(0, step);
		case 0xc7:
			return set_bit_register(0,REG_A, step);
		case 0xc8:
			return set_bit_register(1,REG_B, step);
		case 0xc9:
			return set_bit_register(1,REG_C, step);
		case 0xca:
			return set_bit_register(1,REG_D, step);
		case 0xcb:
			return set_bit_register(1,REG_E, step);
		case 0xcc:
			return set_bit_register(1,REG_H, step);
		case 0xcd:
			return set_bit_register(1,REG_L, step);
		case 0xce:
			return set_bit_hl(1, step);
		case 0xcf:
			return set_bit_register(1,REG_A, step);
		case 0xd0:
			return set_bit_register(2,REG_B, step);
		case 0xd1:
			return set_bit_register(2,REG_C, step);
		case 0xd2:
			return set_bit_register(2,REG_D, step);
		case 0xd3:
			return set_bit_register(2,REG_E, step);
		case 0xd4:
			return set_bit_register(2,REG_H, step);
		case 0xd5:
			return set_bit_register(2,REG_L, step);
		case 0xd6:
			return set_bit_hl(2, step);
		case 0xd7:
			return set_bit_register(2,REG_A, step);
		case 0xd8:
			return set_bit_register(3,REG_B, step);
		case 0xd9:
			return set_bit_register(3,REG_C, step);
		case 0xda:
			return set_bit_register(3,REG_D, step);
		case 0xdb:
			return set_bit_register(3,REG_E, step);
		case 0xdc:
			return set_bit_register(3,REG_H, step);
		case 0xdd:
			return set_bit_register(3,REG_L, step);
		case 0xde:
			return set_bit_hl(3, step);
		case 0xdf:
			return set_bit_register(3,REG_A, step);
		case 0xe0:
			return set_bit_register(4,REG_B, step);
		case 0xe1:
			return set_bit_register(4,REG_C, step);
		case 0xe2:
			return set_bit_register(4,REG_D, step);
		case 0xe3:
			return set_bit_register(4,REG_E, step);
		case 0xe4:
			return set_bit_register(4,REG_H, step);
		case 0xe5:
			return set_bit_register(4,REG_L, step);
		case 0xe6:
			return set_bit_hl(4, step);
		case 0xe7:
			return set_bit_register(4,REG_A, step);
		case 0xe8:
			return set_bit_register(5,REG_B, step);
		case 0xe9:
			return set_bit_register(5,REG_C, step);
		case 0xea:
			return set_bit_register(5,REG_D, step);
		case 0xeb:
			return set_bit_register(5,REG_E, step);
		case 0xec:
			return set_bit_register(5,REG_H, step);
		case 0xed:
			return set_bit_register(5,REG_L, step);
		case 0xee:
			return set_bit_hl(5, step);
		case 0xef:
			return set_bit_register(5,REG_A, step);
		case 0xf0:
			return set_bit_register(6,REG_B, step);
		case 0xf1:
			return set_bit_register(6,REG_C, step);
		case 0xf2:
			return set_bit_register(6,REG_D, step);
		case 0xf3:
			return set_bit_register(6,REG_E, step);
		case 0xf4:
			return set_bit_register(6,REG_H, step);
		case 0xf5:
			return set_bit_register(6,REG_L, step);
		case 0xf6:
			return set_bit_hl(6, step);
		case 0xf7:
			return set_bit_register(6,REG_A, step);
		case 0xf8:
			return set_bit_register(7,REG_B, step);
		case 0xf9:
			return set_bit_register(7,REG_C, step);
		case 0xfa:
			return set_bit_register(7,REG_D, step);
		case 0xfb:
			return set_bit_register(7,REG_E, step);
		case 0xfc:
			return set_bit_register(7,REG_H, step);
		case 0xfd:
			return set_bit_register(7,REG_L, step);
		case 0xfe:
			return set_bit_hl(7, step);
		case 0xff:
			return set_bit_register(7,REG_A, step);
		default:
			return 0;
	}
}
