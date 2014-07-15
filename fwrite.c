/* The data will be written in binary into the file */

#include <stdio.h>
#include <stdlib.h>

int main() {

	struct person_vars {
		char age_string[10];
		char name[10];
	};

	struct person_vars person;

	printf("Type in your name: ");
	fgets(person.name, 9, stdin);
	printf("Type in your current age: ");
	fgets(person.age_string, 9, stdin);
	
	FILE* datafile;

	datafile=fopen("fwrite.dat", "a");
	if(!datafile) {
		puts("Error in file");
		exit(0);
	}

	fwrite(&person, sizeof(person), 1, datafile);

	fclose(datafile);

	return 0;
}
