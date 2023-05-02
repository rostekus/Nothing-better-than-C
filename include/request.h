#ifndef REQUEST_H
#define REQUEST_H

#define MAX_METHOD_LENGTH 10
#define MAX_URL_LENGTH 10

typedef struct {
  char *method;
  char *uri;
} Request;

Request *initRequest(char *method, char *uri);
#endif