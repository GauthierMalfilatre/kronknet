/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Private logger impl
*/
#include "logger.h"
#include <stdarg.h>
#include <stdio.h>

static const char *__type_names[] = {

    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"

};

void knLogger_log(
    knLogType _type,
    const char *_file,
    int _line,
    const char * restrict _fmt,
    ...
)
{
    // FIXME: Change later to let user define his own FILE * to log into.
    FILE *out = stdout;
    va_list args;

    if (_file) {
        fprintf(out, "%s %s:%d: ", __type_names[_type], _file, _line);
    } else {
        fprintf(out, "%s: ", __type_names[_type]);
    }
    va_start(args, _fmt);
    vfprintf(out, _fmt, args);
    va_end(args);
    fprintf(out, "\n");
    fflush(out);
}
