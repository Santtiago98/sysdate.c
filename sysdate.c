#include <stdio.h>
#include <time.h>
#include <string.h>
#include "errors.h"
#include "types.h"

/*Diccionario con los formatos permitidos*/
char *formats[MAX_FORMATS]=
{
        "DDMMAAAA",/*format 1*/
        "AAAADDD", /*format 2*/
        "AAAAMMDDHHmmSS", /*format 3*/
        "AAAADDDHHmmSS" /*format 4*/
};

/*Diccionario con los formatos para su implementacion*/
char *types_formats[MAX_FORMATS]=
{
        "%d/%m/%Y", /*format 1*/
        "%Y/%j", /*format 2*/
        "%Y/%m/%d %H:%M:%S", /*format 3*/
        "%Y/%j %H:%M:%S" /*format 4*/
};

status_t validate_arguments(int argc,char *argv[],int *p)
{
    int i,n;


    *p=-1;
    if(argc!=NUMBER_OF_ARGUMENTS) return ERROR_WITH_NUMBER_OF_ARGUMENTS;
    if ((n=strcmp(argv[1],FORMAT_FLAG))) return ERROR_INVALID_ARGUMENTS;
    for (i=0;i<=MAX_FORMATS-1;i++)
    {
        if ((n=strcmp(argv[FORMAT_POSC],formats[i]))==0)
        {
            *p=i;
            break;
        }
    }
    if ((*p)!=-1)
    {
        return OK;
    }
    return ERROR_INVALID_ARGUMENTS;
}

status_t print_date_as_format_1(char *str, struct tm * ptr)
{
    if (str==NULL || ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%d/%m/%Y",ptr);
    printf("%s\n",str);
    return OK;
}

status_t print_date_as_format_2(char *str, struct tm * ptr)
{
    if (str==NULL || ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%j",ptr);
    printf("%s\n",str);
    return OK;
}
status_t print_date_as_format_3(char *str, struct tm * ptr)
{
    if (str==NULL || ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%m/%d/%H:%M:%S",ptr);
    printf("%s\n",str);
    return OK;
}
status_t print_date_as_format_4(char *str, struct tm * ptr)
{
    if (str==NULL || ptr ==NULL) return ERROR_NULL_POINTER;
    strftime(str,8*sizeof(size_t),"%Y/%j/%H:%M:%S",ptr);
    printf("%s\n",str);
    return OK;
}

/*Arreglo de punteros a funciones*/
status_t ((*functions[MAX_FORMATS])(char *str, struct tm *ptr))=
{
        print_date_as_format_1,
        print_date_as_format_2,
        print_date_as_format_3,
        print_date_as_format_4
};


int main(int argc, char *argv[])
{
    time_t secs;
    status_t st;
    int i;
    char str_time[MAX_SPACE];
    struct tm *ptr;

    if((st=validate_arguments(argc,argv,&i))!=OK)
    {
        return st;
    }
    secs=time(NULL);
    ptr=localtime(&secs);
    /*
    strftime(str_time,40,types_formats[i],ptr);
    fprintf(stdout,"%s\n",str_time);*/
    functions[i](str_time,ptr);


    return 0;
}
