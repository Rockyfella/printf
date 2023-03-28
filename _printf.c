#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0;
    char c, *str;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    len++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        len++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    len++;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            len++;
        }
        i++;
    }

    va_end(args);

    return len;
}
