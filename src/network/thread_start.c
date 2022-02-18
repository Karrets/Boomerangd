#include <stdlib.h>
#include <netinet/in.h>

#include "network/thread_start.h"

void* thread_start(void* input) { //Actually an int :)
    unsigned short port = *(unsigned short*)input;

}