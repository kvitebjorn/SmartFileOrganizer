#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdio.h>
#include <sys/stat.h> // To get the size of the file
#include <stdlib.h>
#include <stdbool.h>

#define FILE_PATH_LEN 128


// Add more types
enum file_types {
    PNG,
		JPG,
		ELF
};

typedef struct file {
		size_t file_size;
		int    file_format;
		bool   success_analyse;
} file_info;

// Function to get the given file its type
file_info analyse_file(const char *path);

#endif
