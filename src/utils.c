#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logger(const char* tag, const char* message) {
   time_t now;
   time(&now);
   printf("%s [%s]: %s\n", ctime(&now), tag, message);
}

short getPort(int argc, char* argv[]){
   return argc > 2 ? atoi(argv[2]) : 80;
}