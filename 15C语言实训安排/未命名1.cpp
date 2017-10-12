#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define N 100


struct clerk
{
 	int num;         //ID号
 	char name[20];   //姓名
 	int jbgz;        //基本工资
 	int zwgz;       //职务工资
 	int jt;          // 津贴 
 	int yb;         //医疗保险
    int gjj;         //公积金//
 	int total;       //总工资
}em[100];       
void menu();
void input();
void save(int);
void display();
void del();
void add();
void search();
void search_num();
void search_name();
void modify();  
void sta();
void start(); /*定义各函数*/




void start() //开始界面
{
    	system("cls");//清屏
    	system("color 1E"); //设置文字颜色为黄色 背景色蓝色
	printf("\n\n\n\n\n\n");
	printf("********************************************************************************");
	printf("*****************************欢迎使用工资管理系统*****************************");
	printf("*********************************************************************************\n\n\n\n\n");
	printf("\t\t\t\t     制作: \n");
	printf("\t\t\t\t        2011年6月\n\n\n\n");

	printf("\t\t\t    ***按任意键进入***\n");

}




void menu() //菜单界面
{
	system("cls");
	system("color 1F"); 
	printf("***菜单***\n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  1  输入  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  2  显示  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  3  查找  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  4  删除  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  5  添加  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  6  修改  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  7  统计  \n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>  8  退出  \n\n");
	printf("说明：*如首次使用 尚未输入数据 请先输入数据 \n      *输入的数据将自动保存 \n      *再次选择输入功能时原数据将被覆盖\n\n");
	}





void input()   /*录入函数*/
{
   	int i,m;
   	system("cls");
  	printf("职工人数(1--100):\n");
   	scanf("%d",&m);
   
	for (i=0;i<m;i++)
   	{
  		printf("请输入职工号: ");
  		scanf("%d",&em[i].num);

  		printf("请输入姓名:  ");
  		scanf("%s",&em[i].name);
 		getchar();

  		printf("请输入基本工资:  ");
  		scanf("%d",&em[i].jbgz);
  
		printf("请输入职务工资:  ");
  		scanf("%d",&em[i].zwgz);

  		printf("请输入津贴:  ");
  		scanf("%d",&em[i].jt);

  		printf("请输入医疗保险:  ");
  		scanf("%d",&em[i].yb);
  
		printf("请输入公积金:  ");
  		scanf("%d",&em[i].gjj);
  
		em[i].total=((em[i].jbgz)+(em[i].zwgz)+(em[i].jt)-(em[i].yb)-(em[i].gjj));//计算总工资
  		printf("\n");//计算总工资
   	}
   	printf("\n创建完毕!\n");
      	save(m);//保存职工人数m
}




void save(int m)  /*保存文件函数*/
{
 	int i;
 	FILE*fp;   //声明fp是指针，用来指向FILE类型的对象
 	if ((fp=fopen("clerk_list","wb"))==NULL) //打开职工列表文件为空
 	{
  		printf ("打开失败\n");
     		exit(0);
 	}
 
	for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/
   	if (fwrite(&em[i],sizeof(struct clerk),1,fp)!=1)//写入数据块   &em[i]：是要输出数据的地址  sizeof(struct clerk)：获取一个单体的长度  1：数据项的个数  fp：目标文件指针
   	printf("文件读写错误\n");
   	fclose(fp);// 缓冲区内最后剩余的数据输出到磁盘文件中，并释放文件指针和有关的缓冲区
}


int load()  /*导入函数  int型*/
{
    	FILE*fp;
 	int i=0;
   	if((fp=fopen("clerk_list","rb"))==NULL)
 	{
  		printf ("cannot open file\n");
     		exit(0);
 	}
 	else 
 	{
  		do 
  		{
        		fread(&em[i],sizeof(struct clerk),1,fp); //读取
    		 	i++;
  		}
  		while(feof(fp)==0);  //检测流上的文件结束符
 	}
 
	fclose(fp);
 	return(i-1);//返回人数
}




