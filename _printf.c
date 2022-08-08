#include "main.h"
  2
  3 /**
  4  * _printf - produces output according to a format
  5  * @format: format string containing the characters and the specifiers
  6  * Description: this function will call the get_print() function that will
  7  * determine which printing function to call depending on the conversion
  8  * specifiers contained into fmt
  9  * Return: length of the formatted output string
 10  */
 11 int _printf(const char *format, ...)
 12 {
 13         int (*pfunc)(va_list, flags_t *);
 14         const char *p;
 15         va_list arguments;
 16         flags_t flags = {0, 0, 0};
 17
 18         register int count = 0;
 19
 20         va_start(arguments, format);
 21         if (!format || (format[0] == '%' && !format[1]))
 22                 return (-1);
 23         if (format[0] == '%' && format[1] == ' ' && !format[2])
 24                 return (-1);
 25         for (p = format; *p; p++)
 26         {
 27                 if (*p == '%')
 28                 {
 29                         p++;
 30                         if (*p == '%')
 31                         {
 32                                 count += _putchar('%');
 33                                 continue;
 34                         }
 35                         while (get_flag(*p, &flags))
 36                                 p++;
 37                         pfunc = get_print(*p);
 38                         count += (pfunc)
 39                                 ? pfunc(arguments, &flags)
 40                                 : _printf("%%%c", *p);
 41                 } else
 42                         count += _putchar(*p);
 43         }
 44         _putchar(-1);

