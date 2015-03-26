#include <stdio.h>

int main() {

	char array[3][3][20] = {
		{"c", "programming"},
		{"ruby", "programming"},
		{"python", "programming"}
	};

	int a;

	for(a=0; a<3; a++) {
		printf("%s %s\n", array[a], array[a][1]);
	}

	return 0;
}

// or printf("%s %s\n", array[a], array[a][(a>0) ? ((a==1) ? 1 : 1) : 1]); xD
