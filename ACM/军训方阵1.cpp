#include <cstdio> 
#include <cmath> 
int main() {

int n, cas = 1;
 while ( scanf( "%d", &n ) != EOF ) 
 { printf( "Case %d:\n", cas++ );
  int end = sqrt(n); 
  for ( int i=1; i<=end; i++ )
   if ( n % i == 0 ) 
   printf( "%d * %d\n", i, n/i ); 
   printf( "\n" );
    } 
   return 0;
   } 

