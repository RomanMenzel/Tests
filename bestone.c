#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main() {
	struct vars {
		char name[10];
	} me;

	struct vars* ptr;

	ptr=malloc(sizeof(struct vars));

	if(ptr == NULL)
		printf("Junge, du hast kein Speicher mehr!\n");
	else {
		strcpy(ptr->name, "roman");
		printf("%s\n", ptr->name);
		free(ptr);
	}

	return 0;
}
