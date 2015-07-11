#include <stdio.h>
#include "mvm.h"

int main()
{
    MCB* vm = mvm_initialize(0x1000, null);
    if (vm == null)
        return -1;
    mvm_destroy(vm);
    return 0;
}