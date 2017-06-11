#include<stdio.h>
#include<stdlib.h>
#include "log.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void log_error(const char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

void log_info_term(const char *msg) {
    printf("%s\n", msg);
}
