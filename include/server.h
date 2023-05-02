#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "routes.h"
typedef struct HTTP_Server {
  int socket;
  int port;
  struct Routes *routes;
} HTTP_Server;

void initServer(HTTP_Server *http_server, int port, struct Routes *routes);

void serveRoutes(HTTP_Server *http_server);

#endif
