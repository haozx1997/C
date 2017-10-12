#include <stdio.h>
int main()
{
    int i;
    float sum = 0;
    for(i = 1;i <= 10; ++ i)
    {
        sum += ((float) i+1)/(float)(i);
    }
    printf("%f\n",sum);
    return 0;
}
