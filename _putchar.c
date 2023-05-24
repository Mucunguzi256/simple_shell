#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _vfprintf - fanction that
 * @stream: param1
 * @format: param2
 * @args: param3
*/

void _vfprintf(FILE *stream, const char *format, va_list args)
{
    int value1;
    char *value2;

    while (*format) {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                {
                    value1 = va_arg(args, int);
                    _fprintf(stream, "%d", value1);
                    break;
                }
                case 's':
                {
                    value2 = va_arg(args, char *);
                    _fprintf(stream, "%s", value2);
                    break;
                }
                case 'c':
                {
                    value1 = va_arg(args, int);
                    _fprintf(stream, "%c", value1);
                    break;
                }
                case '%':
                {
                    fprintf(stream, "%%");
                    break;
                }
                default:
                {
                    _fprintf(stream, "Invalid format specifier");
                    break;
                }
            }
        }
        else
        {
            _fprintf(stream, "%c", *format);
        }
        format++;
    }
}

/**
 * _fprintf - function
 * @stream: file
 * @format: format
 * Return: nothing
*/
void _fprintf(FILE *stream, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    _vfprintf(stream, format, args);
    va_end(args);
}
