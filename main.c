#include "monty.h"
stack_t *head = NULL;

/**
 * Entry point for the program that [briefly describe its purpose].

 * @param argc: The number of command-line arguments passed to the program.
 * @param argv: An array of pointers to the strings representing the command-line arguments.

 * This function performs the following steps:

 * 1. [Mention key function calls related to program logic].
 * 2. [Optionally, mention how arguments are used if relevant].
 * 3. ...

 * @return: 0 to indicate successful execution.

 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * Creates and allocates memory for a new node in the [describe data structure type].

 * @param n: The integer value to be stored within the node.

 * @return: A pointer to the newly created node on success.

 * This function:

 * 1. Allocates memory for the entire node structure.
 * 2. Initializes the node's data field with the provided `n` value.
 * 3. Sets any other necessary fields within the node (if applicable).

 * If memory allocation fails or the provided `n` is invalid, this function returns NULL.

 * The created node might require further operations like insertion into the data structure depending on your program logic.

 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * Frees all nodes currently present in the stack.

 * This function iterates through the stack and releases the memory allocated for each node.
 * After completing the process, the stack will be empty.

 * Note: This function assumes proper stack initialization and handling.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * Adds a newly created node to the back of the FIFO queue.

 * @param new_node: Pointer to the node to be inserted into the queue.

 * @param ln: The line number where the add operation was encountered (used for potential error reporting).

 * This function:

 * 1. Allocates memory for a new node if `new_node` is not already created.
 * 2. Initializes the new node's data fields based on the required format.
 * 3. Inserts the new node at the back of the queue, maintaining the FIFO order.
 * 4. Updates internal queue references and pointers as necessary.

 * If memory allocation fails or the queue is full, the function handles the error appropriately (e.g., error message, return code).

 * Note: The specific queue implementation and error handling details might differ based on your program logic.

 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
