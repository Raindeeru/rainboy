//This isn't really a componenent but yeah  
#include <vector>
#include "../types.h"
#include "../mmu.h"

void MMU::handle_not_useable_writes(WORD address, BYTE data){

} //I think kailangan ko mag implement OAM corruption
BYTE MMU::handle_not_useable_reads(WORD address){
    return 0;
}
