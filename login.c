#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERSION 1.0
#define SIZE 64 // Standart Größe für einen String.

struct t {
  char name[SIZE];
  char passwort[SIZE];
};

// Prototypen der Funktionen.
void add_nullbyte(char* string);

int contains_white_space(char* string); 
int length_is_valid(char* string);

void login(void);
void create(void);
void delete(void);
void show_message(void);

void logged_in(struct t user);

void help(void);
void menu(void);

int main() {
  menu();
  return 0;
}

// Funktion die bei einem String das Nullbyte hinzufügt, damit man den String mit anderen vergleichen kann.
void add_nullbyte(char* string) { 
  if(string[strlen(string)-1] == '\n')
    string[strlen(string)-1] = '\0';
}

int contains_white_space(char* string) {
  char* pointer=string;

  while(*pointer) {
    if(*pointer == ' ') {
      return 1; // 1 steht in diesem Fall für ja, true.
    }

    pointer++;
  }
  return 0;
} 

int length_is_valid(char* string) {
  if(strlen(string) == 1) { // Wenn der User nichts eingegeben hat, ist die Länge des Strings 1, wegen des Nullbytes.
    return 0;
  } else {
    return 1;
  }
}

void login(void) {
  FILE* file_read;  
  FILE* file_temp;  

  FILE* file_deleted_users;
  FILE* file_deleted_users_temp;
    
  file_temp = fopen("users", "a"); // Wenn es die Datei users noch nicht geben würde, würde das hier bereinigt werden.
  file_read = fopen("users", "r");

  file_deleted_users_temp = fopen("deleted_users", "a");
  file_deleted_users      = fopen("deleted_users", "r");


  if(file_read == NULL               || 
     file_temp == NULL               || 
     file_deleted_users == NULL      ||
     file_deleted_users_temp == NULL) {
    puts("Ein Fehler trat auf!"); // @Todo: Hier wäre eine bessere Meldung besser.
    exit(1);
  }

  fclose(file_temp);  
  fclose(file_deleted_users_temp); 

  char name[SIZE]; 
  char passwort[SIZE];

  printf("Benutzername: ");
  fgets(name, SIZE-1, stdin);

  printf("Passwort: ");
  fgets(passwort, SIZE-1, stdin);

  add_nullbyte(passwort); 
  add_nullbyte(name);

  int x;
  struct t user;
  int user_is_deleted = 0;

  while(1) {
    x = fread(&user, sizeof(user), 1, file_read);
    if(x == 0) break;

    if(strcmp(user.name, name) == 0 && strcmp(user.passwort, passwort) == 0) {
      int a;
      char deleted_user[SIZE];
      while(1) {
	a = fread(&deleted_user, sizeof(deleted_user), 1, file_deleted_users);
	if(a == 0) break;
	if(strcmp(deleted_user, name) == 0) {
	  user_is_deleted = 1;
	}
      }
      if(user_is_deleted) {
	break;
      } else {
	fclose(file_read);
	fclose(file_deleted_users);
	puts("Sie haben sich erfolgreich eingeloggt!");
	logged_in(user);
      }
    } 
  }

  puts("Benutzername oder Passwort falsch!");
  show_message();

  fclose(file_read);
  fclose(file_deleted_users);
  menu();
}

