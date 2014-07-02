#include <stdio.h>
#define TRUE 1

int main() {

	while(TRUE) {
		int a=random_number(0, 10001);
		int b=random_number(0, 100001);
		int c=random_number(0, 1000001);
		printf("\E[31m"); 
    	printf("!");
    	if(a % 2) {
    		printf("\E[34m");
  			printf("!");
  			if(!b % 5) {
  				printf("\E[33m");
    			printf("!");
  			}
  			else {
  				printf("\E[32m");
    			printf("!");
  			}
    	}
    	else {
    		printf("\E[35m");
    		printf("!");
    		if(!c % 6) {
    			printf("\E[36m");
    			printf("!");
    		}
    		else {
    			printf("!");
    		}
    	}
	}

	return 0;
}


int random_number(int min_num, int max_num) {
	int result=0,low_num=0,hi_num=0;
	if(min_num<max_num) {
		low_num=min_num;
		hi_num=max_num+1; 
	}
	else {
		low_num=max_num+1;
		hi_num=min_num;
	}
	srand(time(NULL));
	result = (rand()%(hi_num-low_num))+low_num;
	return result;
}





