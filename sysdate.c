#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sysdate.h"

status_t sysdate(size_t i, FILE * stream )
{
    time_t secs;
    struct tm * date;

    secs = time(NULL);
    date = localtime(&secs);
    if((st = (*(print_date_as[i]))(date, stream)) != OK)
        return st;
    
    return OK;
}

