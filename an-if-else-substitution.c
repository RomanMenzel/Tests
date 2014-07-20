#include <stdio.h>

int main() {

	char string[10];
	printf("Type in a number: ");
	fgets(string, 9, stdin);
	int x=atoi(string);

	(x < 5) ? puts("The number is shorter than 5") : puts("The number is not shorter than 5");

	return 0;
}

