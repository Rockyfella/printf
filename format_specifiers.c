#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int len = 0;
    const char *p = format;

    while (*p != '\0')
    {
        if (*p == '%')
        {
            switch (*(++p))
            {
                case 'd':
                case 'i':
                {
                    int arg = va_arg(args, int);
                    len += printf("%d", arg);
                    break;
                }
                default:
                    putchar('%');
                    putchar(*p);
                    len += 2;
            }
        }
        else
        {
            putchar(*p);
            len++;
        }

        p++;
    }

    va_end(args);
    return len;
}
