#include <stdlib.h>

#include "network/thread_start.h"

void* thread_start(void* input) { //Actually an int :)
    int* port = (int*)port;

    //https://www.geeksforgeeks.org/socket-programming-cc/ See for instructions.

    //TODO: UNHARDCODE port specifiers. Should be passed to thread :0
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    //AF_INET6 for ipv6
    //SOCK_DGRAM for udp
    //protocol 0 for internet protocol, search for others. See \/\/
    //----https://docs.oracle.com/cd/E88353_01/html/E37852/protocols-5.html#REFMAN5protocols-5

    int b_log = 0;
    int listen_id = listen(sock_fd, b_log);

    free(input);
    return NULL;
}