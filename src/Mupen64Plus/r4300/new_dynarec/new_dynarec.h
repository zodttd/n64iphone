#ifndef NO_ASM
#define NEW_DYNAREC 1
#endif

extern int pcaddr;
extern int pending_exception;

void invalidate_block(u_int block);
void new_dynarec_init();
void new_dynarec_cleanup();
void new_dyna_start();
