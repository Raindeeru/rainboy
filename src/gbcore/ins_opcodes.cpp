#include "common.h"

int Instructions::decode_execute(BYTE opcode, int step){
	switch(opcode){
		case 0x00:
			return nop(step);
		case 0x01:
			return load_register_immediate_16bit(BC, step);
		case 0x02:
			return load_from_accumulator_bc(step);
		case 0x03:
			return increment_register_16bit(BC, step);
		case 0x04:
			return increment_register(B, step);
		case 0x05:
			return decrement_register(B, step);
		case 0x06:
			return load_register_immediate(B, step);
		case 0x07:
			return rotate_left_circular_accumulator(step);
		case 0x08:
			return load_from_stack(step);
		case 0x09:
			return add_register_hl_16bit(BC, step);
		case 0x0a:
			return load_accumulator_bc(step);
		case 0x0b:
			return decrement_register_16bit(BC, step);
		case 0x0c:
			return increment_register(C, step);
		case 0x0d:
			return decrement_register(C, step);
		case 0x0e:
			return load_register_immediate(C, step);
		case 0x0f:
			return rotate_right_circular_accumulator(step);
		case 0x10:
			return stop(step);
		case 0x11:
			return load_register_immediate_16bit(DE, step);
		case 0x12:
			return load_from_accumulator_de(step);
		case 0x13:
			return increment_register_16bit(DE, step);
		case 0x14:
			return increment_register(D, step);
		case 0x15:
			return decrement_register(D, step);
		case 0x16:
			return load_register_immediate(D, step);
		case 0x17:
			return rotate_left_accumulator(step);
		case 0x18:
			return jump_relative(step);
		case 0x19:
			return add_register_hl_16bit(DE, step);
		case 0x1a:
			return load_accumulator_de(step);
		case 0x1b:
			return decrement_register_16bit(DE, step);
		case 0x1c:
			return increment_register(E, step);
		case 0x1d:
			return decrement_register(E, step);
		case 0x1e:
			return load_register_immediate(E, step);
		case 0x1f:
			return rotate_right_accumulator(step);
		case 0x20:
			return jump_relative_conditional(NZ, step);
		case 0x21:
			return load_register_immediate_16bit(HL, step);
		case 0x22:
			return load_from_accumulator_hl_increment(step);
		case 0x23:
			return increment_register_16bit(HL, step);
		case 0x24:
			return increment_register(H, step);
		case 0x25:
			return decrement_register(H, step);
		case 0x26:
			return load_register_immediate(H, step);
		case 0x27:
			return decimal_adjust_accumulator(step);
		case 0x28:
			return jump_relative_conditional(Z, step);
		case 0x29:
			return add_register_hl_16bit(HL, step);
		case 0x2a:
			return load_accumulator_hl_increment(step);
		case 0x2b:
			return decrement_register_16bit(HL, step);
		case 0x2c:
			return increment_register(L, step);
		case 0x2d:
			return decrement_register(L, step);
		case 0x2e:
			return load_register_immediate(L, step);
		case 0x2f:
			return complement_accumulator(step);
		case 0x30:
			return jump_relative_conditional(NC, step);
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
			return jump_relative_conditional(C, step);
		case 0x39:
			return add_register_hl_16bit(SP, step);
		case 0x3a:
			return load_accumulator_hl_decrement(step);
		case 0x3b:
			return decrement_register_16bit(SP, step);
		case 0x3c:
			return increment_register(A, step);
		case 0x3d:
			return decrement_register(A, step);
		case 0x3e:
			return load_register_immediate(A, step);
		case 0x3f:
			return complement_carry(step);
		case 0x40:
			return load_register(B, B, step);
		case 0x41:
			return load_register(B, C, step);
		case 0x42:
			return load_register(B, D, step);
		case 0x43:
			return load_register(B, E, step);
		case 0x44:
			return load_register(B, H, step);
		case 0x45:
			return load_register(B, L, step);
		case 0x46:
			return load_register_hl(B, step);
		case 0x47:
			return load_register(B, A, step);
		case 0x48:
			return load_register(C, B, step);
		case 0x49:
			return load_register(C, C, step);
		case 0x4a:
			return load_register(C, D, step);
		case 0x4b:
			return load_register(C, E, step);
		case 0x4c:
			return load_register(C, H, step);
		case 0x4d:
			return load_register(C, L, step);
		case 0x4e:
			return load_register_hl(C, step);
		case 0x4f:
			return load_register(C, A, step);
		case 0x50:
			return load_register(D, B, step);
		case 0x51:
			return load_register(D, C, step);
		case 0x52:
			return load_register(D, D, step);
		case 0x53:
			return load_register(D, E, step);
		case 0x54:
			return load_register(D, H, step);
		case 0x55:
			return load_register(D, L, step);
		case 0x56:
			return load_register_hl(D, step);
		case 0x57:
			return load_register(D, A, step);
		case 0x58:
			return load_register(E, B, step);
		case 0x59:
			return load_register(E, C, step);
		case 0x5a:
			return load_register(E, D, step);
		case 0x5b:
			return load_register(E, E, step);
		case 0x5c:
			return load_register(E, H, step);
		case 0x5d:
			return load_register(E, L, step);
		case 0x5e:
			return load_register_hl(E, step);
		case 0x5f:
			return load_register(E, A, step);
		case 0x60:
			return load_register(H, B, step);
		case 0x61:
			return load_register(H, C, step);
		case 0x62:
			return load_register(H, D, step);
		case 0x63:
			return load_register(H, E, step);
		case 0x64:
			return load_register(H, H, step);
		case 0x65:
			return load_register(H, L, step);
		case 0x66:
			return load_register_hl(H, step);
		case 0x67:
			return load_register(H, A, step);
		case 0x68:
			return load_register(L, B, step);
		case 0x69:
			return load_register(L, C, step);
		case 0x6a:
			return load_register(L, D, step);
		case 0x6b:
			return load_register(L, E, step);
		case 0x6c:
			return load_register(L, H, step);
		case 0x6d:
			return load_register(L, L, step);
		case 0x6e:
			return load_register_hl(L, step);
		case 0x6f:
			return load_register(L, A, step);
		case 0x70:
			return load_from_register_hl(B, step);
		case 0x71:
			return load_from_register_hl(C, step);
		case 0x72:
			return load_from_register_hl(D, step);
		case 0x73:
			return load_from_register_hl(E, step);
		case 0x74:
			return load_from_register_hl(H, step);
		case 0x75:
			return load_from_register_hl(L, step);
		case 0x76:
			return halt(step);
		case 0x77:
			return load_from_register_hl(A, step);
		case 0x78:
			return load_register(A, B, step);
		case 0x79:
			return load_register(A, C, step);
		case 0x7a:
			return load_register(A, D, step);
		case 0x7b:
			return load_register(A, E, step);
		case 0x7c:
			return load_register(A, H, step);
		case 0x7d:
			return load_register(A, L, step);
		case 0x7e:
			return load_register_hl(A, step);
		case 0x7f:
			return load_register(A, A, step);
		case 0x80:
			return add_register(B, step);
		case 0x81:
			return add_register(C, step);
		case 0x82:
			return add_register(D, step);
		case 0x83:
			return add_register(E, step);
		case 0x84:
			return add_register(H, step);
		case 0x85:
			return add_register(L, step);
		case 0x86:
			return add_hl(step);
		case 0x87:
			return add_register(A, step);
		case 0x88:
			return add_with_carry_register(B, step);
		case 0x89:
			return add_with_carry_register(C, step);
		case 0x8a:
			return add_with_carry_register(D, step);
		case 0x8b:
			return add_with_carry_register(E, step);
		case 0x8c:
			return add_with_carry_register(H, step);
		case 0x8d:
			return add_with_carry_register(L, step);
		case 0x8e:
			return add_with_carry_hl(step);
		case 0x8f:
			return add_with_carry_register(A, step);
		case 0x90:
			return sub_register(B, step);
		case 0x91:
			return sub_register(C, step);
		case 0x92:
			return sub_register(D, step);
		case 0x93:
			return sub_register(E, step);
		case 0x94:
			return sub_register(H, step);
		case 0x95:
			return sub_register(L, step);
		case 0x96:
			return sub_hl(step);
		case 0x97:
			return sub_register(A, step);
		case 0x98:
			return sub_with_carry_register(B, step);
		case 0x99:
			return sub_with_carry_register(C, step);
		case 0x9a:
			return sub_with_carry_register(D, step);
		case 0x9b:
			return sub_with_carry_register(E, step);
		case 0x9c:
			return sub_with_carry_register(H, step);
		case 0x9d:
			return sub_with_carry_register(L, step);
		case 0x9e:
			return sub_with_carry_hl(step);
		case 0x9f:
			return sub_with_carry_register(A, step);
		case 0xa0:
			return bit_and_register(B, step);
		case 0xa1:
			return bit_and_register(C, step);
		case 0xa2:
			return bit_and_register(D, step);
		case 0xa3:
			return bit_and_register(E, step);
		case 0xa4:
			return bit_and_register(H, step);
		case 0xa5:
			return bit_and_register(L, step);
		case 0xa6:
			return bit_and_hl(step);
		case 0xa7:
			return bit_and_register(A, step);
		case 0xa8:
			return bit_xor_register(B, step);
		case 0xa9:
			return bit_xor_register(C, step);
		case 0xaa:
			return bit_xor_register(D, step);
		case 0xab:
			return bit_xor_register(E, step);
		case 0xac:
			return bit_xor_register(H, step);
		case 0xad:
			return bit_xor_register(L, step);
		case 0xae:
			return bit_xor_hl(step);
		case 0xaf:
			return bit_xor_register(A, step);
		case 0xb0:
			return bit_or_register(B, step);
		case 0xb1:
			return bit_or_register(C, step);
		case 0xb2:
			return bit_or_register(D, step);
		case 0xb3:
			return bit_or_register(E, step);
		case 0xb4:
			return bit_or_register(H, step);
		case 0xb5:
			return bit_or_register(L, step);
		case 0xb6:
			return bit_or_hl(step);
		case 0xb7:
			return bit_or_register(A, step);
		case 0xb8:
			return compare_register(B, step);
		case 0xb9:
			return compare_register(C, step);
		case 0xba:
			return compare_register(D, step);
		case 0xbb:
			return compare_register(E, step);
		case 0xbc:
			return compare_register(H, step);
		case 0xbd:
			return compare_register(L, step);
		case 0xbe:
			return compare_hl(step);
		case 0xbf:
			return compare_register(A, step);
		case 0xc0:
			return ret_conditional(NZ, step);
		case 0xc1:
			return pop(BC, step);
		case 0xc2:
			return jump_conditional(NZ, step);
		case 0xc3:
			return jump(step);
		case 0xc4:
			return call_conditional(NZ, step);
		case 0xc5:
			return push(BC, step);
		case 0xc6:
			return add_immediate(step);
		case 0xc7:
			return restart(0, step);
		case 0xc8:
			return ret_conditional(Z, step);
		case 0xc9:
			return ret(step);
		case 0xca:
			return jump_conditional(Z, step);
		case 0xcb:
			return prefix_0xcb(opcode, step);
		case 0xcc:
			return call_conditional(Z, step);
		case 0xcd:
			return call(step);
		case 0xce:
			return add_with_carry_immediate(step);
		case 0xcf:
			return restart(8, step);
		case 0xd0:
			return ret_conditional(NC, step);
		case 0xd1:
			return pop(DE, step);
		case 0xd2:
			return jump_conditional(NC, step);
		case 0xd4:
			return call_conditional(NC, step);
		case 0xd5:
			return push(DE, step);
		case 0xd6:
			return sub_immediate(step);
		case 0xd7:
			return restart(16, step);
		case 0xd8:
			return ret_conditional(C, step);
		case 0xd9:
			return ret_interrupt(step);
		case 0xda:
			return jump_conditional(C, step);
		case 0xdc:
			return call_conditional(C, step);
		case 0xde:
			return sub_with_carry_immediate(step);
		case 0xdf:
			return restart(24, step);
		case 0xe0:
			return load_from_accumulator_offset(step);
		case 0xe1:
			return pop(HL, step);
		case 0xe2:
			return load_from_accumulator_c(step);
		case 0xe5:
			return push(HL, step);
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
			return pop(AF, step);
		case 0xf2:
			return load_accumulator_c(step);
		case 0xf3:
			return disable_interrupts(step);
		case 0xf5:
			return push(AF, step);
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
			return rotate_left_circular_register(B, step);
		case 0x01:
			return rotate_left_circular_register(C, step);
		case 0x02:
			return rotate_left_circular_register(D, step);
		case 0x03:
			return rotate_left_circular_register(E, step);
		case 0x04:
			return rotate_left_circular_register(H, step);
		case 0x05:
			return rotate_left_circular_register(L, step);
		case 0x06:
			return rotate_left_circular_hl(step);
		case 0x07:
			return rotate_left_circular_register(A, step);
		case 0x08:
			return rotate_right_circular_register(B, step);
		case 0x09:
			return rotate_right_circular_register(C, step);
		case 0x0a:
			return rotate_right_circular_register(D, step);
		case 0x0b:
			return rotate_right_circular_register(E, step);
		case 0x0c:
			return rotate_right_circular_register(H, step);
		case 0x0d:
			return rotate_right_circular_register(L, step);
		case 0x0e:
			return rotate_right_circular_hl(step);
		case 0x0f:
			return rotate_right_circular_register(A, step);
		case 0x10:
			return rotate_left_register(B, step);
		case 0x11:
			return rotate_left_register(C, step);
		case 0x12:
			return rotate_left_register(D, step);
		case 0x13:
			return rotate_left_register(E, step);
		case 0x14:
			return rotate_left_register(H, step);
		case 0x15:
			return rotate_left_register(L, step);
		case 0x16:
			return rotate_left_hl(step);
		case 0x17:
			return rotate_left_register(A, step);
		case 0x18:
			return rotate_right_register(B, step);
		case 0x19:
			return rotate_right_register(C, step);
		case 0x1a:
			return rotate_right_register(D, step);
		case 0x1b:
			return rotate_right_register(E, step);
		case 0x1c:
			return rotate_right_register(H, step);
		case 0x1d:
			return rotate_right_register(L, step);
		case 0x1e:
			return rotate_right_hl(step);
		case 0x1f:
			return rotate_right_register(A, step);
		case 0x20:
			return shift_left_register(B, step);
		case 0x21:
			return shift_left_register(C, step);
		case 0x22:
			return shift_left_register(D, step);
		case 0x23:
			return shift_left_register(E, step);
		case 0x24:
			return shift_left_register(H, step);
		case 0x25:
			return shift_left_register(L, step);
		case 0x26:
			return shift_left_hl(step);
		case 0x27:
			return shift_left_register(A, step);
		case 0x28:
			return shift_right_register(B, step);
		case 0x29:
			return shift_right_register(C, step);
		case 0x2a:
			return shift_right_register(D, step);
		case 0x2b:
			return shift_right_register(E, step);
		case 0x2c:
			return shift_right_register(H, step);
		case 0x2d:
			return shift_right_register(L, step);
		case 0x2e:
			return shift_right_hl(step);
		case 0x2f:
			return shift_right_register(A, step);
		case 0x30:
			return swap_nibbles_register(B, step);
		case 0x31:
			return swap_nibbles_register(C, step);
		case 0x32:
			return swap_nibbles_register(D, step);
		case 0x33:
			return swap_nibbles_register(E, step);
		case 0x34:
			return swap_nibbles_register(H, step);
		case 0x35:
			return swap_nibbles_register(L, step);
		case 0x36:
			return swap_nibbles_hl(step);
		case 0x37:
			return swap_nibbles_register(A, step);
		case 0x38:
			return shift_right_logical_register(B, step);
		case 0x39:
			return shift_right_logical_register(C, step);
		case 0x3a:
			return shift_right_logical_register(D, step);
		case 0x3b:
			return shift_right_logical_register(E, step);
		case 0x3c:
			return shift_right_logical_register(H, step);
		case 0x3d:
			return shift_right_logical_register(L, step);
		case 0x3e:
			return shift_right_logical_hl(step);
		case 0x3f:
			return shift_right_logical_register(A, step);
		case 0x40:
			return test_bit_register(0,B, step);
		case 0x41:
			return test_bit_register(0,C, step);
		case 0x42:
			return test_bit_register(0,D, step);
		case 0x43:
			return test_bit_register(0,E, step);
		case 0x44:
			return test_bit_register(0,H, step);
		case 0x45:
			return test_bit_register(0,L, step);
		case 0x46:
			return test_bit_hl(0, step);
		case 0x47:
			return test_bit_register(0,A, step);
		case 0x48:
			return test_bit_register(1,B, step);
		case 0x49:
			return test_bit_register(1,C, step);
		case 0x4a:
			return test_bit_register(1,D, step);
		case 0x4b:
			return test_bit_register(1,E, step);
		case 0x4c:
			return test_bit_register(1,H, step);
		case 0x4d:
			return test_bit_register(1,L, step);
		case 0x4e:
			return test_bit_hl(1, step);
		case 0x4f:
			return test_bit_register(1,A, step);
		case 0x50:
			return test_bit_register(2,B, step);
		case 0x51:
			return test_bit_register(2,C, step);
		case 0x52:
			return test_bit_register(2,D, step);
		case 0x53:
			return test_bit_register(2,E, step);
		case 0x54:
			return test_bit_register(2,H, step);
		case 0x55:
			return test_bit_register(2,L, step);
		case 0x56:
			return test_bit_hl(2, step);
		case 0x57:
			return test_bit_register(2,A, step);
		case 0x58:
			return test_bit_register(3,B, step);
		case 0x59:
			return test_bit_register(3,C, step);
		case 0x5a:
			return test_bit_register(3,D, step);
		case 0x5b:
			return test_bit_register(3,E, step);
		case 0x5c:
			return test_bit_register(3,H, step);
		case 0x5d:
			return test_bit_register(3,L, step);
		case 0x5e:
			return test_bit_hl(3, step);
		case 0x5f:
			return test_bit_register(3,A, step);
		case 0x60:
			return test_bit_register(4,B, step);
		case 0x61:
			return test_bit_register(4,C, step);
		case 0x62:
			return test_bit_register(4,D, step);
		case 0x63:
			return test_bit_register(4,E, step);
		case 0x64:
			return test_bit_register(4,H, step);
		case 0x65:
			return test_bit_register(4,L, step);
		case 0x66:
			return test_bit_hl(4, step);
		case 0x67:
			return test_bit_register(4,A, step);
		case 0x68:
			return test_bit_register(5,B, step);
		case 0x69:
			return test_bit_register(5,C, step);
		case 0x6a:
			return test_bit_register(5,D, step);
		case 0x6b:
			return test_bit_register(5,E, step);
		case 0x6c:
			return test_bit_register(5,H, step);
		case 0x6d:
			return test_bit_register(5,L, step);
		case 0x6e:
			return test_bit_hl(5, step);
		case 0x6f:
			return test_bit_register(5,A, step);
		case 0x70:
			return test_bit_register(6,B, step);
		case 0x71:
			return test_bit_register(6,C, step);
		case 0x72:
			return test_bit_register(6,D, step);
		case 0x73:
			return test_bit_register(6,E, step);
		case 0x74:
			return test_bit_register(6,H, step);
		case 0x75:
			return test_bit_register(6,L, step);
		case 0x76:
			return test_bit_hl(6, step);
		case 0x77:
			return test_bit_register(6,A, step);
		case 0x78:
			return test_bit_register(7,B, step);
		case 0x79:
			return test_bit_register(7,C, step);
		case 0x7a:
			return test_bit_register(7,D, step);
		case 0x7b:
			return test_bit_register(7,E, step);
		case 0x7c:
			return test_bit_register(7,H, step);
		case 0x7d:
			return test_bit_register(7,L, step);
		case 0x7e:
			return test_bit_hl(7, step);
		case 0x7f:
			return test_bit_register(7,A, step);
		case 0x80:
			return reset_bit_register(0,B, step);
		case 0x81:
			return reset_bit_register(0,C, step);
		case 0x82:
			return reset_bit_register(0,D, step);
		case 0x83:
			return reset_bit_register(0,E, step);
		case 0x84:
			return reset_bit_register(0,H, step);
		case 0x85:
			return reset_bit_register(0,L, step);
		case 0x86:
			return reset_bit_hl(0, step);
		case 0x87:
			return reset_bit_register(0,A, step);
		case 0x88:
			return reset_bit_register(1,B, step);
		case 0x89:
			return reset_bit_register(1,C, step);
		case 0x8a:
			return reset_bit_register(1,D, step);
		case 0x8b:
			return reset_bit_register(1,E, step);
		case 0x8c:
			return reset_bit_register(1,H, step);
		case 0x8d:
			return reset_bit_register(1,L, step);
		case 0x8e:
			return reset_bit_hl(1, step);
		case 0x8f:
			return reset_bit_register(1,A, step);
		case 0x90:
			return reset_bit_register(2,B, step);
		case 0x91:
			return reset_bit_register(2,C, step);
		case 0x92:
			return reset_bit_register(2,D, step);
		case 0x93:
			return reset_bit_register(2,E, step);
		case 0x94:
			return reset_bit_register(2,H, step);
		case 0x95:
			return reset_bit_register(2,L, step);
		case 0x96:
			return reset_bit_hl(2, step);
		case 0x97:
			return reset_bit_register(2,A, step);
		case 0x98:
			return reset_bit_register(3,B, step);
		case 0x99:
			return reset_bit_register(3,C, step);
		case 0x9a:
			return reset_bit_register(3,D, step);
		case 0x9b:
			return reset_bit_register(3,E, step);
		case 0x9c:
			return reset_bit_register(3,H, step);
		case 0x9d:
			return reset_bit_register(3,L, step);
		case 0x9e:
			return reset_bit_hl(3, step);
		case 0x9f:
			return reset_bit_register(3,A, step);
		case 0xa0:
			return reset_bit_register(4,B, step);
		case 0xa1:
			return reset_bit_register(4,C, step);
		case 0xa2:
			return reset_bit_register(4,D, step);
		case 0xa3:
			return reset_bit_register(4,E, step);
		case 0xa4:
			return reset_bit_register(4,H, step);
		case 0xa5:
			return reset_bit_register(4,L, step);
		case 0xa6:
			return reset_bit_hl(4, step);
		case 0xa7:
			return reset_bit_register(4,A, step);
		case 0xa8:
			return reset_bit_register(5,B, step);
		case 0xa9:
			return reset_bit_register(5,C, step);
		case 0xaa:
			return reset_bit_register(5,D, step);
		case 0xab:
			return reset_bit_register(5,E, step);
		case 0xac:
			return reset_bit_register(5,H, step);
		case 0xad:
			return reset_bit_register(5,L, step);
		case 0xae:
			return reset_bit_hl(5, step);
		case 0xaf:
			return reset_bit_register(5,A, step);
		case 0xb0:
			return reset_bit_register(6,B, step);
		case 0xb1:
			return reset_bit_register(6,C, step);
		case 0xb2:
			return reset_bit_register(6,D, step);
		case 0xb3:
			return reset_bit_register(6,E, step);
		case 0xb4:
			return reset_bit_register(6,H, step);
		case 0xb5:
			return reset_bit_register(6,L, step);
		case 0xb6:
			return reset_bit_hl(6, step);
		case 0xb7:
			return reset_bit_register(6,A, step);
		case 0xb8:
			return reset_bit_register(7,B, step);
		case 0xb9:
			return reset_bit_register(7,C, step);
		case 0xba:
			return reset_bit_register(7,D, step);
		case 0xbb:
			return reset_bit_register(7,E, step);
		case 0xbc:
			return reset_bit_register(7,H, step);
		case 0xbd:
			return reset_bit_register(7,L, step);
		case 0xbe:
			return reset_bit_hl(7, step);
		case 0xbf:
			return reset_bit_register(7,A, step);
		case 0xc0:
			return set_bit_register(0,B, step);
		case 0xc1:
			return set_bit_register(0,C, step);
		case 0xc2:
			return set_bit_register(0,D, step);
		case 0xc3:
			return set_bit_register(0,E, step);
		case 0xc4:
			return set_bit_register(0,H, step);
		case 0xc5:
			return set_bit_register(0,L, step);
		case 0xc6:
			return set_bit_hl(0, step);
		case 0xc7:
			return set_bit_register(0,A, step);
		case 0xc8:
			return set_bit_register(1,B, step);
		case 0xc9:
			return set_bit_register(1,C, step);
		case 0xca:
			return set_bit_register(1,D, step);
		case 0xcb:
			return set_bit_register(1,E, step);
		case 0xcc:
			return set_bit_register(1,H, step);
		case 0xcd:
			return set_bit_register(1,L, step);
		case 0xce:
			return set_bit_hl(1, step);
		case 0xcf:
			return set_bit_register(1,A, step);
		case 0xd0:
			return set_bit_register(2,B, step);
		case 0xd1:
			return set_bit_register(2,C, step);
		case 0xd2:
			return set_bit_register(2,D, step);
		case 0xd3:
			return set_bit_register(2,E, step);
		case 0xd4:
			return set_bit_register(2,H, step);
		case 0xd5:
			return set_bit_register(2,L, step);
		case 0xd6:
			return set_bit_hl(2, step);
		case 0xd7:
			return set_bit_register(2,A, step);
		case 0xd8:
			return set_bit_register(3,B, step);
		case 0xd9:
			return set_bit_register(3,C, step);
		case 0xda:
			return set_bit_register(3,D, step);
		case 0xdb:
			return set_bit_register(3,E, step);
		case 0xdc:
			return set_bit_register(3,H, step);
		case 0xdd:
			return set_bit_register(3,L, step);
		case 0xde:
			return set_bit_hl(3, step);
		case 0xdf:
			return set_bit_register(3,A, step);
		case 0xe0:
			return set_bit_register(4,B, step);
		case 0xe1:
			return set_bit_register(4,C, step);
		case 0xe2:
			return set_bit_register(4,D, step);
		case 0xe3:
			return set_bit_register(4,E, step);
		case 0xe4:
			return set_bit_register(4,H, step);
		case 0xe5:
			return set_bit_register(4,L, step);
		case 0xe6:
			return set_bit_hl(4, step);
		case 0xe7:
			return set_bit_register(4,A, step);
		case 0xe8:
			return set_bit_register(5,B, step);
		case 0xe9:
			return set_bit_register(5,C, step);
		case 0xea:
			return set_bit_register(5,D, step);
		case 0xeb:
			return set_bit_register(5,E, step);
		case 0xec:
			return set_bit_register(5,H, step);
		case 0xed:
			return set_bit_register(5,L, step);
		case 0xee:
			return set_bit_hl(5, step);
		case 0xef:
			return set_bit_register(5,A, step);
		case 0xf0:
			return set_bit_register(6,B, step);
		case 0xf1:
			return set_bit_register(6,C, step);
		case 0xf2:
			return set_bit_register(6,D, step);
		case 0xf3:
			return set_bit_register(6,E, step);
		case 0xf4:
			return set_bit_register(6,H, step);
		case 0xf5:
			return set_bit_register(6,L, step);
		case 0xf6:
			return set_bit_hl(6, step);
		case 0xf7:
			return set_bit_register(6,A, step);
		case 0xf8:
			return set_bit_register(7,B, step);
		case 0xf9:
			return set_bit_register(7,C, step);
		case 0xfa:
			return set_bit_register(7,D, step);
		case 0xfb:
			return set_bit_register(7,E, step);
		case 0xfc:
			return set_bit_register(7,H, step);
		case 0xfd:
			return set_bit_register(7,L, step);
		case 0xfe:
			return set_bit_hl(7, step);
		case 0xff:
			return set_bit_register(7,A, step);
		default:
			return 0;
	}
}
