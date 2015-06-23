// Is not finish yet !

#include <stdio.h>
#include <stdlib.h>

char field[] = {
  '-','-','-',
  '-','-','-',
  '-','-','-'
};

void print_field(void) {
  system("clear");
  printf("%c", field[0]);
  printf("%c", field[1]);
  printf("%c\n", field[2]);
  printf("%c", field[3]);
  printf("%c", field[4]);
  printf("%c\n", field[5]);
  printf("%c", field[6]);
  printf("%c", field[7]);
  printf("%c\n\n", field[8]);
}

void player_one(void) {
  char a[10];
  printf("\nPlayer one [x]: ");
  
  fgets(a, 9, stdin);
  int b = atoi(a);

  if(b <= 0) {
    puts("This place doesn't exist!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else if(b > 9) {
    puts("This place doesn't exist!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else if(field[b-1] == 'o' || field[b-1] == 'x') {
    puts("This place is already occupied!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else {
    field[b-1] = 'x';
  }
}

void player_two(void) {
  char a[10];
  printf("\nPlayer two [o]: ");
  
  int b = atoi(fgets(a, 9, stdin));

  if(b <= 0) {
    puts("This place doesn't exist!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else if(b > 9) {
    puts("This place doesn't exist!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else if(field[b-1] == 'o' || field[b-1] == 'x') {
    puts("This place is already occupied!");
    printf("Press enter to continue...");
    getchar();
    player_one();
  } else {
    field[b-1] = 'o';
  }
}

void check_field(void) {
  if(field[0] == 'x' && field[1] == 'x' && field[2] == 'x' || 
     field[4] == 'x' && field[5] == 'x' && field[6] == 'x' ||
     field[7] == 'x' && field[8] == 'x' && field[9] == 'x' ||
     field[0] == 'x' && field[4] == 'x' && field[7] == 'x' ||
     field[1] == 'x' && field[5] == 'x' && field[8] == 'x' ||
     field[2] == 'x' && field[6] == 'x' && field[9] == 'x') {

    puts("---------------------------");
    puts("|    Player one has won!   |");
    puts("---------------------------");

    exit(0);

  } else if(field[0] == 'o' && field[1] == 'o' && field[2] == 'o' || 
     field[4] == 'o' && field[5] == 'o' && field[6] == 'o' ||
     field[7] == 'o' && field[8] == 'o' && field[9] == 'o' ||
     field[0] == 'o' && field[4] == 'o' && field[7] == 'o' ||
     field[1] == 'o' && field[5] == 'o' && field[8] == 'o' ||
     field[2] == 'o' && field[6] == 'o' && field[9] == 'o') {

    puts("---------------------------");
    puts("|    Player two has won!   |");
    puts("---------------------------");

    exit(0);
  }
}

int main() {
  while(1) {
    print_field();
    player_one();
    check_field();
    print_field();
    player_two();
  }

  print_field();

  return 0;
}
