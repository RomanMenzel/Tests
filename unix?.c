#include <stdio.h>

#ifdef __unix__
	#define info() printf("Du bist unter einem unix system :)\n")

#else
	#define info() printf("Du bist nicht unter einem unix system :(\n")

#endif

int main() {

	info();

	return 0;
}
