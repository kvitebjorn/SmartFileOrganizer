#include "../include/utils"

static int check_png(FILE *file) {
		if (file == NULL)
}


// Get given file its size
static size_t get_file_size(const char *path) {
		if (path == NULL)
				return -1;

		struct stat file_stat;
		if (stat(path, &file_stat) == 0)
				return (size_t) file_stat.size;
		
		return -1;
}

file_info analyse_file(const char *path) {
		file_info analyse_result;
		
		if (path == NULL) {
				analyse_result.file_size     = -1;
				analyse_file.file_format     = -1;
				analyse_file.success_analyse = false;
				return analyse_file;
		}
		
		analyse_result.file_size = get_file_size(path);
}
