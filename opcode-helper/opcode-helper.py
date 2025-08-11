from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.options import Options
import re

options = Options()
options.headless = True

driver = webdriver.Firefox(options = options)
driver.get("https://izik1.github.io/gbops/")

opcode_table = driver.find_element(By.ID, "unprefixed-16-t")
opcode_table = opcode_table.find_element(By.XPATH, ".//tbody")
opcode_rows = opcode_table.find_elements(By.XPATH, ".//tr")
opcodes = []
for i, opcode_row in enumerate(opcode_rows):
    opcodes_row_removed_first = opcode_row.find_elements(By.XPATH, ".//td")
    for j, opcode in enumerate(opcodes_row_removed_first):
        opcode_dict = {}

        opcode_int = i*16 + j
        opcode_dict["hex"] = "0x%0.2x" % opcode_int
        opcode_dict["class"] = opcode.get_attribute("class")

        split_opcode = opcode.text.split("\n")

        if len(split_opcode) < 3:
            opcodes.append(opcode_dict)
            continue

        opcode_dict["ins"] = split_opcode[0]

        len_cycles_split = split_opcode[1].split()
        opcode_dict["len"] = len_cycles_split[0]
        opcode_dict["cycles"] = len_cycles_split[1][:-1]

        opcodes.append(opcode_dict)

opcode_prefix_table = driver.find_element(By.ID, "cbprefixed-16-t")
opcode_prefix_table = opcode_prefix_table.find_element(By.XPATH, ".//tbody")
opcode_prefix_rows = opcode_prefix_table.find_elements(By.XPATH, ".//tr")
opcode_prefixs = []
for i, opcode_prefix_row in enumerate(opcode_prefix_rows):
    opcode_prefixs_row_removed_first = opcode_prefix_row.find_elements(By.XPATH, ".//td")
    for j, opcode_prefix in enumerate(opcode_prefixs_row_removed_first):
        opcode_prefix_dict = {}

        opcode_prefix_int = i*16 + j
        opcode_prefix_dict["hex"] = "0x%0.2x" % opcode_prefix_int
        opcode_prefix_dict["class"] = opcode_prefix.get_attribute("class")

        split_opcode_prefix = opcode_prefix.text.split("\n")

        if len(split_opcode_prefix) < 3:
            opcode_prefixs.append(opcode_prefix_dict)
            continue

        opcode_prefix_dict["ins"] = split_opcode_prefix[0]

        len_cycles_split = split_opcode_prefix[1].split()
        opcode_prefix_dict["len"] = len_cycles_split[0]
        opcode_prefix_dict["cycles"] = len_cycles_split[1][:-1]

        opcode_prefixs.append(opcode_prefix_dict)

driver.close()

