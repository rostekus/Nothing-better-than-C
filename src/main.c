#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <fcntl.h>

#include <unistd.h>

#include <errno.h>

#include "server.h"

#include "routes.h"

#include "response.h"

#include "utils.h"

#include "request.h"

int main(int argc, char *argv[]) {

  // default port 80
  const short port = getPort(argc, argv);
  struct Route *route = initRoute("/", "GET", "index.html");
  addRoute(route, "/about", "GET", "about.html");

  HTTP_Server http_server;
  initServer(&http_server, port, route);
  serveRoutes(&http_server);
  return 0;
}
