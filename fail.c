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
		printf("Wrong number of arguments!\n");
		exit(1);
	}
	else {

		if(argv[1][strlen(argv[1])-1] == '\n') {
			argv[1][strlen(argv[1])-1] = '\0';
		}
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
		else {
			printf("The function %s doesn't exist!\n", command);
			exit(1);
		}
	}

	return 0;
}

void find_char(char* string) {
	//fflush(stdin);
	char c;
	printf("Which char do you want to find in the string? ");
	// if(!(isalpha(c=getchar()))) {
	// 	printf("Please choose a char of the alphabet!\n");
	// 	exit(1);
	// }
	int x=1;
	char* pointer=string;
	while(pointer) {
		printf("%c", *pointer);
		pointer++;	
	}
}

void find_piece(char* string) {
	printf("The piece of chars which should be searched for? ");
	char piece[LEN-1];
	fgets(piece, 10, stdin);
	// if(strlen(piece) == 2) {
	// 	printf("Use the \'find_char\' function to find a single char!\n");
	// 	exit(1);
	// }
	int x=1;
	int a=1;
	char* pointer=string;
	while(pointer != '\0') {
		x++;
		if(*pointer == piece[0]) {
			for(; a <= (strlen(piece)-1); a++) {
				printf("%i", a);
			}
		}
		pointer++;
	}
}
