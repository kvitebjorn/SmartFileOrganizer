#include "../include/utils.h"


bool cmp_buffers(const uint8_t *restrict buff1, const uint8_t *restrict buff2, size_t lenght) {
		if(buff1 == NULL || buff2 == NULL || lenght < 1)
				return false;
		
		for (int count = 0; count < (int) lenght; count++) {
				
				// if there is any difference at the arrays break return false
				if (buff1[count] != buff2[count]) 
						return false;
		}

		return true; // No difference was found
}
