#include "main.h"

int run_printf(const char *format, va_list args);
int _printf(const char *format, ...);


/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
		//	flags = handle_flags(format + i + 1, &tmp);
		//	wid = handle_width(args, format + i + tmp + 1, &tmp);
		//	prec = handle_precision(args, format + i + tmp + 1,
		//			&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy((format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args);

	return (ret);
}
