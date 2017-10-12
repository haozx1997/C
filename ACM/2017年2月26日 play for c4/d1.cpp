 #include<stdio.h>
 #include<math.h>
 int main()
 {
 	int n,a[10010],max,min,i;
 	while(scanf("%d",&n)!=EOF)
 	{
 		for( i=0;i<n;i++)
 		scanf("%d",&a[i]);
 		max=min=a[0];
 		for(i=1;i<n;i++)
 		{
 			min=min<a[i]?min:a[i];
 			max=max>a[i]?max:a[i];
		 }
		 if(min>=0)
		 printf("%d\n",max);
		 else if(max<=0)
		 printf("%d\n",abs(min));
		 else if(abs(min)>=max)
		 printf("%d\n",2*max+abs(min));
		 else 
		 printf("%d\n",2*abs(min)+max);
		
	 }
	 return 0;
 }

