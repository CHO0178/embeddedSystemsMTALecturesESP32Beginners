#ifndef LITTLE_HELPER_H
#define LITTLE_HELPER_H



#define setBitInRegister(REG, pos)  						REG |= 1 << pos
#define clearBitInRegister(REG, pos)  						REG &= ~(1 << pos)
#define toogleBitInRegister(REG, pos)  						REG ^= 1 << pos
#define changeMultipleBitInRegister(REG, DATA, MASK, pos)   REG = (DATA << pos) | (REG & (~(MASK & REG)))
#define setMultipleBitsInRegister(REG,DATA,MASK)			REG = (DATA & (~MASK)) | (DATA & MASK)
#define heavyFunction() for(int i = 0;i < 2000000; i++){}
#define REG(x) (*(volatile uint32_t *)(x))






#endif
