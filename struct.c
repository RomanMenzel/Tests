#include <stdio.h>

/* Globale Struktur wird vereinbart  */
struct human {
	char name[20];
	int age;
};

void print_struct(struct human man);

int main() {

	/* Variablen werden angelegt und initializiert*/
	struct human person = {
		"roman",
		13
	};

	print_struct(person);

	return 0;
}

void print_struct(struct human man) {
	printf("Name: %s\n", man.name);
	printf("Age: %i\n", man.age);
}
