#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct person_vars {
	char name[10];
	char hobby[30];
	int age;
};

struct person_vars2 {
	char name_in_person_vars2[10];
	char hobby_in_person_vars2[30];
	int age_in_person_vars2;
};

void print_struct(struct person_vars person);
struct person_vars getstruct(char* var_name, char* var_hobby, int age);
struct person_vars2* ptr_var;

int main() {

	struct person_vars me = {
		"roman",
		"programmming",
		13
	};

	print_struct(me);
	struct person_vars lad;
	lad=getstruct("roman", "programmming", 13);

	ptr_var=malloc(sizeof(struct person_vars2));
	if(ptr_var == NULL) {
		printf("No memory available");
		exit(0);
	}
	else {
		ptr_var->age_in_person_vars2=13;
		strcpy(ptr_var->name_in_person_vars2, "roman");
		strcpy(ptr_var->hobby_in_person_vars2, "programmming");
		printf("\nStructure filled with pointer: \n");
		printf("Name: %s\n", ptr_var->name_in_person_vars2);
		printf("Hobby: %s\n", ptr_var->hobby_in_person_vars2);
		printf("Age: %i\n\n", ptr_var->age_in_person_vars2);
		free(ptr_var);
		ptr_var=NULL;
	}

	return 0;
}

void print_struct(struct person_vars person) {
	printf("\nStructure as Parameter: \n");
	printf("Name: %s\n", person.name);
	printf("Hobby: %s\n", person.hobby);
	printf("Age: %i\n\n", person.age);
}

struct person_vars getstruct(char* var_name, char* var_hobby, int var_age) {
	struct person_vars boy;
	strcpy(boy.name, var_name);
	strcpy(boy.hobby, var_hobby);
	boy.age=var_age;
	printf("Returned Structure: \n");
	printf("Name: %s\n", boy.name);
	printf("Hobby: %s\n", boy.hobby);
	printf("Age: %i\n", boy.age);
	return (boy);
}
