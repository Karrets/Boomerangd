#pragma once
#ifndef BOOMERANGD_UTIL_H
#define BOOMERANGD_UTIL_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

#include "util/flags.h"
#include "network/thread_start.h"

typedef struct {
    void (*daemonize)();
    void (*cleanup)();
    void (*thread_start)(int);

    Flags flags;
} Util;

static Util utils;

void initialize();

#endif //BOOMERANGD_UTIL_H