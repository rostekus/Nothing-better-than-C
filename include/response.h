struct Response {
    int status_code;
    char* status_message;
    char* content_type;
    char* body;
};

struct Response createDefaultResponse();
char* toHTTPString(struct Response* response);
char * renderStaticFile(char * fileName);
