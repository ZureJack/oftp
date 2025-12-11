#ifndef O_PRIVATE_LOG_H
#define O_PRIVATE_LOG_H
#include "common.h"
#include "log/log.h"
#include <assert.h>
#include <time.h>
#include "mem/mem.h"

struct Olog
{
    OlogLevel level;
    FILE *log_file;
    char log_cache[OFTP_BUF_LEN];
    
};

STATIC const char* get_level_str(OlogLevel level);
STATIC void get_current_date(char* buffer, size_t size);
STATIC size_t get_current_time(char* buffer, size_t size);
STATIC INLINE bool check_level_valid(OlogLevel level);



#endif