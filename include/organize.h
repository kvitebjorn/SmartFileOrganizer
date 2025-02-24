#ifndef SFO_ORGANIZE_H
#define SFO_ORGANIZE_H
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "file_type_detector.h"
#include "errors.h"

int8_t organize(const char *path);

#endif