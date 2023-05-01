#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Request* initRequest(char *method, char *uri) {
    // allocate memory for a Request struct
    Request *req = malloc(sizeof(Request));
    
    // allocate memory for the method string
    req->method = malloc(strlen(method) + 1);
    strcpy(req->method, method);
    
    // allocate memory for the uri string
    req->uri = malloc(strlen(uri) + 1);
    strcpy(req->uri, uri);
    
    return req;
}