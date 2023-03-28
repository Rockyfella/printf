#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    char *p = buffer;
    const char *f = format;
    int chars_written = 0;

    va_start(args, format);

    while (*f != '\0') {
        if (*f == '%') {
            f++;
            switch (*f) {
                case 'c':
                    *p++ = (char)va_arg(args, int);
                    break;
                case 's':
                    p += _strcpy(p, va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    p += _itoa(va_arg(args, int), p);
                    break;
                case 'u':
                    p += _utoa(va_arg(args, unsigned int), p);
                    break;
                case 'o':
                    p += _otoa(va_arg(args, unsigned int), p);
                    break;
                case 'x':
                    p += _xtoa(va_arg(args, unsigned int), p, 0);
                    break;
                case 'X':
                    p += _xtoa(va_arg(args, unsigned int), p, 1);
                    break;
                case 'b':
                    p += _uitob(va_arg(args, unsigned int), p);
                    break;
                case '%':
                    *p++ = '%';
                    break;
                default:
                    *p++ = '%';
                    *p++ = *f;
                    break;
            }
        } else {
            *p++ = *f;
        }

        if (p >= buffer + sizeof(buffer)) {
            chars_written += write(1, buffer, p - buffer);
            p = buffer;
        }

        f++;
    }

    va_end(args);

    if (p > buffer) {
        chars_written += write(1, buffer, p - buffer);
    }

    return chars_written;
}
