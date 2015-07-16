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
    for (int i = 0; i < io_size; i++)
    {
        new_mvm->io_map[i] = null;
        new_mvm->io_function[i] = null;
    }
    return new_mvm;
}

void mvm_destroy(MCB *mcb)
{
    if (mcb->memory_type == memory_type_in)
        free(mcb->memory);
    free(mcb);
}

bool mvm_set_io_map(MCB *mcb, u32 port, u32 *address, void (*function)())
{
    if (port < io_size)
    {
        mcb->io_map[port] = address;
        mcb->io_function[port] = function;
        return TRUE;
    }
    return FALSE;
}

bool mvm_load_code(MCB *mcb, u8 *code, u32 code_size, u32 address)
{
    u32 temp_size = mcb->memory_size;
    if (temp_size > code_size) {
        temp_size -= code_size;
        if (temp_size >  address) {
            for (u32 i = 0; i < code_size; i++)
                mcb->memory[ address + i] = code[i];
            return TRUE;
        }
        else
            return FALSE;
    }
    else
        return FALSE;
}