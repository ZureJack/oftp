#include "log.h"
#include <stdio.h>



STATIC const char* get_level_str(OlogLevel level) {
    switch (level) {
        case OlogLevel::DEBUG: return "DEBUG";
        case OlogLevel::INFO:  return "INFO";
        case OlogLevel::WARN:  return "WARN";
        case OlogLevel::ERROR: return "ERROR";
        case OlogLevel::FATAL: return "FATAL";
        default: return "UNKNOWN";
    }
}
STATIC void get_current_date(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(buffer, size, "%Y%m%d", tm);
}
STATIC size_t get_current_time(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    return strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm);
}
STATIC INLINE bool check_level_valid(OlogLevel level)
{
    return (level >= OlogLevel::DEBUG && level <= OlogLevel::FATAL);
}


Olog *olog_init(OlogLevel level, const char *path)
{
    if (!check_level_valid(level) || NULL == path)
    {
        return NULL;
    }

    Olog *ptr =  (Olog *)omem_alloc(sizeof(Olog));
    if (NULL == ptr)
    {
        return NULL;
    }
    
    FILE *fp = fopen(path, "a");
    if (NULL == fp)
    {
        omem_free(ptr);
        return NULL;
    }
    setvbuf(fp, NULL, _IOLBF, 0);

    ptr->log_file = fp;
    ptr->level = level;
    
    return ptr;
}
void olog_uninit(Olog **hdl)
{
    if (NULL == hdl || NULL == *hdl)
    {
        return;
    }
    Olog *ptr = *hdl;

    fclose(ptr->log_file);
    omem_free(ptr);
    *hdl = NULL;
}
void olog_set_level(Olog *hdl, OlogLevel level)
{
    if (NULL == hdl)
    {
        return ;
    }
    if (!check_level_valid(level))
    {
        return ;
    }

    hdl->level = level;

}
/**
* 日志格式：年 月 日 h:m:s [level] log_str
*/
void olog_ex(Olog *hdl, OlogLevel level, const char *fmt, va_list ap)
{
    if (!check_level_valid(level) || level < hdl->level)
    {
        return;
    }

    if (NULL == hdl || NULL == fmt)
    {
        return ;
    }
    char *buf = hdl->log_cache;
    size_t buf_len = sizeof(hdl->log_cache);
    size_t used_len = get_current_time(buf, buf_len);
    buf[used_len] = ' ';
    used_len++;
    buf[used_len] = '[';
    used_len++;
    
    ;
    int tmp = snprintf(&buf[used_len], buf_len - used_len, "%s", get_level_str(level));
    if (tmp < 0)
    {
        return;
    }
    used_len += tmp;
    buf[used_len] = ']';
    used_len++;
    buf[used_len] = ' ';
    used_len++;
    tmp = vsnprintf(&buf[used_len], buf_len - used_len, fmt, ap);
    if (tmp < 0)
    {
        return;
    }
    used_len += tmp;
    buf[used_len] = '\0';

    fprintf(hdl->log_file, "%s\n", buf);

}
void olog(Olog *hdl, OlogLevel level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    olog_ex(hdl, level, fmt, args);
    va_end(args);
}