void create(void) {
  FILE* file_write;
  FILE* file_read;

  file_write = fopen("users", "a");
  file_read  = fopen("users", "r");

  if(file_write == NULL || file_read == NULL) {
    puts("Ein Fehler trat auf!");
    exit(1);
  }

  struct t user; 
  struct t temp; 

  printf("Benutzername: ");
  fgets(user.name, 49, stdin);

  if(!(length_is_valid(user.name))) { // Länge der Eingabe wird überprüft.
    printf("Der Username muss mindestens einen Buchstaben beinhalten!\n");
    fclose(file_write);
    fclose(file_read);
    show_message();
    menu();
  }

  if(contains_white_space(user.name)) { // Hier wird geprüft, ob der in der Eingabe ein Leerzeichen vorhanden ist.
    printf("Der Username darf kein Leerzeichen enthalten!\n");
    fclose(file_write);
    fclose(file_read);
    show_message();
    menu();
  }

  printf("Passwort: ");
  fgets(user.passwort, 49, stdin);

  if(!(length_is_valid(user.passwort))) {
    printf("Der Passwort muss mindestens einen Buchstaben beinhalten!\n");
    fclose(file_write);
    fclose(file_read);
    show_message();
    menu();
  }

  if(contains_white_space(user.passwort)) {
    printf("Das Passwort darf kein Leerzeichen enthalten!\n");
    fclose(file_write);
    fclose(file_read);
    show_message();
    menu();
  }

  add_nullbyte(user.passwort);
  add_nullbyte(user.name);

  int x; 

  while(x != 0) {
    x = fread(&temp, sizeof(temp), 1, file_read);

    if(x == 0) break;

    add_nullbyte(temp.name);

    if(strcmp(temp.name, user.name) == 0) {
      printf("Diesen User gibt es schon!\n");
      show_message();

      fclose(file_write);
      fclose(file_read);

      menu();
    }
  }

  int var = fwrite(&user, sizeof(user), 1, file_write);

  if(var == 0) {
    puts("Ein Fehler trat auf!"); // @Todo: Bessere Meldung!

    fclose(file_write);
    fclose(file_read);

    exit(0);
  }      

  printf("Neuen User namens %s erstellt!\n", user.name);
  show_message();

  fclose(file_write);
  fclose(file_read);

  menu();  
}

void delete(void) {
  FILE* file_write;
  FILE* file_read;	

  FILE* temp_file;

  // Wenn es die Datei 'users' noch nicht gibt, dann würde es einen Fehler geben.
  // Deswegen wird das hier geprüft, indem ich die Datei im anhänge Modus öffne.
  // Wenn es sie schon gibt, passiert nicht, wenn es sie aber noch nicht gibt, dann wird sie erstellt.

  temp_file  = fopen("users", "a");

  file_write = fopen("deleted_users", "a");
  file_read  = fopen("users", "r");

  if(temp_file == NULL || file_write == NULL || file_read == NULL) {
    puts("Ein Fehler traf auf!");
    exit(0);
  }
  
  fclose(temp_file);
  
  char name[SIZE];
  char passwort[SIZE];

  printf("Name des Users: ");
  fgets(name, SIZE-1, stdin);
  add_nullbyte(name);

  printf("Passwort des Users '%s': ", name);
  fgets(passwort, SIZE-1, stdin);
  add_nullbyte(passwort);
  
  struct t user;
  int x;
  
  while(1) {
    x = fread(&user, sizeof(user), 1, file_read);
    if(x == 0) break;
    
    add_nullbyte(user.name);
    add_nullbyte(user.passwort); 
    
    if(strcmp(user.name, name) == 0) {
      if(!(strcmp(user.passwort, passwort) == 0)) {
	printf("Falsches Passwort für den User '%s'\n", name);
      } else {
	int v = fwrite(&user.name, sizeof(user.name), 1, file_write);
	
	if(v == 0) {
	  printf("Ein Fehler trat auf!");
	  fclose(file_write);
	  fclose(file_read);
	}

	printf("User '%s' erfolgreich gelöscht!\n", name);
	fclose(file_write);
	fclose(file_read);
	show_message();
	menu();
      }
    }
  }

  puts("Diesen User gibt es nicht!");
  show_message();

  fclose(file_write);
  fclose(file_read);
  menu();
}

void show_message(void) {
  printf("Drücken sie Enter um zum Menu zurückzukommen...");
  getchar(); // Ist unsicher.
}

