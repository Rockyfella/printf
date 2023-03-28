#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_unsigned - Print an unsigned integer in decimal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
	char buf[32];
	int len;

	len = sprintf(buf, "%u", n);
	write(1, buf, len);

	return (len);
}

/**
 * print_octal - Print an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
	char buf[32];
	int len;

	len = sprintf(buf, "%o", n);
	write(1, buf, len);

	return (len);
}

/**
 * print_hex - Print an unsigned integer in hexadecimal format
 * @n: The unsigned integer to print
 * @uppercase: Whether to use uppercase letters for the hexadecimal digits
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	char buf[32];
	int len;

	if (uppercase)
		len = sprintf(buf, "%X", n);
	else
		len = sprintf(buf, "%x", n);

	write(1, buf, len);

	return (len);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len;
	unsigned int u;

	va_start(args, format);

	len = 0;

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			len++;
			continue;
		}

		i++;

		switch (format[i])
		{
		case 'u':
			u = va_arg(args, unsigned int);
			len += print_unsigned(u);
			break;
		case 'o':
			u = va_arg(args, unsigned int);
			len += print_octal(u);
			break;
		case 'x':
			u = va_arg(args, unsigned int);
			len += print_hex(u, 0);
			break;
		case 'X':
			u = va_arg(args, unsigned int);
			len += print_hex(u, 1);
			break;
		default:
			write(1, &format[i - 1], 2);
			len += 2;
			break;
		}
	}

	va_end(args);

	return (len);
}
