#include "../include/organize.h"

const char *image_types[] = {"png", "jpeg", "jpg", "gif", "bmp", "tiff", "webp", "x-icon"};

char sfo_home[1024];
char links_path[1024];

bool is_image = false;

#define SUCCESS_CREATED_IMAGE_LINKS 0

// Current working directory
char current_directory[1024];

static int handle_images(const file_info *file_info)
{
    if (file_info == NULL)
        return -1;

    if (symlink(sfo_home, "link_image") == -1)
    {
        fprintf(stderr, "Error: %s\n", MSG_FAIL_CREATE_SYMBOLIC_LINK);
        return FAIL_CREATE_SYMBOLIC_LINK;
    }

        return 0;
}

static int handle_types(const file_info *file_info)
{
    if (file_info == NULL)
        return FAIL_HANDLE_TYPE;

    for (int i = 0; i < IMAGE_TYPE_ARRAY_LEN; i++)
    {
        if (strcmp(file_info->extension, image_types[i]) == 0)
        {
            is_image = true;
            break;
        }
    }

    if (is_image)
    {
        strcat(sfo_home, "/images/"); 
        if (!mkdir(sfo_home, 0755)) // create a directory for images
        {
            fprintf(stderr, "Error: %s\n", MSG_FAIL_CREATE_DIRECTORY);
            return FAIL_CREATE_NEW_DIRECTORY;
        }

        //TO DO ( maybe copying the original image files into newly created folder (images))

        handle_images(file_info);
    }
}

/*
    Function to handle the organize process
*/
int organize(const file_info *f_info)
{

    if (!getcwd(current_directory, sizeof(current_directory)))
    {
        fprintf(stderr, "Error: %s or %s\n", MSG_FAIL_NO_CWD, MSG_FAIL_NO_SPACE);
        return FAIL_NO_CWD;
    }

    strncpy(sfo_home, current_directory, sizeof(sfo_home));
    sfo_home[strlen(current_directory) + 1] = '\0';

    if (!sfo_home)
    {
        fprintf(stderr, "Error: %s\n", MSG_FAIL_COPY_CWD);
        return FAIL_NO_COPY;
    }

    if (f_info->success_analyse)
    {
        handle_types(f_info);
    }

    return 0;
}
