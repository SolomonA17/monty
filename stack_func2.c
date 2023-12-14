#include "monty.h"

/**
 * Executes a no-operation instruction.

 * @param stack: Pointer to a pointer pointing to the top node of the stack (unused in this case).

 * @param line_number: Line number where the opcode was encountered (optional for debugging).

 * This function serves as a placeholder and performs no action. 
 * It might be used intentionally within your program logic for control flow or 
 * reserving space in the instruction sequence.

 * Note: The unused arguments are explicitly cast to `void` to avoid compiler warnings.

 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * Swaps the top two elements of the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function swaps the data and pointers of the top two nodes in the stack. This effectively reverses the order of these two elements.

 * Note: 

 * - The function assumes there are at least two elements in the stack to swap. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any internal stack updates performed besides swapping the nodes.

 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * Adds the top two elements of the stack and pushes the sum onto the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function:

 * 1. Pops the top two elements from the stack.
 * 2. Calculates the sum of their data values (assuming they are numeric).
 * 3. Creates a new node containing the sum as its data.
 * 4. Pushes the new node onto the top of the stack.

 * Note:

 * - The function assumes there are at least two elements in the stack to add. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).
 * - The specific data type and addition operation might differ based on your program logic.

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any potential overflow handling for large values.

 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Subtracts the top element from the second element and pushes the difference onto the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function:

 * 1. Pops the top two elements from the stack.
 * 2. Treats the first element as the subtrahend and the second element as the minuend.
 * 3. Calculates the difference between their data values (assuming they are numeric).
 * 4. Creates a new node containing the difference as its data.
 * 5. Pushes the new node onto the top of the stack.

 * Note:

 * - The function assumes there are at least two elements in the stack to subtract. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).
 * - The specific data type and subtraction operation might differ based on your program logic.

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any potential overflow handling for large values or negative results.

 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Divides the second element by the top element and pushes the quotient onto the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function:

 * 1. Pops the top two elements from the stack.
 * 2. Treats the first element as the divisor and the second element as the dividend.
 * 3. Calculates the quotient of their data values (assuming they are numeric).
 * 4. Creates a new node containing the quotient as its data.
 * 5. Pushes the new node onto the top of the stack.

 * Note:

 * - The function assumes there are at least two elements in the stack to divide. If the stack is empty or contains only one element, the function might handle the error appropriately (e.g., throw exception, print error message).
 * - The specific data type and division operation might differ based on your program logic.
 * - Potential division by zero or overflow should be handled appropriately.

 * You can further enhance this comment by mentioning:

 * - The specific data type stored within the nodes for clarity.
 * - Any specific rounding behavior employed for the quotient.

 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
