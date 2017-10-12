#include <stdio.h>
main ( )
{ 
    double r,Pi,s1,s2,v;
    Pi=3.1415926536;
    scanf ("%lf",&r);
    s1 = Pi*r*r;
    s2 = Pi*r*r*4;
    v = 4/3*Pi*r*r*r;
    printf ("s1=%lf\n s2=%lf\nv=%lf\n",s1,s2,v);
    return 0;
}