void logged_in(struct t user) {
  char input[SIZE];

  while(1) {
    printf("> ");
    fgets(input, SIZE-1, stdin);
    add_nullbyte(input);
    
    if(strcmp(input, "config") == 0) {
      puts("\n1. Farbe des Promptes."); // @Todo: hier sollen noch ein paar Sachen hin die man konfigurieren kann.
      printf("Ihre Eingabe: ");
      char z[SIZE];
      int g = atoi(fgets(z, SIZE-1, stdin));
      
      if(g == 1) {
	puts("Wählen Sie eine Farbe aus!");
	puts("Rot, grün, gelb, lila");
	printf("Ihre Eingabe: ");

	char color[SIZE];
	fgets(color, SIZE-1, stdin);
	add_nullbyte(color);

	if(strcmp(color, "rot") == 0 || strcmp(color, "Rot") == 0) {
	  printf("\E[31m"); 
	} else if(strcmp(color, "gelb") == 0 || strcmp(color, "Gelb") == 0) {
	  printf("\E[33m");
	} else if(strcmp(color, "grün") == 0 || strcmp(color, "Grün") == 0) {
	  printf("\E[32m");
	} else if(strcmp(color, "lila") == 0 || strcmp(color, "Lila") == 0) {
	  printf("\E[35m");
	} else if(strcmp(color, "\0") == 0) {
	  puts("Sie müssen schon etwas richtiges eingeben.");
	} else {
	  puts("Diese Farbe ist nicht unterstützt.");
	}
      }
    } else if(strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
      printf("\E[0m"); // Die Terminal Farbe wieder auf die ursprüngliche zurücksetzen.
      exit(0);
    } else if(strcmp(input, "\0") == 0) { // Wenn der User nur Enter gedrückt hat.
    } else {
      puts("Ungültige Eingabe.");
    }
  }
}

void help(void) {
  puts("1. Informationen über diese Version.");
  puts("2. Was ist das hier?");
  puts("3. Kommandozeilenargumente.");
  puts("4. Zum Menu zurückkehren.");
  puts("5. Exit");
  printf("Wählen sie eine Nummer: ");
  
  char string[SIZE];
  fgets(string, SIZE-1, stdin);
  int num = atoi(string);

  switch(num) {
  case 1:
    printf("\nVersionsnummer: %0.1f\n\n", VERSION);
    puts("Implementierungen:");
    puts("Login");
    puts("Benutzererstellung");
    puts("Benutzerlöschung");
    puts("Konfigurationen\n"); 
    show_message();
    menu();
    break;
  case 2:
    puts("\nDieses Programm ist eine Imitation");
    puts("eines Computer Systems auf Text Basis.\n");
    show_message();
    menu();
    break;
  case 3:
    puts("\nBeim Start des Programms können sie folgende");
    puts("Kommandozeilenargumente mit angeben:");
    puts("--no-clear     : Das Terminal wird nicht geleert.");  // @Todo
    puts("--color-outputs: Es werden Farben (Menu etc.) in den Ausgaben verwendet."); // @Todo
    break;
  case 4:
    show_message();
    menu();
    break;
  case 5:
    exit(0);
    break;
  default:
    puts("Ungültige Eingabe.");
    show_message();
    menu();
    break;
  }
}

void menu(void) {
  system("clear");
  puts(" =-=-=-=-=-=-=-=-=-=-=-=-=");
  puts("| 1. User anmelden        |");
  puts("| 2. User erstellen       |");
  puts("| 3. User löschen         |");
  puts("| 4. Hilfe                |");
  puts("| 5. Exit                 |");
  puts(" =-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("Ihre Eingabe: ");

  char string[SIZE];
  int var = atoi(fgets(string, SIZE-1, stdin));

  switch(var) {
  case 1:
    login();
    break;
  case 2:
    create();
    break;
  case 3:
    delete();
    break;
  case 4:
    help();
    break;
  case 5:
    exit(0);
    break;
  default:
    puts("Ungültige Eingabe.");
    menu();
  }
}