def translate_instruction_to_function(ins:str):
    LDr_r_prime = r"^LD ([ABCDEFHL]),([ABCDEFHL])"
    match = re.fullmatch(LDr_r_prime, ins)

    if match:
        reg1 = match.group(1)
        reg2 = match.group(2)
        return f"load_register({reg1}, {reg2})"
    LDr_n = r"^LD ([ABCDEFHL]),u8"

    match = re.fullmatch(LDr_n, ins)
    if match:
        reg1 = match.group(1)
        return f"load_register_immediate({reg1})"

    LDr_HL = r"^LD ([ABCDEFHL]),\(HL\)"
    match = re.fullmatch(LDr_HL, ins)
    if match:
        reg1 = match.group(1)
        return f"load_register_hl({reg1})"

    LD_HL_r = r"^LD \(HL\),([ABCDEFHL])"
    match = re.fullmatch(LD_HL_r, ins)
    if match:
        reg1 = match.group(1)
        return f"load_from_register_hl({reg1})"

    # LD_HL_n =
    if ins == "LD (HL),u8":
        return "load_hl_immediate()"

    # LDA_BC =
    if ins == "LD A,(BC)":
        return "load_accumulator_bc()"

    # LDA_DE =
    if ins == "LD A,(DE)":
        return "load_accumulator_de()"

    # LD_BC_A =
    if ins == "LD (BC),A":
        return "load_from_accumulator_bc()"

    # LD_DE_A =
    if ins == "LD (DE),A":
        return "load_from_accumulator_de()"

    # LDA_nn =
    if ins == "LD A,(u16)":
        return "load_accumulator()"

    # LD_nn_A =
    if ins == "LD (u16),A":
        return "load_from_accumulator()"

    # LDHA_C =
    if ins == "LD A,(FF00+C)":
        return "load_accumulator_c()"

    # LDH_C_A =
    if ins == "LD (FF00+C),A":
        return "load_from_accumulator_c()"

    # LDHA_n =
    if ins == "LD A,(FF00+u8)":
        return "load_accumulator_offset()"

    # LDH_n_A =
    if ins == "LD (FF00+u8),A":
        return "load_from_accumulator_offset()"

    # LDA_HLminus =
    if ins == "LD A,(HL-)":
        return "load_accumulator_hl_decrement()"

    # LD_HLminus_A =
    if ins == "LD (HL-),A":
        return "load_from_accumulator_hl_decrement()"

    # LDA_HLplus =
    if ins == "LD A,(HL+)":
        return "load_accumulator_hl_increment()"

    # LD_HLplus_A =
    if ins == "LD (HL+),A":
        return "load_from_accumulator_hl_increment()"

    LDrr_nn = r"^LD ([A-Z][A-Z]),u16"
    match = re.fullmatch(LDrr_nn, ins)
    if match:
        reg1 = match.group(1)
        return f"load_register_immediate({reg1})"

    # LD_nn_SP =
    if ins == "LD (u16),SP":
        return "load_from_stack()"

    # LDSP_HL =
    if ins == "LD SP,HL":
        return "load_from_stack()"

    PUSHrr = r"^PUSH ([A-Z][A-Z])"
    match = re.fullmatch(PUSHrr, ins)
    if match:
        reg1 = match.group(1)
        return f"push({reg1})"

    POPrr = r"^POP ([A-Z][A-Z])"
    match = re.fullmatch(POPrr, ins)
    if match:
        reg1 = match.group(1)
        return f"pop({reg1})"

    # LDHL_SPpluse =
    if ins == "LD HL,SP+i8":
        return "load_hl_sp_plus_e()"

    ADDr = r"^ADD A,([ABCDEFHL])"
    match = re.fullmatch(ADDr, ins)
    if match:
        reg1 = match.group(1)
        return f"add_register({reg1})"

    # ADD_HL =
    if ins == "ADD A,(HL)":
        return "add_hl()"

    # ADDn =
    if ins == "ADD A,u8":
        return "add_immediate()"

    ADCr = r"^ADC A,([ABCDEFHL])"
    match = re.fullmatch(ADCr, ins)
    if match:
        reg1 = match.group(1)
        return f"add_with_carry_register({reg1})"

    # ADC_HL =
    if ins == "ADC A,(HL)":
        return "add_with_carry_hl()"

    # ADCn =
    if ins == "ADC A,u8":
        return "add_with_carry_immediate()"

    SUBr = r"^SUB A,([ABCDEFHL])"
    match = re.fullmatch(SUBr, ins)
    if match:
        reg1 = match.group(1)
        return f"sub_register({reg1})"

    # SUB_HL =
    if ins == "SUB A,(HL)":
        return "sub_hl()"

    # SUBn =
    if ins == "SUB A,u8":
        return "sub_immediate()"

    SBCr = r"^SBC A,([ABCDEFHL])"
    match = re.fullmatch(SBCr, ins)
    if match:
        reg1 = match.group(1)
        return f"sub_with_carry_register({reg1})"

    # SBC_HL =
    if ins == "SBC A,(HL)":
        return "sub_with_carry_hl()"

    # SBCn =
    if ins == "SBC A,u8":
        return "sub_with_carry_immediate()"

    # CPr =
    CPr = r"^CP A,([ABCDEFHL])"
    match = re.fullmatch(CPr, ins)
    if match:
        reg1 = match.group(1)
        return f"compare_register({reg1})"

    # CP_HL =
    if ins == "CP A,(HL)":
        return "compare_hl()"

    # CPn =
    if ins == "CP A,u8":
        return "compare_immediate()"

    INCr = r"^INC ([ABCDEFHL])"
    match = re.fullmatch(INCr, ins)
    if match:
        reg1 = match.group(1)
        return f"increment_register({reg1})"

    # INC_HL =
    if ins == "INC (HL)":
        return "increment_hl()"

    # DECr =
    # DEC_HL =
    DECr = r"^DEC ([ABCDEFHL])"
    match = re.fullmatch(DECr, ins)
    if match:
        reg1 = match.group(1)
        return f"decrement_register({reg1})"

    # DEC_HL =
    if ins == "DEC (HL)":
        return "decrement_hl()"

    ANDr = r"^AND A,([ABCDEFHL])"
    match = re.fullmatch(ANDr, ins)
    if match:
        reg1 = match.group(1)
        return f"bit_and_register({reg1})"

    # AND_HL =
    if ins == "AND A,(HL)":
        return "bit_and_hl()"

    # ANDn =
    if ins == "AND A,u8":
        return "bit_and_immediate()"

    ORr = r"^OR A,([ABCDEFHL])"
    match = re.fullmatch(ORr, ins)
    if match:
        reg1 = match.group(1)
        return f"bit_or_register({reg1})"

    # OR_HL =
    if ins == "OR A,(HL)":
        return "bit_or_hl()"

    # ORn =
    if ins == "OR A,u8":
        return "bit_or_immediate()"

    XORr = r"^XOR A,([ABCDEFHL])"
    match = re.fullmatch(XORr, ins)
    if match:
        reg1 = match.group(1)
        return f"bit_xor_register({reg1})"

    # Xxor_HL =
    if ins == "XOR A,(HL)":
        return "bit_xor_hl()"

    # Xxorn =
    if ins == "XOR A,u8":
        return "bit_xor_immediate()"

    # CCF =
    if ins == "CCF":
        return "complement_carry()"

    # SCF =
    if ins == "SCF":
        return "set_carry()"

    # DAA =
    if ins == "DAA":
        return "decimal_adjust_accumulator()"

    # CPL =
    if ins == "CPL":
        return "complement_accumulator()"

    INCrr = r"^INC ([A-Z][A-Z])"
    match = re.fullmatch(INCrr, ins)
    if match:
        reg1 = match.group(1)
        return f"increment_register_16bit({reg1})"

    DECrr = r"^DEC ([A-Z][A-Z])"
    match = re.fullmatch(DECrr, ins)
    if match:
        reg1 = match.group(1)
        return f"decrement_register_16bit({reg1})"

    # ADDHL_rr =
    ADDHL_rr = r"^ADD HL,([A-Z][A-Z])"
    match = re.fullmatch(ADDHL_rr, ins)
    if match:
        reg1 = match.group(1)
        return f"add_register_hl_16bit({reg1})"

    # ADDSP_e =
    if ins == "ADD SP,i8":
        return "add_stack_16bit()"

    # RLCA =
    if ins == "RLCA":
        return "rotate_left_circular_accumulator()"

    # RRCA =
    if ins == "RRCA":
        return "rotate_right_circular_accumulator()"

    # RLA =
    if ins == "RLA":
        return "rotate_left_accumulator()"

    # RRA =
    if ins == "RRA":
        return "rotate_right_accumulator()"

    RLCr = r"^RLC ([ABCDEFHL])"
    match = re.fullmatch(RLCr, ins)
    if match:
        reg1 = match.group(1)
        return f"rotate_left_circular_register({reg1})"

    # RLC_HL =
    if ins == "RLC (HL)":
        return  "rotate_left_circular_hl()"

    RRCr = r"^RRC ([ABCDEFHL])"
    match = re.fullmatch(RRCr, ins)
    if match:
        reg1 = match.group(1)
        return f"rotate_right_circular_register({reg1})"

    # RRC_HL =
    if ins == "RRC (HL)":
        return  "rotate_right_circular_hl()"

    RLr = r"^RL ([ABCDEFHL])"
    match = re.fullmatch(RLr, ins)
    if match:
        reg1 = match.group(1)
        return f"rotate_left_register({reg1})"

    # RL_HL =
    if ins == "RL (HL)":
        return  "rotate_left_hl()"

    RRr = r"^RR ([ABCDEFHL])"
    match = re.fullmatch(RRr, ins)
    if match:
        reg1 = match.group(1)
        return f"rotate_right_register({reg1})"

    # RR_HL =
    if ins == "RR (HL)":
        return  "rotate_right_hl()"

    SLAr = r"^SLA ([ABCDEFHL])"
    match = re.fullmatch(SLAr, ins)
    if match:
        reg1 = match.group(1)
        return f"shift_left_register({reg1})"

    # SLA_HL =
    if ins == "SLA (HL)":
        return  "shift_left_hl()"

    SRAr = r"^SRA ([ABCDEFHL])"
    match = re.fullmatch(SRAr, ins)
    if match:
        reg1 = match.group(1)
        return f"shift_right_register({reg1})"

    # SRA_HL =
    if ins == "SRA (HL)":
        return  "shift_right_hl()"

    SWAPr = r"^SWAP ([ABCDEFHL])"
    match = re.fullmatch(SWAPr, ins)
    if match:
        reg1 = match.group(1)
        return f"swap_nibbles_register({reg1})"

    # SWAP_HL =
    if ins == "SWAP (HL)":
        return  "swap_nibbles_hl()"

    # SRLr =
    # SRL_HL =
    SRLr = r"^SRL ([ABCDEFHL])"
    match = re.fullmatch(SRLr, ins)
    if match:
        reg1 = match.group(1)
        return f"shift_right_logical_register({reg1})"

    # SRL_HL =
    if ins == "SRL (HL)":
        return  "shift_right_logical_hl()"

    BITbr = r"^BIT ([0-7]),([ABCDEFHL])"
    match = re.fullmatch(BITbr, ins)
    if match:
        reg1 = match.group(2)
        bit = match.group(1)
        return f"test_bit_register({bit},{reg1})"

    # BITb_HL =
    BITb_HL = r"^BIT ([0-7]),\(HL\)"
    match = re.fullmatch(BITb_HL, ins)
    if match:
        bit = match.group(1)
        return f"test_bit_hl({bit})"

    RESbr = r"^RES ([0-7]),([ABCDEFHL])"
    match = re.fullmatch(RESbr, ins)
    if match:
        reg1 = match.group(2)
        bit = match.group(1)
        return f"reset_bit_register({bit},{reg1})"

    # RESb_HL =
    RESb_HL = r"^RES ([0-7]),\(HL\)"
    match = re.fullmatch(RESb_HL, ins)
    if match:
        bit = match.group(1)
        return f"reset_bit_hl({bit})"

    SETbr = r"^SET ([0-7]),([ABCDEFHL])"
    match = re.fullmatch(SETbr, ins)
    if match:
        reg1 = match.group(2)
        bit = match.group(1)
        return f"set_bit_register({bit},{reg1})"

    # SETb_HL =
    SETb_HL = r"^SET ([0-7]),\(HL\)"
    match = re.fullmatch(SETb_HL, ins)
    if match:
        bit = match.group(1)
        return f"set_bit_hl({bit})"

    # JPnn =
    if ins == "JP u16":
        return "jump()"

    # JPHL =
    if ins == "JP HL":
        return "jump_hl()"

    JPcc_nn = r"^JP (Z|NZ|C|NC),u16"
    match = re.fullmatch(JPcc_nn, ins)
    if match:
        condition = match.group(1)
        return f"jump_conditional({condition})"
    
    # JRe =
    if ins == "JR i8":
        return "jump_relative()"

    JRcc_e = r"^JR (Z|NZ|C|NC),i8"
    match = re.fullmatch(JRcc_e, ins)
    if match:
        condition = match.group(1)
        return f"jump_relative_conditional({condition})"

    # CALLnn =
    if ins == "CALL u16":
        return "call()"

    CALLcc_nn = r"^CALL (Z|NZ|C|NC),u16"
    match = re.fullmatch(CALLcc_nn, ins)
    if match:
        condition = match.group(1)
        return f"call_conditional({condition})"

    # RET =
    if ins == "RET":
        return "ret()"

    RETcc = r"^RET (Z|NZ|C|NC)"
    match = re.fullmatch(RETcc, ins)
    if match:
        condition = match.group(1)
        return f"ret_conditional({condition})"

    # RETI =
    if ins == "RETI":
        return "ret_interrupt()"

    # RSTn =
    RSTcc = r"^RST (00|08|10|18|20|28|30|38)h"
    match = re.fullmatch(RSTcc, ins)
    if match:
        n = match.group(1)
        n = int(n, 16)
        return f"restart({n})"

    # HALT =
    if ins == "HALT":
        return "halt()"

    # STOP =
    if ins == "STOP":
        return "stop()"

    # DI =
    if ins == "DI":
        return "disable_interrupts()"
        
    # EI =
    if ins == "EI":
        return "enable_interrupts()"

    # NOP =
    if ins == "NOP":
        return "nop()"

    if ins == "PREFIX CB":
        return "prefix_0xcb(opcode)"

    return ""

