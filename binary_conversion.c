/**
 * print_binary - prints a number in binary format
 * @n: unsigned int to print in binary format
 *
 * Return: number of printed characters
 */
int print_binary(unsigned int n)
{
    int printed = 0;

    if (n > 1)
        printed += print_binary(n >> 1);
    printed += _putchar((n & 1) + '0');

    return (printed);
}

/**
 * print_unsigned - prints an unsigned int
 * @args: list of arguments
 * @fmt_info: format info struct
 *
 * Return: number of printed characters
 */
int print_unsigned(va_list args, const fmt_t *fmt_info)
{
    unsigned int n = va_arg(args, unsigned int);
    int printed = 0;

    if (fmt_info->specifier == 'b')
        printed += print_binary(n);
    else if (fmt_info->specifier == 'o')
        printed += print_octal(n);
    else if (fmt_info->specifier == 'x')
        printed += print_hex(n, 0);
    else if (fmt_info->specifier == 'X')
        printed += print_hex(n, 1);
    else
        printed += print_number(n, 10, 0, fmt_info);

    return (printed);
}
