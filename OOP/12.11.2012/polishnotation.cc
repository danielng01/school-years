#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *p;   /* will point to a region of free memory */
int *tos; /* points to top of stack */
int *bos; /* points to bottom of stack */

void push(int i)
{
  if(p > bos) {
    printf("Stack Full\n");
    return;
  }
  *p = i;
  p++;
}

int pop(void)
{
  p--;
  if(p < tos) {
    printf("Stack Underflow\n");
    return 0;
  }
  return *p;
}

int main(void)
{
  int a, b;
  char s[80];

  p = (int *) malloc(MAX*sizeof(int)); /* get stack memory */
  if(!p) {
    printf("Allocation Failure\n");
    exit(1);
  }
  tos = p;
  bos = p + MAX-1;

  printf("Four Function Calculator\n");
  printf("Enter 'q' to quit\n");

  do {
    printf(": ");
    gets(s);
    switch(*s) {
      case '+':
        a = pop();
        b = pop();
        printf("%d\n", a+b);
        push(a+b);
        break;
      case '-':
        a = pop();
        b = pop();
        printf("%d\n", b-a);
        push(b-a);
        break;
      case '*':
        a = pop();
        b = pop();
        printf("%d\n", b*a);
        push(b*a);
        break;
      case '/':
        a = pop();
        b = pop();
        if(a==0) {
          printf("Divide by 0.\n");
          break;
        }
        printf("%d\n", b/a);
        push(b/a);
        break;
      case '.': /* show contents of top of stack */
        a = pop();
        push(a);
        printf("Current value on top of stack: %d\n", a);
        break;
      default:
        push(atoi(s));
    }
  } while(*s != 'q');

  return 0;
}