void display()  /*浏览函数*/
{
 
 	int i,sum=0;
 	int m=load();
 	system("cls");
 	printf("职工号   姓名   基本工资  职务工资   津贴    医疗保险  公积金   总工资 \n");
 	for(i=0;i<m;i++) /*m为输入部分的职工人数*/
 	{printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",em[i].num,em[i].name,em[i].jbgz,em[i].zwgz,em[i].jt,em[i].yb,em[i].gjj,em[i].total);
  	sum+=em[i].total;//计算员工总工资之和
 	}
  	printf("\n\n职工平均工资为：%d \n",sum/m);
}




void del()   /*删除函数 */
{
 	int m=load();
 	int i,j,n,t,button;
 	char name[20];
 	
	printf("\n 原来的职工信息:\n");
    	display(); //显示删除前的员工信息
    	printf("\n");
 	
	printf("按姓名删除:\n");
 	scanf("%s",name);
 	for(button=1,i=0;button&&i<m;i++)//主函数中确定button==1时各函数才可以被调用
 	{
  		if(strcmp(em[i].name,name)==0)//按员工姓名查找到某员工 并调出其资料
  		{
   			printf("\n此人原始记录为:\n");//显示选定员工的信息
   			printf("职工号   姓名   基本工资  职务工资   津贴    医疗保险  公积金   总工资 \n");
   			printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",em[i].num,em[i].name,em[i].jbgz,em[i].zwgz,em[i].jt,em[i].yb,em[i].gjj,em[i].total);  
   			printf("\n确定删除 请按1,不删除请按0\n");  
   			scanf("%d",&n);
            		if(n==1)
   			{
     				for(j=i;j<m-1;j++)//从第i项开始 将后一项的各成员的值赋给前一项各对应的成员 完成对第i项的删除
     				{
    					strcpy(em[j].name,em[j+1].name);
                			em[j].num=em[j+1].num;
                			em[j].jbgz=em[j+1].jbgz;
                			em[j].zwgz=em[j+1].zwgz;
                			em[j].jt=em[j+1].jt;
               				em[j].yb=em[j+1].yb;  
               				em[j].gjj=em[j+1].gjj;
               				em[j].total=em[j+1].total;
     				}
    				button=0;
   			}
  		}
 	}
 	if(!button)//button==0表明删除已完成
    		m=m-1;//总员工数减少一人
 	else
    		printf("\n查无此人!\n");
    		printf("\n 删除后的所有职工信息:\n");
    		save(m);     //调用保存函数
    		display();  //调用浏览函数
 
		printf("\n继续删除请按1,不再删除请按0\n");
 		scanf("%d",&t);
 		switch(t)
 		{
    			case 1:del();break;
    			case 0:break;
    			default :break;
 		}
}




void add()/*添加函数*/
{
 	FILE*fp;
 	int n;
    	int count=0;
    	int i;
    	int m=load();
    
	printf("\n 原来的职工信息:\n");
    	display();  
   	printf("\n");
    	fp=fopen("emploee_list","a");
    	printf("请输入想增加的职工数:\n");//确定要加入的职工数n
 	scanf("%d",&n);
    	for (i=m;i<(m+n);i++)//添加n名员工的信息
  	{
  		printf("\n 请输入新增加职工的信息:\n");
  		printf("请输入职工号:  ");
  		scanf("%d",&em[i].num);
  		printf("\n");
        	printf("请输入姓名:  ");
     		scanf("%s",em[i].name);
        	getchar();
        	printf("请输入基本工资:  ");
     		scanf("\t%d",&em[i].jbgz);
        	printf("请输入职务工资:  ");
     		scanf("%d",&em[i].zwgz);
     		printf("请输入津贴:  ");
     		scanf("%d",&em[i].jt);
     		printf("请输入医疗保险:  ");
     		scanf("\t%d",&em[i].yb);
      		printf("请输入公积金:  ");
     		scanf("%d",&em[i].gjj);
      		em[i].total=( em[i].jbgz+ em[i].zwgz + em[i].jt- em[i].yb- em[i].gjj);//计算该员工总工资
        	printf("\n");
     		count=count+1;
  		
		printf("已增加的人数:\n");
     		printf("%d\n",count);
 	}
    	printf("\n添加成功\n"); 
    	m=m+count;//将新添加员工的人数加到总员工人数中
 	printf("\n增加后的所有职工信息:\n");
 	printf("\n");
 	save(m);
    	display();//显示添加后的信息
   	fclose(fp);
}




