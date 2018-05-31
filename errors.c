#ifndef ERRORS__H
#define ERRORS__H

#define MAX_ERRORS 4
#define MSG_OK "Ok"
#define MSG_ERROR_NULL_POINTER "Puntero nulo"
#define MSG_ERROR_NUMBER_OF_ARGUMENTS "Número de argumentos erroneo"
#define MSG_ERROR_INVALID_ARGUMENTS "Argumento inválido"

typedef enum
{
    OK,
    ERROR_NULL_POINTER,
    ERROR_WITH_NUMBER_OF_ARGUMENTS,
    ERROR_INVALID_ARGUMENTS

} status_t;

char *errors[MAX_ERRORS]=
{
    MSG_OK,
    MSG_ERROR_NULL_POINTER,
    MSG_ERROR_NUMBER_OF_ARGUMENTS,
    MSG_ERROR_INVALID_ARGUMENTS
};

#endif
