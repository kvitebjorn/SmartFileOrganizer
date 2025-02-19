#include "../include/cli.h"

// Static function declare
static int8_t format_null(struct program_state *program_struct);

/*
    Function to handle user input
*/
int read_input(struct program_state *program_struct) {
    if (NULL == program_struct )
        return ERROR_READ;

    fgets(program_struct->input_buff, USR_BUFF_CAP, stdin); // Get the input
    if (format_null(program_struct) != 0)
        return ERROR_READ;


    /*
        The code below is dedicated to handle the commands
    */
    if (strcmp(program_struct->input_buff, "organize") == 0) {
        // TODO: handle organize command

    } else if (strcmp(program_struct->input_buff, "backup") == 0) {
        // TODO: handle backup command

    } else if (strcmp(program_struct->input_buff, "status") == 0) {
        // TODO: handle status command

    } else if (strcmp(program_struct->input_buff, "exit") == 0) {
        printf("Bye :)\n");
        program_struct->is_running = false;
    }

    return READ_SUCCESS;
}


/*
    A function to dedicate to format the input to change from a \n at the end to \0
*/
static int8_t format_null(struct program_state *program_struct) {
    if (NULL == program_struct)
        return -1;

    char *char_index = strchr(program_struct->input_buff, 0xA); // gets the address where \n occour
    if (char_index == NULL) // check if it was found
        return -1;

    *char_index = 0x00; // set the addr to 0x00
    return 0;
}
