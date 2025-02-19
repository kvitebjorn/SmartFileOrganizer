#include "../include/file_type_detector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <magic.h>

file_info file;

int get_file_size(const char *file_path, file_info *file)
{
    struct stat file_stat;

    // Get file size using stat()
    if (stat(file_path, &file_stat) == 0)
    {
        file->file_size = (size_t)file_stat.st_size;
    }
    return file->file_size;
}

int get_file_type(const char *file_path, file_info *file)
{
    magic_t magic_cookie;

    // Initialize magic library
    magic_cookie = magic_open(MAGIC_MIME_TYPE);
    if (magic_cookie == NULL)
    {
        fprintf(stderr, "Failed to initialize magic library.\n");
        file->success_analyse = false;
        return -1;
    }

    // Load default magic database
    if (magic_load(magic_cookie, NULL) != 0)
    {
        fprintf(stderr, "Failed to load magic database: %s\n", magic_error(magic_cookie));
        magic_close(magic_cookie);
        file->success_analyse = false;
        return -1;
    }

    // Get file MIME type
    const char *mime_type = magic_file(magic_cookie, file_path);
    if (mime_type == NULL)
    {
        fprintf(stderr, "Failed to get file type: %s\n", magic_error(magic_cookie));
        magic_close(magic_cookie);
        file->success_analyse = false;
        return -1;
    }
    
    strncpy(file->mime_type, mime_type, strlen(mime_type));
    file->mime_type[strlen(mime_type) + 1] = '\0';

    file->success_analyse = true;
    magic_close(magic_cookie);

    return 1;
}