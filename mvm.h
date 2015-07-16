#ifndef _MVM_H_
#define _MVM_H_

#define null ((void *)0x0)
#define u8 unsigned char
#define u32 unsigned int
#define pointer void *
#define bool unsigned char

#define TRUE 1
#define FALSE 0

#define memory_type_out 0
#define memory_type_in  1

#define io_size 0x10

typedef struct mvm_contral_block {
    u32 memory_size;
    u8 *memory;
    u8 memory_type;
    u32 r0;
    u32 r1;
    u32 r2;
    u32 r3;
    u32 r4;
    u32 r5;
    u32 r6;
    u32 r7;
    u32 ip;
    u32 sp;
    u32 *io_map[io_size];
    void (*io_function[io_size])();
} MCB;

MCB* mvm_initialize(u32 memory_size, pointer memory_address);
void mvm_destroy(MCB *mcb);
bool mvm_set_io_map(MCB *mcb, u32 port, u32 *address, void (*function)());
bool mvm_load_code(MCB *mcb, u8 *code, u32 code_size, u32 address);

#endif //_MVM_H_
