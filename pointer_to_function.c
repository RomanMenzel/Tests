#include <stdio.h>

void print(void);
void add(int a, int b, void(*f)(void));

int main() {

	add(5, 5, &print);

	return 0;
}

void print(void) {
	printf("Hallo Welt!\n");
}

void add(int a, int b, void(*f)(void)) {
	int c=a+b;
	printf("C ist jetzt %i\n", c);
	printf("Jetzt wird die Funktion aufgerufen: \n");
	f();
}

