/* Seach a string for a char or a bunch of chars using pointers*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 10000
#define TRUE 0
void find_char(char* string);
void find_piece(char* string);

int main(int argc, char* argv[]) {

	if(argc != 2) {
		printf("Usage: ./string <string to investigate>\n");
		exit(1);
	}
	else {

		if(argv[1][strlen(argv[1])-1] == '\n') {
			argv[1][strlen(argv[1])-1] = '\0';
		}
		label:
		printf("Command (help for help): ");
		char command[LEN];
		fgets(command, LEN-1, stdin);

		if(command[strlen(command)-1] == '\n') {
			command[strlen(command)-1] = '\0';
		}

		if(strcmp(command, "find_char") == 0) {
			find_char(argv[1]);
		}
		else if(strcmp(command, "find_piece") == 0) {
			find_piece(argv[1]);
		}
		else if(strcmp(command, "help") == 0) {
			printf("Availabale functions are: find_char, find_piece\n");
			goto label;
		}
		else {
			printf("The function %s doesn't exist!\n", command);
			exit(1);
		}
	}

	return 0;
}

void find_char(char* string) {
	char c;
	printf("Which char do you want to find in the string? ");
	if(!(isalpha(c=getchar()))) {
		printf("Please choose a char of the alphabet!\n");
		exit(1);
	}
	int x=1;
	char* pointer=string;
	while(*pointer) {
		if(*pointer == c) {
			printf("Char %c found at place %i\n", c, x);
			exit(0);
		}
		x++;
		pointer++;
	}
	printf("Char %c not found\n", c);
}

void find_piece(char* string) {
	printf("The piece of chars which should be searched for? ");
	char piece[LEN-1];
	fgets(piece, LEN-1, stdin);
	if(strlen(piece) <= 2) {	// 2 beacause of the 0x00
		printf("Use the \'find_char\' function to find a single char!\n");
		exit(1);
	}
	int x=1;
	char* pointer=&string[0];
	char* ppointer=&piece[1];
	while(*pointer != 0x00) {
		if(*pointer == piece[0]) { // First charakter of the piece was found
			while(*ppointer != 0x00) {
				if(*ppointer == *pointer){
					goto a;
				}
				else {

				}
				a:
				ppointer++;
				continue;
			}
			printf("Piece found!\n");
			exit(0);
		}		
		else {
			// Nothing
		}
		x++;
		pointer++;
	}
	printf("Piece not found!\n");
}
