#include <stdio.h>

int main()
{
    int A[20], *A2 = &(A[10]), i;
    int aa[100][100];
    int **ap = 
    for(i=0; i<20; i++) A[i] = i*2;
    
    for(i=-10; i<10; i++) printf("%d %d\n",i, A2[i]);
    printf("!%d",A[14]); 
    
    return 0;
}
