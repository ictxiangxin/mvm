#include "mvm.h"
#include "stdlib.h"

 MCB* mvm_initialize(u32 memory_size, pointer memory_address)
{
    MCB* new_mvm = (MCB *)malloc(sizeof(MCB));
    if (memory_address == null)
    {
        new_mvm->memory = (u8 *)malloc(memory_size);
        new_mvm->memory_type = memory_type_in;
    }
    else
    {
        new_mvm->memory = (u8 *)memory_address;
        new_mvm->memory_type = memory_type_out;
    }
    if (new_mvm->memory == null)
        return null;
    new_mvm->r0 = 0x0;
    new_mvm->r1 = 0x0;
    new_mvm->r2 = 0x0;
    new_mvm->r3 = 0x0;
    new_mvm->r4 = 0x0;
    new_mvm->r5 = 0x0;
    new_mvm->r6 = 0x0;
    new_mvm->r7 = 0x0;
    new_mvm->ip = 0x0;
    new_mvm->sp = memory_size - 1;
    for (int i = 0; i < io_map_size; i++)
        new_mvm->io_map[i] = null;
    return new_mvm;
}

void mvm_destory(MCB *mcb)
{
    if (mcb->memory_type == memory_type_in)
        free(mcb->memory);
    free(mcb);
}