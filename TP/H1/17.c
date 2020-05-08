//ТУЕС elsys-bg.org
//11Б
//11
//Даниел Николаев Георгиев
//Да се разработи програма, която изисква от потребителя да въведе число x, където x e интервала (0;1). Да се намери сумата от сбора на реципрочните стойности за всеки две twin primes. Развитието да продължи докато отношението не стане по-малко то x.
#include <stdio.h>

int prime(long x);
float rec(float x);

int main(){
	
	float x, sum;
	do{
		printf("Enter 0<x<1 : ");
		scanf("%f", &x);
	}while(x<=0 || x>=1);

	long i;
	for(i=2; ; i++){
		if( prime(i) ){
			if( prime(i+2) ){
				if( (sum = rec(i) + rec(i+2)) < x ){
					break;
				}
			}
		}
	}
	
	printf("Primes : (%ld;%ld) .. SUM = %f \n", i, (i+2), sum);		
	
	return 0;
}


int prime(long x){
	int i;
	for (i=2; i<x; i++)
    {
      if (x%i == 0 && i != x)
        return 0;
    }
    return 1;
}

float rec(float x){
	return 1.0/x;
}
