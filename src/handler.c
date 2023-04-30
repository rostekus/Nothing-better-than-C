#include "handler.h"

#include <stddef.h>

#include <stdlib.h>


struct Handler* initHandler(char*(*handlerFunc)(char*), char * method){
    struct Handler* temp = (struct Handler *)malloc(sizeof(struct Handler));
    temp -> handlerFunc = handlerFunc;
    temp -> method = method;
    return temp;
}

char * handle(struct Handler * handler, char* message){
    return handler -> handlerFunc(message);
}