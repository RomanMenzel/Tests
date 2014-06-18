#include <stdio.h>
#include <string.h>

char nullbyte(char* text) {
	if(text[strlen(text) -1] == '\n')
		text[strlen(text) -1] = '\0';
	return 0;
}

int comparison(char* a, char* b, char* c);

int main() {

	char hallo1[10];
	char hallo2[10];
	char hallo3[10];

	fgets(hallo1, 19, stdin);
	fgets(hallo2, 19, stdin);
	fgets(hallo3, 19, stdin);

	int test=comparison(hallo1, hallo2, hallo3);

	printf("%i\n", test);

	return 0;
}

int comparison(char* a, char* b, char* c) {
	int result;
	nullbyte(a);
	nullbyte(b);
	nullbyte(c);
	result=strcmp(a, b);
	if(result != 0) {
		return result = 1;
	}
	else {
		if(strcmp(a, c) == 0) {
			result = 0;
		}
	}
	return result;
}
