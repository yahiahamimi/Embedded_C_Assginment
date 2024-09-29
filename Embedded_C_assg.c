/******************************************************************************
 *
 * File Name: Embedded_C_assg.c
 *
 * Description: * File contains all functions based on the Embedded c assginment in Standard Diploma
 * each Task has its own Functionality and description individually
 * and the user which functionality he wants to use
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Embedded_C_assg.h"

/**
 * @name print_binary
 * @details This function prints the binary representation of the given number
 * from left to right (most significant bit to least significant bit).
 * The output is a string of 0s and 1s.
 * @param num The number to be printed in binary
 *
 *
 */
void print_binary(unsigned char num)
{
	unsigned char i;
	unsigned char mask = 0x80;
	unsigned char NO_OF_BITS = sizeof(num) * 8;

	printf("The Binary Representation of number %d is : ", num);

	/*
	 * start looping from index n-1 to 0 and check every bit
	 * if it is equals to one print 1
	 * if it is zero print 0
	 */
	for (i = 0; i < NO_OF_BITS; i++)
	{
		((num << i) & mask) ? printf("1") : printf("0");
	}

	printf("\n");
}

/**
 *
 * @name forthleastsignbit
 *
 * @brief This function takes an integer as an argument and returns the 4th least
 * significant bit (bit 3) as an integer.
 *
 * @param num The integer to extract the 4th least significant bit from.
 *
 * @return The 4th least significant bit as an integer.
 */
int forthleastsignbit(int num)
{
	return ((num & 0x00000008) >> 3);
}

/**
 * @name FallingEdgeCounter
 * @brief This function takes an integer as an argument that represents the current
 * state of a pin. It returns the accumulative sum of the falling edges (state change
 * from 1 to 0) of the pin.
 *
 * @param pin_current The current state of the pin, either 0 or 1.
 *
 * @return The accumulative sum of the falling edges of the pin.
 */
int FallingEdgeCounter(int pin_current)
{
	static char previous = 0;	  /* variable contains the previous pin value */
	static int falling_count = 0; /* variable contains the accumulative sum of the falling edges */

	if ((pin_current == 0) && (previous == 1))
	{
		falling_count++;
	}

	previous = pin_current;

	return falling_count;
}
/**
 * @name RisingEdgeCounter
 * @brief This function takes an integer as an argument that represents the current
 * state of a pin. It returns the accumulative sum of the raising edges (state change
 * from 0 to 1) of the pin.
 *
 * @param pin_current The current state of the pin, either 0 or 1.
 *
 * @return The accumulative sum of the raising edges of the pin.
 */
int RisingEdgeCounter(int pin_current)
{
	static char previous = 1;	 /* variable contains the previous pin value */
	static int rising_count = 0; /* variable contains the accumulative sum of the raising edges */

	if ((pin_current == 1) && (previous == 0))
	{
		rising_count++;
	}

	previous = pin_current;

	return rising_count;
}
/**
 * @name RightCircularShift
 *
 *
 * @details This function performs a right circular shift on the given InputNumber for
 * NumberOfShifts number of times. The result is stored in the memory location
 * pointed to by pOutput. The function returns 0 if the shifting is successful,
 * otherwise it returns 0xFF.
 *
 * @param InputNumber The number to be right circular shifted.
 *
 * @param NumberOfShifts The number of times the right circular shift is to be
 * performed.
 *
 * @param pOutput A pointer to a memory location where the result of the right
 * circular shift is to be stored.
 *
 * @return 0 if the shifting is successful, otherwise 0xFF.
 */
unsigned char RightCircularShift(unsigned int InputNumber, int NumberOfShifts, unsigned int *pOutput)
{
	if (NumberOfShifts > (8 * sizeof(InputNumber)))
	{
		*pOutput = InputNumber;
		return 0xFF;
	}
	// the function needs to return 2 outputs 1 by using return and the other pass by address
	else
	{
		*pOutput = (InputNumber >> NumberOfShifts) | (InputNumber << ((8 * sizeof(InputNumber)) - NumberOfShifts));
		return 0;
	}
}
/**
 * @name ClearBit
 *
 * @details This function takes an unsigned integer Number and an unsigned integer
 * BitNumber as arguments. It clears the bit at position BitNumber in the given
 * Number and returns the resulting number.
 *
 * @param Number The number to clear the bit in.
 *
 * @param BitNumber The position of the bit to clear.
 *
 * @return The resulting number with the bit cleared.
 */
