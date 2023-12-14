#include "monty.h"

/**
 * Opens a file and returns a file stream for writing data.

 * @param file_name: The path to the file to be opened or created.

 * @return: A reference to the opened file stream, or an empty reference if an error occurs.

 * @throws: std::runtime_error: If the file cannot be opened or written to.
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * Reads data from an open file descriptor into a provided user-defined buffer.

 * @param fd: The file descriptor for the previously opened file.

 * @param buffer: A pointer to the user-defined buffer where the read data will be stored.

 * @param buffer_size: The size of the user-defined buffer in bytes.

 * @return: The number of bytes read, or -1 if an error occurs.
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parses a line from the file into tokens and determines which function to call based on the extracted data.

 * @param buffer: The line of text to be parsed, typically containing separated tokens.

 * @param line_number: The line number of the current line being parsed.

 * @param format: An integer flag indicating the expected data structure format:

 *     - 0: Nodes will be entered as a stack (LIFO).
 *     - 1: Nodes will be entered as a queue (FIFO).

 * @return:

 *     - 0 if the parsed data indicates a stack operation.
 *     - 1 if the parsed data indicates a queue operation.
 *     - Additional logic (e.g., error handling) can be implemented based on the parsed data.

 * Note: The specific format of tokens and data values within the line should be clarified in additional documentation.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * Determines the appropriate function to call based on the provided opcode and arguments.

 * @param opcode: The keyword or symbol identifying the desired operation.

 * @param value: The optional argument accompanying the opcode, if applicable.

 * @param format: An integer flag indicating the data structure format:

 *     - 0: Nodes are stored as a stack (Last In First Out).
 *     - 1: Nodes are stored as a queue (First In First Out).

 * @param ln: The line number where the opcode was found (for error reporting).

 * @return: void

 * This function identifies the corresponding function to be called based on the provided
 * `opcode`, potentially considering the `value` and `format` for specialized operations.
 * It typically does not directly execute the function but sets up the necessary context
 * or prepares arguments for proper function invocation.

 * Note: The specific meanings and expected formats of `opcode` and `value` should be
 * clearly documented in separate references or within the function implementation itself.
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * Executes the given function with appropriate arguments parsed from the opcode and value.

 * @param func: A pointer to the function to be called.

 * @param op: The string representing the parsed opcode, identifying the desired operation.

 * @param val: The string representing the parsed numeric value associated with the opcode (optional).

 * @param ln: The line number where the opcode was found (used for error reporting).

 * @param format: An integer flag indicating the data structure format:

 *     - 0: Nodes are stored as a stack (Last In First Out).
 *     - 1: Nodes are stored as a queue (First In First Out).

 * @return: void

 * This function takes the previously parsed information from the opcode and value, including
 * the format, and performs the following actions:

 * 1. Converts the `val` string to the appropriate numeric data type (if applicable).
 * 2. Sets up any necessary context or prepares arguments based on the `format` and operation.
 * 3. Executes the specified function pointed to by `func` with the prepared arguments.
 * 4. Handles any potential errors or exceptions that may occur during the function call.

 * Note: The specific meanings and expected formats of `op` and `val` should be clearly
 * documented in separate references or within the function implementation itself.

 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
