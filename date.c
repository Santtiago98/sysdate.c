#include <stdio.h>
#include "date.h"

char *formats[MAX_FORMATS]=
        {
                "DDMMAAAA",/*format 1*/
                "AAAADDD", /*format 2*/
                "AAAAMMDDHHmmSS", /*format 3*/
                "AAAADDDHHmmSS" /*format 4*/
        };

status_t (*print_date_as[MAX_FORMATS])(struct tm * date, FILE * stream)={
        print_date_as_format_1,
        print_date_as_format_2,
        print_date_as_format_3,
        print_date_as_format_4};


status_t print_date_as_format_1(struct tm * ptr, FILE * stream)
{
    char str[MAX_LEN];

    if (ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%d/%m/%Y",ptr);
    fprintf(stream, "%s\n",str);
    return OK;
}
status_t print_date_as_format_2(struct tm * ptr, FILE * stream)
{
    char str[MAX_LEN];

    if (ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%j",ptr);
    fprintf(stream, "%s\n",str);
    return OK;
}
status_t print_date_as_format_3(struct tm * ptr, FILE * stream)
{
    char str[MAX_LEN];

    if (ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%m/%d/%H:%M:%S",ptr);
    fprintf(stream, "%s\n",str);
    return OK;
}
status_t print_date_as_format_4(struct tm * ptr, FILE * stream)
{
    char str[MAX_LEN];

    if (ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%j/%H:%M:%S",ptr);
    fprintf(stream, "%s\n",str);
    return OK;
}