print(translate_instruction_to_function("LD SP,u16"))

cpp_string = ""
cpp_string += "#include \"instructions.h\"\n"
cpp_string += "#include \"cpu.h\"\n"
cpp_string += "int Instructions::decode_execute(BYTE opcode){\n"


opcode_switch = ""
opcode_switch += "\tswitch(opcode){\n"
#Do stuff here

for opcode in opcodes:
    if(opcode["class"] == "opcode unused"):
        continue
    opcode_switch += "\t\tcase " 
    opcode_switch += opcode["hex"]
    opcode_switch += ":\n" 
    function_name = translate_instruction_to_function(opcode["ins"])
    opcode_switch += f"\t\t\treturn {function_name};\n"

opcode_switch += "\t\tdefault:\n\t\t\treturn 0;\n"

opcode_switch += "\t}\n"
cpp_string += opcode_switch

cpp_string += "}\n\n"



cpp_string += "int prefix_0xcb(BYTE opcode){\n"

opcode_prefix_switch = ""
opcode_prefix_switch += "\tswitch(opcode){\n"
#Do stuff here

for opcode_prefix in opcode_prefixs:
    if(opcode_prefix["class"] == "opcode_prefix unused"):
        continue
    opcode_prefix_switch += "\t\tcase " 
    opcode_prefix_switch += opcode_prefix["hex"]
    opcode_prefix_switch += ":\n" 
    function_name = translate_instruction_to_function(opcode_prefix["ins"])
    opcode_prefix_switch += f"\t\t\treturn {function_name};\n"

opcode_prefix_switch += "\t\tdefault:\n\t\t\treturn 0;\n"

opcode_prefix_switch += "\t}\n"
cpp_string += opcode_prefix_switch

cpp_string += "}\n"

print(cpp_string)

output_file = open("../src/gbcore/ins_opcodes.cpp", "w")
output_file.write(cpp_string)
output_file.close()