unsigned int ClearBit(unsigned int Number, unsigned int BitNumber)
{
	if (BitNumber >= (sizeof(Number) * 8))
		return Number;
	else
		return (Number & ~(1 << BitNumber));
}
/**
 * @name reverseBits
 * @details This function takes an unsigned char number as an argument and reverses
 * the order of its bits.
 *
 * @param num The number to reverse the bits of.
 *
 * @return The reversed number.
 */
unsigned char reverseBits(unsigned char num)
{
	unsigned char NO_OF_BITS = sizeof(num) * 8;
	unsigned char reverse_num = 0, i;

	/*
	 * start looping from index 0 to n-1 and check every bit
	 * if it is equals to one we need to set the reverse bit location value to one
	 * if it is zero do no nothing as the reverse bit location equals to zero (reverse_num = 0 as initial value)
	 */
	for (i = 0; i < NO_OF_BITS; i++)
	{
		/* check if this bit is equals to one */
		if (num & (1 << i))
			reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
	}

	return reverse_num;
}

int main(void)
{
	/* set stdout and stderr to unbuffered mode to solve the problema of printf and scanf */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int task;
	printf("Enter the specific task to operate:\n");
	scanf("%d", &task);
	/* switch case for the specific task */
	switch (task)
	{
	case 1:
	{
		char Reg = 0b10000001;
		int num;
		printf("Enter the bit number:\n");
		scanf("%d", &num);
		int bit_value = GET_BIT(Reg, num);
		printf("%d", bit_value);
		break;
	}
	case 2:
	{
		int arr[] = {1, 2, 3, 4, 5};
		printf("%d", ARRAY_SUM(arr, Arr_Size));
		break;
	}
	case 3:
	{
		int num;
		printf("Enter the number:\n");
		scanf("%d", &num);
		printf("%d", forthleastsignbit(num));
		break;
	}
	case 4:
	{
		char count = 0;

		count = FallingEdgeCounter(1);

		count = FallingEdgeCounter(1);

		/* falling edge the count should be equal 1 */
		count = FallingEdgeCounter(0);

		count = FallingEdgeCounter(1);

		/* falling edge the count should be equal 2 */
		count = FallingEdgeCounter(0);

		count = FallingEdgeCounter(0);

		count = FallingEdgeCounter(1);

		/* falling edge the count should be equal 3 */
		count = FallingEdgeCounter(0);

		printf("count = %d", count);

		break;
	}
	case 5:
	{
		char count = 0;
		count = RisingEdgeCounter(1);

		count = RisingEdgeCounter(0);

		/* raising edge the count should be equal 1 */
		count = RisingEdgeCounter(1);

		count = RisingEdgeCounter(1);

		count = RisingEdgeCounter(0);

		/* raising edge the count should be equal 2 */
		count = RisingEdgeCounter(1);

		count = RisingEdgeCounter(0);

		/* raising edge the count should be equal 3 */
		count = RisingEdgeCounter(1);

		printf("count = %d", count);

		break;
	}
	case 6:
	{
		unsigned int num = 255; /* binary = 00000000 00000000 00000000 11111111 */
		unsigned int output = 0;
		unsigned char error_status = 0;

		error_status = RightCircularShift(num, 2, &output);

		if (error_status == 0)

			printf("count = %u\n", output); /* it should be equals to 11000000000000000000000000111111 */

		else if (error_status == 0xFF)

			printf("The number of shifts must be less than or equal 32 for unsigned int\n");

		error_status = RightCircularShift(num, 40, &output);

		if (error_status == 0)

			printf("count = %u\n", output);

		else if (error_status == 0xFF)

			printf("The number of shifts must be less than or equal 32 for unsigned int\n");

		break;
	}
	case 7:
	{
		int num, bit;
		printf("Enter the number:\n");
		scanf("%d", &num);
		printf("Enter the bit number:\n");
		scanf("%d", &bit);
		printf("%d", ClearBit(num, bit));
		break;
	}
	case 8:
	{
		unsigned char num1 = 0b11010001;
		unsigned char num2;

		/* Reverse num1 and put the new value in num2 */
		num2 = reverseBits(num1);

		/* print the value of num2 */
		print_binary(num2);
		break;
	}
	case 9:
	{

		break;
	}

	default:
		printf("You have entered an invalid task number\n");
	}
}
