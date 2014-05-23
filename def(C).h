#include <string.h>
char nullbyte(char* text) {
	if(text[strlen(text) -1] == '\n')
		text[strlen(text) -1] = '\0';
	return 0;
}
