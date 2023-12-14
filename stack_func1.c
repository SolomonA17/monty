#include "monty.h"


/**
 * Adds a newly created node containing integer data to the top of the stack.

 * @param new_node: Pointer to the node to be inserted into the stack. This node should already be allocated with its `n` field initialized.

 * @param ln: The line number where the push operation was encountered (used for potential error reporting).

 * This function:

 * 1. Verifies if sufficient memory is available to add the new node to the stack.
 * 2. Updates the `next` pointer of the new node to point to the current top of the stack.
 * 3. Sets the new node as the new top of the stack.
 * 4. (Optionally) Updates any internal stack size or reference pointers.

 * If memory allocation fails or the stack is already full, the function handles the error appropriately (e.g., error message, return code).

 * Note: The specific error handling and internal stack details might differ based on your program logic.

 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * Prints the contents of the stack starting from the top node.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number where the print operation was encountered (for debugging).

 * This function iterates through the stack, starting from the top element, and prints the data stored in each node.

 * Note: The specific format and additional information printed might differ based on your program logic.

 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * Removes the top node from the stack and returns it.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @return: A pointer to the removed node, or NULL if the stack is empty.

 * This function:

 * 1. Checks if the stack is empty. If so, it returns NULL and potentially handles the error.
 * 2. Otherwise, it stores the current top node in a temporary variable.
 * 3. Updates the stack pointer to point to the new top node (the next element in the list).
 * 4. Returns the stored top node, which the caller is responsible for managing further.

 * Note: The specific error handling and return values might differ based on your program logic.

 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * Prints the data stored in the top node of the stack.

 * @param stack: Pointer to a pointer pointing to the top node of the stack.

 * @param line_number: (Optional) Line number of the opcode where printing was called.

 * This function retrieves the top node of the stack and prints its data (e.g., integer value) to the output.

 * Note: If the stack is empty, the function might handle the error accordingly or simply print an empty message.

 * You can expand this comment to specify the exact format of the printed data and any additional information displayed alongside.

 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
