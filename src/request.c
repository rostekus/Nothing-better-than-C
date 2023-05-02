#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Request *initRequest(char *method, char *uri) {
  Request *req = malloc(sizeof(Request));

  req->method = malloc(strlen(method) + 1);
  strcpy(req->method, method);

  req->uri = malloc(strlen(uri) + 1);
  strcpy(req->uri, uri);

  return req;
}