#include "../include/organize.h"

const char *sfo_home = NULL;
char *links_path = NULL;

static int handle_images(const file_info *file_info) {
    if (file_info == NULL)
        return;

    for (int i = 0; i < IMAGE_TYPE_ARRAY_LEN; i ++) {
        if (strcmp(file_info->extension, image_types[i]) == 0) {
            links_path = strcat(sfo_home, strcat("/images/", image_types[i]));  // concat the path to the images with the directory related to the file type
        }
    }

    return execvp("ln", (const char *[]) {"-s", file_info->path, " ",links_path}); // Returns if the link was successfully made
}

static int8_t handle_types(const file_info *file_info) {
    if (file_info == NULL)
        return FAIL_HANDLE_TYPE; 

    if(strcmp(file_info->type, "image") == 0) {
        mkdir(strcat(sfo_home, "/images"), 755); // create a directory for images
        handle_images(file_info);
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

    sfo_home = strcat(getenv("HOME"), "/.sfo"); // SFO home (where the backups goes)

    while ((file_on_dir = readdir(&dir_pointer)) != NULL) {
        if (strcmp(file_type.type, "inode") == 0) {
            continue; // the file is a directory, jump to the next file
        } else {
            get_file_type(file_on_dir->d_name, &file_type);
        }
    }

    return 0;
}
