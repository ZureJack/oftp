#ifndef O_LOG_H
#define O_LOG_H
#include "common.h"
#include <stdarg.h>

enum class OlogLevel
{
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    FATAL,
};


struct Olog;
API Olog *olog_init(OlogLevel level, const char *path);
API void olog_uninit(Olog **hdl);
API void olog_set_level(Olog *hdl, OlogLevel level);
API void olog(Olog *hdl, OlogLevel level, const char *fmt, ...);


#endif