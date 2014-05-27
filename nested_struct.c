#include <stdio.h>
#include <string.h>

int main() {

	struct person {
		char day[20];
		char month[20];
		int year;
	};

	struct human {
		char name[10];
		struct person birthday;
	} me;

	strcpy(me.birthday.day, "Monday");
	strcpy(me.birthday.month, "August");
	strcpy(me.name, "roman");
	me.birthday.year=2000;

	printf("My name: %s\n", me.name);
	printf("My birthday (day): %s\n", me.birthday.day);
	printf("My birthday (month): %s\n", me.birthday.month);
	printf("My birthday (year): %i\n", me.birthday.year);

	return 0;
}
