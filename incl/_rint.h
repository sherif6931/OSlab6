#ifndef RINT_H
#define RINT_H

#include <unistd.h>

int buf[2];

int sig_init(void) {
    return pipe(buf);
}

ssize_t sig_write(int value) {
    return write(buf[1], &value, sizeof(value));
}

ssize_t sig_read(int *value) {
    return read(buf[0], value, sizeof(*value));
}

#endif