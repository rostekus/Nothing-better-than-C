#ifndef HANDLER_H
#define HANDLER_H

struct Handler {

    char* method;
    char* (*handlerFunc)(char*);

};

struct Handler* initHandler(char*(*handlerFunc)(char*), char* method);

char * handle(struct Handler * handler, char* message);

#endif //HANDLER_H