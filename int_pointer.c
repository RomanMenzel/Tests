// How to run through an array, using a pointer

#include <stdio.h>
#include <stdlib.h>

int main() {

	int array[] = {0, 1, 2, 4, 5};
	int* pointer=array;
	int x=0;

	for(; x < sizeof(array)/4; x++) {
		printf("[%i]: %i\n", x, *pointer);
		pointer++;
	}

	return 0;
}
