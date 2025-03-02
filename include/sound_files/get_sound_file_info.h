#ifndef FILE_SOUND_INFO
#define FILE_SOUND_INFO

#include "../errors.h"

#include <sndfile.h>

int get_file_sound_info(const char *file_path, SF_INFO *sf_info);

#endif