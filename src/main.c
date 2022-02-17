#include "util/util.h"

#include <string.h>
#include <syslog.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char **argv) {
    utils = makeUtil();
    int exit = EXIT_SUCCESS;

    for(int arg = 0; arg < argc; arg++) {
        if(strcmp(argv[arg], "--no-daemon") == 0) {
            utils.flags.daemon = false;
        } else
        if(strcmp(argv[arg], "--verbose") == 0) {
            utils.flags.verbose = true;
        }
    }

    if(utils.flags.daemon) {
        utils.daemonize();
    }

    utils.print(LOG_INFO, "Boomerangd has started!\n");

    //DO STUFF HERE
    int* port = malloc(sizeof *port);
    (*port) = 22;

    pthread_t thread;
    int err = pthread_create(&thread, NULL, thread_start, (void*)&port);

    if(err > 0) exit = EXIT_FAILURE;

    //ALL DONE :)


    utils.cleanup();

	return exit;
}
