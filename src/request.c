#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Request* initRequest(char *method, char *uri){
    Request*temp = (Request*) malloc(sizeof(Request));

    temp -> method = method;
    temp -> uri = uri;

    return temp;
}