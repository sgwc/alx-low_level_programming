#include "3-calc.h"
#include <stdio.h>

/**
 * op_add - calculates the sum of a and b
 * @a: first operand
 * @b:	second operand
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract b from a
 * @a: first operand
 * @b: second operand
 *
 * Return: difference a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply a and b
 * @a: fist operand
 * @b: second operand
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divide a with b
 * @a: denom
 * @b: neom
 *
 * Return: division
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder of a when divided by b
 * @a: dividend
 * @b: divider
 *
 * Return: remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
