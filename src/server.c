#include "server.h"

#include <netinet/in.h>

#include <stdio.h>

#include <sys/socket.h>

#include <string.h>

#include <stdio.h>

#include <unistd.h>

#include "request.h"

#include "response.h"

void initServer(HTTP_Server *http_server, int port, struct Routes *routes) {
  http_server->port = port;
  http_server->routes = routes;

  int server_fd, new_socket;
  long valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("In sockets");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  memset(address.sin_zero, '\0', sizeof address.sin_zero);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("In bind");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 10) < 0) {
    perror("In listen");
    exit(EXIT_FAILURE);
  }

  http_server->socket = server_fd;
  printf("HTTP Server Initialized\nPort: %d\n", http_server->port);
  printf("Routes:\n");
  displayRoutes(http_server->routes);
  printf("\n");
}

void serveRoutes(HTTP_Server *http_server) {
  int client_socket;
  while (1) {
    char client_msg[4096] = "";
    printf("Listening on port: %d\n", http_server->port);
    client_socket = accept(http_server->socket, NULL, NULL);

    read(client_socket, client_msg, 4095);

    // parsing client socket header to get HTTP method, route
    char *method = "";
    char *urlRoute = "";

    char *client_http_header = strtok(client_msg, "\n");

    char *header_token = strtok(client_http_header, " ");

    int header_parse_counter = 0;

    while (header_token != NULL) {

      switch (header_parse_counter) {
      case 0:
        method = header_token;
      case 1:
        urlRoute = header_token;
      }
      header_token = strtok(NULL, " ");
      header_parse_counter++;
    }

    Request *request = initRequest(method, urlRoute);
    printf("processing request:\n uri: %s\n method: %s\n", request->uri,
           request->method);
    char *pageFilepath = handleRequest(http_server->routes, request);
    char *pageContent = renderStaticFile(pageFilepath);
    free(pageFilepath);

    struct Response response =
        initResponse(200, "Server: Apache\r\n", "OK", "text/html", pageContent);

    char *http_response = createHTTPResponse(&response);
    char http_header[4096] = "";
    strcat(http_header, http_response);
    send(client_socket, http_header, sizeof(http_header), 0);
    close(client_socket);
    free(pageContent);
  }
}