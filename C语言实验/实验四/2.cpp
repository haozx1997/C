#include "stdio.h" 
main ()
{//[�����]�����⣺��д��������ӹ�Ԫ1000����2100�������������š�Ҫ��ÿ���15����Ż�һ��
	int y[1000];
	int y0=0,i;
	for(i=1000;i<=2100;i++)
	 {
	 	if (i%400)
        {if (i%100)
             if (i%4)
		       continue;
		    else 
			{
				y[y0]=i;
				y0++;
			}
        else
        	continue;   
	    }
	else
       {
			y[y0]=i;
			y0++;
		}
	 }
	 for(i=0;i<y0;i++)
	   {
	   	if(i%15==0) printf("\n");
	   	printf("%d ",y[i]);
	   }
	return 0;
}
	
