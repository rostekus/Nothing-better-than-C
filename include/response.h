struct Response {
  int statusCode;
  char *headers;
  char *statusMessage;
  char *contentType;
  char *body;
};

char *createHTTPResponse(const struct Response *response);
char *renderStaticFile(const char *);
struct Response initResponse(int statusCode, char *headers, char *statusMessage,
                             char *contentType, char *body);
