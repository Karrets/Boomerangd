#include "util/util.h"

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void daemonize() {
/*
* This example daemonizes a process, writes a few log messages,
* sleeps 20 seconds and terminates afterwards.
* This is an answer to the stackoverflow question:
* https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux/17955149#17955149
* (THANK YOU PASCAL WERKL <3)
*/

    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Success: Let the parent terminate */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    /* On success: The child process becomes session leader */
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    /* Catch, ignore and handle signals */
    /*TODO: Implement a working signal handler */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Success: Let the parent terminate */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    /* Set new file permissions */
    umask(0);

    /* Change the working directory to the root directory */
    /* or another appropriated directory */
    chdir("/");

    /* Close all open file descriptors */
    int x;
    for (x = (int)sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }
}

void print(int level, const char* fstring, ...) {
    va_list args;
    va_start(args, fstring);

    if(utils.flags.daemon) {
        vsyslog(level, fstring, args);
    } else {
        char* prefix;

        switch(level) {
            case 0:
                prefix = "EMERG : ";
                break;
            case 1:
                prefix = "ALERT : ";
                break;
            case 2:
                prefix = "CRIT  : ";
                break;
            case 3:
                prefix = "ERR   : ";
                break;
            case 4:
                prefix = "WARN  : ";
                break;
            case 5:
                prefix = "NOTICE:";
                break;
            case 6:
                prefix = "INFO  : ";
                break;
            case 7:
                prefix = "DEBUG : ";
                break;
            default:
                prefix = "UNKWN : ";
                break;
        }

        char* format = malloc(strlen(prefix) + strlen(fstring));
        strcat(format, prefix); //strcat appends to first string, it doesn't return!
        strcat(format, fstring);

        vprintf(format, args);

        free(format);
    }

    va_end(args);
}

void cleanup() {
    closelog();
}

Util makeUtil() {
    openlog("Boomerangd", LOG_PID, LOG_DAEMON);

    Util util;

    util.daemonize = &daemonize;
    util.cleanup = &cleanup;
    util.print = &print;
    util.thread_start = &thread_start;

    util.flags = makeFlags();

    return util;
}
