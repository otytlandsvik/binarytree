#include <stdlib.h>
#include <stdio.h>

#include "common.h"

void fatal_error(char *msg)
{
    fprintf(stderr, "fatal error: %s\n", msg);
    exit(1);
}