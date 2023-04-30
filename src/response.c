#include "response.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Response createDefaultResponse() {
    struct Response response;
    response.status_code = 200;
    response.status_message = "OK";
    response.content_type = "text/plain";
    response.body = "Hello, world!";
    return response;
}

char* toHTTPString(struct Response* response) {
    char* http_string = (char*) malloc(sizeof(char) * 1024); // allocate memory for the HTTP string
    snprintf(http_string, 1024, "HTTP/1.1 %d %s\r\nContent-Length: %ld\r\n\r\n%s", 
        response->status_code, response->status_message, strlen(response->body), response->body);
    return http_string;
}


char * renderStaticFile(char * fileName) {
	FILE* file = fopen(fileName, "r");

	if (file == NULL) {
		return NULL;
	}else {
		printf("%s does exist \n", fileName);
	}

	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* temp = malloc(sizeof(char) * (fsize+1));
	char ch;
	int i = 0;
	while((ch = fgetc(file)) != EOF) {
		temp[i] = ch;
		i++;
	}
	fclose(file);
	return temp;
}
