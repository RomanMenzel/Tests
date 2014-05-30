#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define HOBBYLEN 20
#define LEN 20

int main() {

	struct human {
		char hobby[HOBBYLEN];
		char name[20];
		float geb;
	};

	struct human* me;

	me=malloc(sizeof(struct human));

	if(me == NULL) {
		printf("Sie haben keinen Speicher mehr frei");
		exit(0);
	}
	else {
		printf("Geben sie hier ihren Namen ein: ");
		fgets(me->name, 19, stdin);
		printf("Und nun ihr Hobby (ein Wort): ");
		fgets(me->hobby, 19, stdin);
		printf("Und nun ihren Geburtstag (Zahl): ");
		char input[20];
		me->geb=atoi(fgets(input,19, stdin));
		free(me);
	}

	return 0;
}
