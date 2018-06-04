#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "date.h"
#include "sysdate.h"

#define NUMBER_OF_ARGUMENTS 3
#define FLAG "-fmt"
#define FLAG_POSITION 1
#define FORMAT_POSITION 2

status_t validate_arguments(int, char**, size_t *);

int main(int argc, char * argv[]) {
    size_t format;

    if((st = validate_arguments(argc, argv, &format)) != OK) return st;
    if((st = sysdate(format, stdout)) != OK) return st;
    return OK;
}

status_t validate_arguments(int argc, char * argv[], size_t * i) {
    if (argc != NUMBER_OF_ARGUMENTS)
        return ERROR_NUMBER_OF_ARGUMENTS;
    if (strcmp(argv[FLAG_POSITION], FLAG) != 0)
        return ERROR_INVALID_ARGUMENTS;
    for (*i = 0; *i < NUMBER_OF_FORMATS; (*i)++) {
        if (!strcmp(argv[FORMAT_POSITION], formats[*i]))
            return OK;
    }
    return ERROR_INVALID_ARGUMENTS;
}


