#include <stdarg.h>
#include <stdio.h>

case 'b':
{
    /* Extract the unsigned int argument */
    unsigned int num = va_arg(args, unsigned int);
    
    /* Convert the number to binary and print it */
    int bits[sizeof(unsigned int) * CHAR_BIT];
    int i = 0;
    do {
        bits[i++] = num % 2;
        num /= 2;
    } while (num > 0);

    while (i-- > 0) {
        _putchar(bits[i] ? '1' : '0');
    }
    printed_chars += sizeof(unsigned int) * CHAR_BIT;
    break;
}
