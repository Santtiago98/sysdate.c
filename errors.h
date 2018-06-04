#ifndef TYPES__H
#define TYPES__H

#include <stdio.h>


#define MAX_ERRORS 4
#define MSG_OK "Ok"
#define MSG_ERRORS_NULL_POINTER "Puntero nulo"
#define MSG_ERROR_NUMBER_OF_ARGUMENTS "Numero de argumentos incorrectos"
#define MSG_ERROR_INVALID_ARGUMENTS "Argumentos inválidos"

typedef enum
{
    OK,
    ERROR_NULL_POINTER,
    ERROR_NUMBER_OF_ARGUMENTS,
    ERROR_INVALID_ARGUMENTS
} status_t;

status_t st;

char * errors[MAX_ERRORS];

#endif
