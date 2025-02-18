#include "../include/file_ops.h" 

/*
	Static functions to help the other functions goes here

*/


const uint8_t png_signature[] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A };
const uint8_t jpg_signature[] = { 0xFF, 0xD8, 0xFF };
const uint8_t mp3_signature[] = { 0xFF, 0xFB };
const uint8_t elf_signature[] = { 0x7F, 0x45, 0x4C, 0x46 };

static int check_type(FILE *file, const file_info *info_struct) {

		// Check if there is a file and if its size has at least the same size of the PNG size
		if (file == NULL || info_struct == NULL || info_struct->file_size < PNG_SIGNATURE_SIZE)  
				return -1;
		
		uint8_t header_buffer[8]; // using which which is the the PNG header size and is the current biggest value 
		fread(header_buffer, sizeof(uint8_t), PNG_SIGNATURE_SIZE, file); // Read 8 bytes of data to a buffer
		
		if (cmp_buffers(header_buffer, png_signature, PNG_SIGNATURE_SIZE) == true) {
				return PNG;

		} else if (cmp_buffers(header_buffer, jpg_signature, JPG_SIGNATURE_SIZE) == true) {
				return JPG;
		
		} else if (cmp_buffers(header_buffer, mp3_signature, MP3_SIGNATURE_SIZE) == true){
				return MP3;

		} else if (cmp_buffers(header_buffer, elf_signature, ELF_SIGNATURE_SIZE)  == true) {
				return ELF;
				
		} 
}


// Get gien file its size
static size_t get_file_size(const char *path) {
		if (path == NULL)
				return -1;

		struct stat file_stat;
		stat(path, &file_stat);
			
	  return (size_t) file_stat.st_size;
}


/*
	Functions included on header file goes here
	
*/
file_info analyse_file(const char *path) {
		file_info analyse_result;
		
		if (path == NULL) {
				analyse_result.file_size       = -1;
				analyse_result.file_format     = -1;
				analyse_result.success_analyse = false;
				return analyse_result;
		}
		
		FILE *file = fopen(path, "rb");
	 
		analyse_result.file_size       = get_file_size(path);
		analyse_result.file_format     = check_type(file, &analyse_result);
		analyse_result.success_analyse = true;
		fclose(file);

		return analyse_result;
}
