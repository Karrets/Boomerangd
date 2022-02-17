#pragma once
#ifndef BOOMERANGD_UTIL_H
#define BOOMERANGD_UTIL_H

#include "util/flags.h"
#include "network/thread_start.h"

typedef struct {
    void (*daemonize)();
    void (*cleanup)();
    void (*print)(int, const char*, ...);
    void (*thread_start)(void*);

    Flags flags;
} Util;

static Util utils;

Util makeUtil();

#endif //BOOMERANGD_UTIL_H