#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Print anything based on the provided format.
 * @format: A format string indicating the types of arguments.
 * @...: The arguments to be printed.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *separator = "";
	unsigned int i = 0;
	char c;
	int i_val;
	float f_val;
	char *s_val;

	va_start(args, format);

	while (format && format[i])
	{
		c = format[i];
		switch (c)
		{
		case 'c':
			printf("%s%c", separator, va_arg(args, int));
			break;
		case 'i':
			printf("%s%d", separator, va_arg(args, int));
			break;
		case 'f':
			printf("%s%f", separator, va_arg(args, double));
			break;
		case 's':
			s_val = va_arg(args, char *);
			if (s_val == NULL)
				s_val = "(nil)";
			printf("%s%s", separator, s_val);
			break;
		default:
			i++;
			continue;
		}
		separator = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}
