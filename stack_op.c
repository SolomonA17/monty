#include "monty.h"

/**
 * Multiplies the top two elements of the stack and pushes the product onto the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function:

 * 1. Pops the top two elements from the stack.
 * 2. Calculates the product of their data values (assuming they are numeric).
 * 3. Creates a new node containing the product as its data.
 * 4. Pushes the new node onto the top of the stack.

 * Note:

 * - The function assumes there are at least two elements in the stack to multiply. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).
 * - The specific data type and multiplication operation might differ based on your program logic.
 * - Depending on your intended behavior, you may want to consider how to handle potential overflow for large values.

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any specific rounding behavior employed for the product.

 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Calculates the modulo of the second element by the top element and pushes the remainder onto the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function:

 * 1. Pops the top two elements from the stack.
 * 2. Treats the first element as the divisor and the second element as the dividend.
 * 3. Calculates the modulo of their data values (assuming they are numeric).
 * 4. Creates a new node containing the modulo as its data.
 * 5. Pushes the new node onto the top of the stack.

 * Note:

 * - The function assumes there are at least two elements in the stack to calculate the modulo. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).
 * - The specific data type and modulo operation might differ based on your program logic.
 * - Depending on your intended behavior, you may want to consider how to handle negative values and potential division by zero.

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any specific rounding behavior employed for the modulo.

 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
