#include "stdio.h" 
struct student 
{ int x; 
char c; 
} a; 
void f(struct student *b) 
{ 
b->x=20; 
(*b).c='y'; 
} 

int main() 
{a.x=3; 
a.c='a'; 
f(&a); 
printf("%d,%c",a.x,a.c); 
} 


