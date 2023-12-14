#include "monty.h"

/**
 * Prints appropriate error messages based on the provided error code.

 * Error codes and their meanings:

 * 1:  The program received either no files or more than one file as input.
 * 2:  The provided file cannot be opened or read.
 * 3:  The file contains an invalid instruction. Please refer to the program documentation for valid instructions.
 * 4:  The program encountered an out-of-memory error while allocating memory.
 * 5:  The parameter passed to the `push` instruction is not an integer.
 * 6:  The stack is empty when trying to perform a `pint` operation.
 * 7:  The stack is empty when trying to perform a `pop` operation.
 * 8:  The stack is too short to perform the desired operation.

 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * `more_err` handles errors by either printing corresponding error messages or taking corrective actions based on the provided error code.

 * Error codes and their meanings:

 * (6-8) => Stack related errors (empty for `pint`, `pop`, or insufficient size).
 * 9:  Division by zero occurred during an operation (please provide context for the operation).

 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * `string_err` handles string-related errors by either printing informative error messages or performing specific actions based on the provided error code.

 * Error codes and their meanings:

 * 10:  The value stored in a node within the string data structure is outside the valid ASCII character range. Please check for invalid data or encoding issues.
 * 11:  The string data structure is empty. This error may occur when attempting to access elements or perform operations on an empty string.

 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
