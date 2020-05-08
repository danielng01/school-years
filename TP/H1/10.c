//ТУЕС elsys-bg.org
//11Б
//11
//Даниел Николаев Георгиев
//Да се разработи програма,  която изисква от потребителя да въведе четири числа x, y, w, h където x>0, y>0, w>0, h>0. Числото x е дължината на плоча дървесина, а числото y е височината. Да се определи на колко цели плочи с размери w, h може да се разреже голямата плоча. Да се инициализира масив от 10 елемента. Стойностите на елементите на масива да са първите 10 координати по дължина на плочата, в които тя трябва да се разреже, за да се получат по-малките плочи.
#include <stdio.h>

void printCoords( int x, int y, int w, int h, int flag );

void main(){
	int x, y, w, h;
				
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 );
	
	do{
		printf("y=");
		scanf("%d", &y);
	}while( x < 0 );
	
	do{
		printf("w=");
		scanf("%d", &w);
	}while( x < 0 );
	
	do{
		printf("h=");
		scanf("%d", &h);
	}while( x < 0 );
	
	
	int pcs, flag;
	if(x>y){
		if(w>h){
			pcs = (x/w) * (y/h);
			flag = 1;
		}else{
			pcs = (x/h) * (y/w);	
			flag = 2;
		}
	}else{
		if(w<h){
			pcs = (x/w) * (y/h);
			flag = 3;
		}else{
			pcs = (x/h) * (y/w);	
			flag = 4;
		}
	}	
	
	printf("%d pieces can be cut out at the following Xcoords : \n", pcs);
	printCoords(x, y, w, h, flag);
	
}

void printCoords( int x, int y, int w, int h, int flag ){
	
	int i=0;
	switch(flag){
		case 1 : {
					while(x>=w){
						i++;
						printf("Xcoord = %d\n", i*w);
						x -= w;
					}
				 }
		case 2 : {
					while(x>=h){
						i++;
						printf("Xcoord = %d\n", i*h);
						x -= h;
					}
				 }
		case 3 : {
					while(x>=w){
						i++;
						printf("Xcoord = %d\n", i*w);
						x -= w;
					}
				 }
		case 4 : {
					while(x>=h){
						i++;
						printf("Xcoord = %d\n", i*h);
						x -= h;
					}
				 }	
	}
}

