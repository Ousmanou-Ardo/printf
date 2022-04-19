#ifndef MACRONI_H
#define MACRONI_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int _printf(const char *format, ...);
int run_printf(const char *format, va_list args);

#endif /* MACRONI_H */
