#include "main.h"

/**
 * _printf - Prints output according to a format
 * @format: A character string that specifies the output format
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i = 0;
    char buffer[1024];
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    // handle %c conversion specifier
                    break;

                case 's':
                    // handle %s conversion specifier
                    break;

                case 'd':
                case 'i':
                    // handle %d and %i conversion specifiers
                    break;

                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    // handle %u, %o, %x, and %X conversion specifiers
                    break;

                case 'S':
                    // handle %S conversion specifier
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        if (*str >= 32 && *str < 127)
                        {
                            buffer[printed_chars++] = *str;
                        }
                        else
                        {
                            printed_chars += sprintf(&buffer[printed_chars], "\\x%02X", *str);
                        }
                        str++;
                    }
                    break;

                default:
                    // handle invalid conversion specifier
                    break;
            }
        }
        else
        {
            buffer[printed_chars++] = format[i];
        }
        i++;
    }

    va_end(args);

    // Write the remaining characters in the buffer to stdout
    write(1, buffer, printed_chars);

    return printed_chars;
}
