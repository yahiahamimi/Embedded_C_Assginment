
/******************************************************************************
 *
 * File Name: Embedded_C_assg.h
 *
 * Description: header file for Embedded_C_assg
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#ifndef EMBEDDED_C_ASSG_H_
#define EMBEDDED_C_ASSG_H_

#define Arr_Size 5

#define GET_BIT(REG, BIT) ((REG & (1 << BIT)) >> BIT)

#define ARRAY_SUM(arr, size) ({         \
    int sum = 0;                        \
    for (int _i = 0; _i < (size); ++_i) \
    {                                   \
        sum += (arr)[_i];               \
    }                                   \
    sum;                                \
})

int forthleastsignbit(int num);
int FallingEdgeCounter(int pin_current);
int RisingEdgeCounter(int pin_current);
unsigned char RightCircularShift(unsigned int InputNumber, int NumberOfShifts, unsigned int *pOutput);
unsigned int ClearBit(unsigned int Number, unsigned int BitNumber);
unsigned char reverseBits(unsigned char num);

#endif /* EMBEDDED_C_ASSG_H_ */