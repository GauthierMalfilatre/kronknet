/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Private logger definition
*/
#ifndef KRONKNET_LOGGER_H
    #define KRONKNET_LOGGER_H

typedef enum kronknet_log_type_e {

    knLogTrace = 0,
    knLogDebug,
    knLogInfo,
    knLogWarn,
    knLogError,
    knLogFatal

} knLogType;

void knLogger_log(knLogType _type, const char *_file, int _line, const char * restrict _fmt, ...);

#ifndef KNDEBUG
    #define knTrace(fmt, ...) knLogger_log(knLogTrace, NULL, 0, fmt, ##__VA_ARGS__)
    #define knDebug(fmt, ...) knLogger_log(knLogDebug, NULL, 0, fmt, ##__VA_ARGS__)
    #define knInfo(fmt, ...) knLogger_log(knLogInfo,  NULL, 0, fmt, ##__VA_ARGS__)
    #define knWarn(fmt, ...) knLogger_log(knLogWarn,  NULL, 0, fmt, ##__VA_ARGS__)
    #define knError(fmt, ...) knLogger_log(knLogError, NULL, 0, fmt, ##__VA_ARGS__)
    #define knFatal(fmt, ...) knLogger_log(knLogFatal, NULL, 0, fmt, ##__VA_ARGS__)
#else
    #define knTrace(fmt, ...) knLogger_log(knLogTrace, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define knDebug(fmt, ...) knLogger_log(knLogDebug, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define knInfo(fmt, ...) knLogger_log(knLogInfo,  __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define knWarn(fmt, ...) knLogger_log(knLogWarn,  __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define knError(fmt, ...) knLogger_log(knLogError, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define knFatal(fmt, ...) knLogger_log(knLogFatal, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#endif /* KNDEBUG */

#endif /* KRONKNET_LOGGER_H */
