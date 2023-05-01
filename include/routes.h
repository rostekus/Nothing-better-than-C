#ifndef ROUTE_H
#define ROUTE_H

#include <stdlib.h>
#include <string.h>
#include "request.h"
struct Route {
	char* key;
	char* method;
	char* filename;
	struct Route *left, *right;
};

struct Route * initRoute(char* key, char* method,	char* filename);

struct Route * addRoute(struct Route * root, char* key, char* method, 	char* filename);

struct Route * search(struct Route * root, char * key);

void displayRoutes(struct Route * root );

char* handleRequest(struct Route * root, Request* request);
#endif
