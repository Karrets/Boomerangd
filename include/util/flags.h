#pragma once
#ifndef BOOMERANGD_FLAGS_H
#define BOOMERANGD_FLAGS_H

#include <stdbool.h>

typedef struct {
     bool daemon;
     bool verbose;
} Flags;

Flags makeFlags();

#endif //BOOMERANGD_FLAGS_H
