#include "../include/organize.h"

static void handle_images(const file_info *file_info) {
    if (file_info == NULL)
        return;

    if (strcmp(file_info->format, "jpeg") == 0) {
        
    }
}

static int8_t handle_types(const file_info *file_info) {
    if (file_info == NULL)
        return FAIL_HANDLE_TYPE; 

    if(strcmp(file_info->type, "image") == 0) {
        if (strcmp(file_info->format, ""))
    }
    
}

/*
    Function to handle the organize process
*/
int8_t organize(const char *path) {
    if (path == NULL || check_is_a_dir(path) == false) // Check if the path points do a directory
        return FAIL_ORGANIZE_FILES;   


    struct dirent *file_on_dir;         // struct to store the curret file on the dir 
    DIR *dir_pointer = opendir(path);   // pointer to the current directory
    file_info file_type;

    if (dir_pointer == NULL)
        return FAIL_ORGANIZE_FILES;

    while ((file_on_dir = readdir(&dir_pointer)) != NULL) {
        if (strcmp(file_type.type, "inode") == 0) {
            continue; // the file is a directory, jump to the next file
        } else {
            get_file_type(file_on_dir->d_name, &file_type);
        }
    }

    return 0;
}
