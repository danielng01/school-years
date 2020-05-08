//ТУЕС elsys-bg.org
//11Б
//11
//Даниел Николаев Георгиев
//Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намерят и изведат всички числа на Фибоначи в интервала [x, y].

#include <stdio.h>
int main()
{
	int a = 0;
	int b = 1;
	int sum;
	int i;
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	for (i=0;;i++)
	{
		if(a>=x && a<=y)
			printf("%d\n",a);
		sum = a + b;
		a = b;
		b = sum;
		if(a>y)
			break;
	}
}
