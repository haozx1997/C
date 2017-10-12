#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000009

void cal_next( char * str, int * next, int len )
{
    int i, j;

    next[0] = -1;
    for( i = 1; i < len; i++ )
    {
        j = next[ i - 1 ];
        while( str[ j + 1 ] != str[ i ] && ( j >= 0 ) )
        {
            j = next[ j ];
        }
        if( str[ i ] == str[ j + 1 ] )
        {
            next[ i ] = j + 1;
        }
        else
        {
            next[ i ] = -1;
        }
    }
}

int KMP( char * str, int slen, char * ptr, int plen, int * next )
{
    int s_i = 0, p_i = 0;

    while( s_i < slen && p_i < plen )
    {
        if( str[ s_i ] == ptr[ p_i ] )
        {
            s_i++;
            p_i++;
        }
        else
        {
            if( p_i == 0 )
            {
                s_i++;
            }
            else
            {
                p_i = next[ p_i - 1 ] + 1;
            }
        }
    }
    return ( p_i == plen ) ? ( s_i - plen+1 ) : -1;
}

int main()
{
    char str[ 1000100 ];
    char ptr[ 10010 ];
    int slen, plen;
    int next[ 10010 ];
	int T;
	scanf("%d",&T);
    while( T-- )
    {
    	scanf("%d%d",&slen,&plen);
    	getchar();
        for(int i = 0 ;i < slen ;i++)
        {
        	scanf("%s",&str[i]);
        	
		}
		str[slen] = '\0';
		
		for(int i = 0 ;i < plen ;i++)
        {
        	scanf("%s",&ptr[i]);
		}
		ptr[plen] = '\0';
		
         cal_next( ptr, next, plen );
        printf( "%d\n", KMP( str, slen, ptr, plen, next ) );
    }
    return 0;
}

