#include "errors.h"

char * errors[MAX_ERRORS]=
        {
                MSG_OK,
                MSG_ERRORS_NULL_POINTER,
                MSG_ERROR_NUMBER_OF_ARGUMENTS,
                MSG_ERROR_INVALID_ARGUMENTS
        };

status_t print_error_messages (status_t st)
{
  fprintf(stderr, "%s", errors[st]);
  return OK;
}
