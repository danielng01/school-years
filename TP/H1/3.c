//ТУЕС elsys-bg.org
//11Б
//11
//Даниел Николаев Георгиев
//Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намерят и изведат всички прости числа завършващи на 3 в интервал [x,y].
#include <stdio.h>
int isPrime(int i)
{
	int j=2;
	while(j<=i/2)
	{
		if(i%j==0)
		{
			return 1;
		}
		else
		{
			j++;		
		}
		
	}
	return 0;
}
int main()
{
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	int i;
	for(i=0;x<=y;x++)
	{
		i = x%10;
		if(i==3)
		{
			if(isPrime(x)==0)
			{
				printf("%d\n",x);
			}		
		}
	}	
}
