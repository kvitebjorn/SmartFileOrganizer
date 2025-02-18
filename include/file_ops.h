#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "utils.h"


#define FILE_PATH_LEN 128

#define PNG_SIGNATURE_SIZE 8u
#define JPG_SIGNATURE_SIZE 3u
#define MP3_SIGNATURE_SIZE 2u 
#define ELF_SIGNATURE_SIZE 4u




// Add more types
enum file_types {
    PNG,
	JPG,
	ELF,
	MP3
};

typedef struct file {
	size_t file_size;
	int    file_format;
	bool   success_analyse;

} file_info;

// Function to get the given file its type
file_info analyse_file(const char *path);
#endif
