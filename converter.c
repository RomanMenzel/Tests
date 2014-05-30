/* Binary Converter written in C 
 * (c) Roman Menzel                */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "def.h"

#define LEN 40

int main() {

	printf ("Type in a word: ");
	char word[LEN];
	fgets(word, 39, stdin);
	
	nullbyte(word);
	
	char* ptr;
	ptr=word;
	
	while(*ptr) {

		switch(tolower(*ptr)) {
		
		case 'a':
			printf("01100001");
			break;
			
		case 'b':
			printf("01100010");
			break;
			
		case 'c':
			printf("01100011");
			break;
			
		case 'd':
			printf("01100100");
			break;
			
		case 'e':
			printf("01100101");
			break;
			
		case 'f':
			printf("01100110");
			break;
			
		case 'g':
			printf("01100111");
			break;
			
		case 'h':
			printf("01101000");
			break;
			
		case 'i':
			printf("01101001");
			break;
			
		case 'j':
			printf("01101010");
			break;
			
		case 'k':
			printf("01101011");
			break;
			
		case 'l':
			printf("01101100");
			break;
			
		case 'm':
			printf("01101101");
			break;
			
		case 'n':
			printf("01101110");
			
		case 'o':
			printf("01101111");
			break;
			
		case 'p':
			printf("01110000");
			break;
			
		case 'q':
			printf("01110001");
			break;
			
		case 'r':
			printf("01110010");
			break;
			
		case 's':
			printf("01110011");
			break;
			
		case 't':
			printf("01110100");
			break;
			
		case 'u':
			printf("01110101");
			break;
			
		case 'v':
			printf("01110110");
			break;
		
		case 'w':
			printf("01110111");
			break;
			
		case 'x':
			printf("01111000");
			break;
			
		case 'y':
			printf("01111001");
			break;
			
		case 'z':
			printf("01111010");
			break;
			
		default:
			printf("%c", *ptr);
			break;
		}
		ptr++;
	}
	
	putchar('\n');
	
	return 0;
}