void search()/*查询函数*/
{
    	int t,button;
 	system("cls");//清屏
 
	do
 	{
    		printf("\n按1 按工号查询\n按2 按姓名查询\n按3 回主菜单\n");
    		scanf("%d",&t);
    		if(t>=1&&t<=3)
    		{
    			button=1;
    			break;
    		}
    		else
    		{
   			button=0;
   			printf("输入错误");
    		}
 	}
    	while(button==0);//回到查询选择项
    	while(button==1)
 	{
    		switch(t)//选择查询方式
    		{ 
     			case 1:printf("按工号查询\n");search_num();break;
     			case 2:printf("按姓名查询\n");search_name();break;
    	 		case 3:menu();break;
     			default:break;
    		}
    
 	}

}




void search_num()//按职工号查询
{
  int a;
  int i,t;
  int m=load();
  printf("请输入要查找的职工号:\n");
  scanf("%d",&a);
  for(i=0;i<m;i++)
  if(a==em[i].num)
 {  
  printf("职工号   姓名   基本工资  职务工资   津贴    医疗保险  公积金   总工资 \n");
  printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",em[i].num,em[i].name,em[i].jbgz,em[i].zwgz,em[i].jt,em[i].yb,em[i].gjj,em[i].total);   
  break;
 
 }
   if(i==m)  
   printf("\n对不起,查无此人\n");
   printf("\n");
   printf("返回查询函数请按1,继续查询职工号请按2\n");
   scanf("%d",&t);
   switch(t)
   { 
   case 1:search();break;
   case 2: break;
   default:break;
   }
}


void search_name()
{
  char name[30];
  int i,t;
  int m=load();
  printf("请输入姓名:\n");
  scanf("%s",name);
  for(i=0;i<m;i++)
   if(strcmp(em[i].name,name)==0)
 {
    printf("\n已找到,其记录为:\n");
     printf("职工号   姓名   基本工资  职务工资   津贴    医疗保险  公积金   总工资 \n");
     printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",em[i].num,em[i].name,em[i].jbgz,em[i].zwgz,em[i].jt,em[i].yb,em[i].gjj,em[i].total);      
 }
   if(i==m) 
   printf("\n\n");
   printf("\n");
   printf("返回查询菜单请按1,继续查询姓名请按2\n");
   scanf("%d",&t);
  switch(t)
  { 
   case 1:search();break;
   case 2:break;
   default :break;
  }
 }




