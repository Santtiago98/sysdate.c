#ifndef DATE__H
#define DATE__H

#include <stdio.h>
#include <time.h>
#include "errors.h"

#define MAX_FORMATS 21
#define NUMBER_OF_FORMATS 4
#define MAX_LEN 50

char *formats[MAX_FORMATS];

status_t (*print_date_as[MAX_FORMATS])(struct tm * date, FILE * stream);

status_t print_date_as_format_1(struct tm *, FILE *);
status_t print_date_as_format_2(struct tm *, FILE *);
status_t print_date_as_format_3(struct tm *, FILE *);
status_t print_date_as_format_4(struct tm *, FILE *);

#endif
