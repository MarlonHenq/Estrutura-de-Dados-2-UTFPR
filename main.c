#include <stdio.h>
#include <stdlib.h>

int main{

int *p;

int a = 2;

p = &a;

printf("%d", *p);

char *p2 = (char *) &a;

printf("%d", *p2);

}