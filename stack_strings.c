#include "monty.h"

/**
 * Prints the character stored in the top node of the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack (assumed to contain a character).

 * @param line_number: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function retrieves the character data from the top node and prints it to the output.

 * Note: The function assumes the top node contains valid character data. If not, the behavior might be undefined.

 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * Prints the string stored in the data field of the top node on the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack (assumed to contain a string).

 * @param ln: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function retrieves the string data from the top node and prints it to the output.

 * Note: The function assumes the top node contains valid string data. If not, the behavior might be undefined.

 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * Performs a left rotation on the stack, moving the first node to the bottom.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param ln: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function detaches the first node from the top of the stack and inserts it as the new last node. All other nodes move up one position.

 * Note: The function assumes the stack contains at least two nodes. If empty, the behavior might be undefined.

 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * Performs a right rotation on the stack, moving the last node to the top.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param ln: (Optional) Line number where the opcode was encountered (useful for debugging).

 * This function detaches the last node from the bottom of the stack and inserts it as the new top node. All other nodes move down one position.

 * Note: The function assumes the stack contains at least two nodes. If empty, the behavior might be undefined.

 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
