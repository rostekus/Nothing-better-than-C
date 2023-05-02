#include "response.h"

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define RESPONSE_BUFFER_SIZE 4096

char *createHTTPResponse(const struct Response *response) {
  // Allocate memory for the response buffer
  char *response_buffer = malloc(RESPONSE_BUFFER_SIZE);
  if (response_buffer == NULL) {
    perror("malloc");
    return NULL;
  }

  // Construct the response string
  int bytes_written = snprintf(response_buffer, RESPONSE_BUFFER_SIZE,
                               "HTTP/1.1 %d %s\r\n"
                               "Content-Type: %s\r\n"
                               "%s"
                               "Content-Length: %d"
                               "\r\n\r\n"
                               "%s\r\n\r\n",
                               response->statusCode, response->statusMessage,
                               response->contentType,
                               response->headers ? response->headers : "",
                               (int)strlen(response->body), response->body);

  if (bytes_written < 0 || bytes_written >= RESPONSE_BUFFER_SIZE) {
    fprintf(stderr, "Failed to create HTTP response\n");
    free(response_buffer);
    return NULL;
  }

  return response_buffer;
}

char *renderStaticFile(const char *filename) {
  char *buffer = NULL;
  long length;
  FILE *file = fopen(filename, "rb");

  if (file) {
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = (char *)malloc(length);
    if (buffer) {
      fread(buffer, 1, length, file);
    }
    fclose(file);
  }
  return buffer;
}

struct Response initResponse(int statusCode, char *headers, char *statusMessage,
                             char *contentType, char *body) {
  struct Response res;
  res.statusCode = statusCode;
  res.headers = (char *)malloc(strlen(headers) + 1);
  strcpy(res.headers, headers);
  res.statusMessage = (char *)malloc(strlen(statusMessage) + 1);
  strcpy(res.statusMessage, statusMessage);
  res.contentType = (char *)malloc(strlen(contentType) + 1);
  strcpy(res.contentType, contentType);
  res.body = (char *)malloc(strlen(body) + 1);
  strcpy(res.body, body);
  return res;
}