void modify() /*修改函数*/
{
    	int num;
    	char name[20];
    	int jbgz;  
    	int zwgz;
    	int jt;
    	int yb;
    	int gjj;
    	int b,c,i,n,t,button; 
 	int m=load();
    	system("cls");

    	printf("\n 原来的职工信息:\n");
    	display(); 
 	printf("\n");
    
	printf("请输入要修改的职工的姓名:\n");
 	scanf("%s",name);
 	for(button=1,i=0;button&&i<m;i++)
 	{
  		if(strcmp(em[i].name,name)==0)
  		{
    			printf("\n此人原始记录为:\n");
     			printf("职工号   姓名   基本工资  职务工资   津贴    医疗保险  公积金   总工资 \n");
     			printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",em[i].num,em[i].name,em[i].jbgz,em[i].zwgz,em[i].jt,em[i].yb,em[i].gjj,em[i].total);    
     			printf("\n确定 按1 ; 不修改请按0\n");
     			scanf("%d",&n);
            		if(n==1)
   			{
               			printf("\n需要进行修改的选项\n 1.职工号 2.姓名 3.基本工资 4.职务工资 5.津贴 6.医疗保险 7.公积金 8.返回上层\n");  
               			printf("请选择序号1-8:\n");  
               			scanf("%d",&c);  
               			if(c>8||c<1)  
         				printf("\n选择错误,请重新选择!\n");  
   			}
        		button=0;
  		}		
        
 	}
    	if(button==1)
 	printf("\n查无此人\n");  
    	
	do  
 	{
  		switch(c)      /*因为当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人*/
  		{  
           		case 1:printf("职工号改为: ");
      		 	       scanf("%d",&num);
      			       em[i-1].num=num;
           		       break;  
           		case 2:printf("姓名改为: ");
                               scanf("%s",name);
                               strcpy(em[i-1].name,name); 
                               break;  
           		case 3:printf("基本工资改为: ");
                               	getchar();
                               	scanf("%d",&jbgz);
                               	em[i-1].jbgz=jbgz;
      			       	em[i-1].total=( em[i-1].jbgz+ em[i-1].zwgz + em[i-1].jt- em[i-1].yb- em[i-1].gjj);
           			break;  
           		case 4:printf("职务工资改为: ");
      				scanf("%d",&zwgz);
      				em[i-1].zwgz=zwgz;
     		 		em[i-1].total=( em[i-1].jbgz+ em[i-1].zwgz + em[i-1].jt- em[i-1].yb- em[i-1].gjj);
           			break;  
           		case 5:printf("津贴改为: ");
      				scanf("%d",&jt);
      				em[i-1].jt=jt; 
      				em[i-1].total=( em[i-1].jbgz+ em[i-1].zwgz + em[i-1].jt- em[i-1].yb- em[i-1].gjj);
           			break;  
           		case 6:printf("医疗保险改为: ");
      				scanf("%d",&yb);
      				em[i-1].yb=yb;
      				em[i-1].total=( em[i-1].jbgz+ em[i-1].zwgz + em[i-1].jt- em[i-1].yb- em[i-1].gjj);
           			break;  
           		case 7:printf("公积金改为: ");
      				scanf("%d",&gjj);
      				em[i-1].gjj=gjj;
      				em[i-1].total=( em[i-1].jbgz+ em[i-1].zwgz + em[i-1].jt- em[i-1].yb- em[i-1].gjj);
           			break;  
           		case 8:modify(); 
           			break;  
  		} 
  	
		printf("\n");
  		printf("\n\n 确定修改 请按1 ; 重新修改 请按2:  \n"); 
  		scanf("%d",&b);
 	}	  
   	while(b==2);
   	printf("\n修改后的所有职工信息:\n");
   	printf("\n");
   	save(m);
   	
	display();
   	printf("\n按1 继续修改 ,不再修改请按0\n");
   	scanf("%d",&t);
   	switch(t)
 	{
    		case 1:modify();break;
    		case 0:break;
    		default :break;
 	}
}




void sta()//统计函数
{
 	int i;
 	int sum=0; 
 	int a=0,b=0,c=0;
 	int m=load();
	system("cls");//清屏函数
 	for(i=0;i<m;i++) /*m为输入部分的职工人数*/
 		{sum+=em[i].total;
  		if((em[i].total)<=2000&&em[i].total>=1000) 
    			{a++;}
  		if(em[i].total>2000&&em[i].total<=3000) 
    			{b++;}
  		if(em[i].total>2000) 
    			{c++;}
		}

	printf("\n\n工资总额为：%d\n",sum);
	printf("平均工资为：%d\n",sum/m);
	printf("\n基本工资、职务工资、津贴之和\n");
	printf("在1000-2000圆的员工占总员工的百分之%d\n",a*100/m); 
	printf("在2000-3000圆的员工占总员工的百分之%d\n",b*100/m); 
	printf("在3000圆以上的员工占总员工的百分之%d\n",c*100/m);
	printf("\n\n按任意键继续");
	getch();
	menu();
}




int main()//主函数
{   
	int n,button;
 	char a; 
 	start();
	getch();
 	menu();  

 	do
 	{
    		printf("功能选择(1--8):\n");
    		scanf("%d",&n);
    		if(n>=1&&n<=7)
    		{
    			button=1;
    			break;
    		}
    		else
    		{
   			button=0;
   			printf("您输入有误,请重新选择!");
    		}
 	}
    	while(button==0);
    	while(button==1)
     {
  	
	switch(n)
  	{	
       		case 1: input();break;
       		case 2: display();break;
       		case 3: search();break; 
       		case 4:del();break;
       		case 5: add();break;
       		case 6:modify();break;
       		case 7:sta();break;
       		case 8:exit(0);break;
       		default :break;
  	}
  
	getchar();
  	printf("\n");
  	printf("按任意键继续\n");
  	getch();
     	system("cls");  /*清屏*/
     	menu(); /*调用菜单函数*/
     	printf("功能选择(1--8):\n");
     	scanf("%d",&n);
     	printf("\n");

     }
 
}

