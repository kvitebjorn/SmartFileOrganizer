/**
 * Error messages
 */

#define MSG_FAIL_INIT_MAGIC "Fail to initialize magic library"
#define MSG_FAIL_MAGIC_ERROR "Magic error"
#define MSG_FAIL_MAGIC_LOAD "Fail to load magic database"
#define MSG_FAIL_OPEN_FILE "Error opening file"
#define MSG_FAIL_MAGIC_DESCRIPTOR "Could not read file with magic descriptor function"
#define MSG_FAIL_GET_MIME_TYPE "Fail to get file MIME type"

#define MSG_FAIL_FILE_BYTES_READ "Fail to read all the bytes from the file"
#define MSG_FAIL_FILE_INFO_DETAILS "Failed to identify file type & description"
#define MSG_FAIL_NO_EXTENSION "There is no extension, probably binary file"


/**
 * Error codes
 */

#define FAIL_FILE_NOT_FOUND 4041
#define FAIL_INIT_MAGIC 4042
#define FAIL_LOAD_MAGIC_DATABASE 4043
#define FAIL_GET_MIME_TYPE 4044
#define FAIL_MAGIC_DESCRIPTOR 4045

#define FAIL_BYTES_READ 1011
#define FAIL_OPEN_FILE 1012
#define FAIL_FILE_INFO_DETAILS 1013

#define FAIL_NO_EXTENSION 2011