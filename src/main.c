#include <string.h>
#include <syslog.h>
#include <stdlib.h>

#include "util/util.h"

int main(int argc, char **argv) {
    initialize();

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
        syslog(LOG_INFO, "Boomerangd has started!\n");
    }

    //DO STUFF HERE

    //ALL DONE :)

    if(utils.flags.daemon) {
        closelog();
    }

	return EXIT_SUCCESS;
}
