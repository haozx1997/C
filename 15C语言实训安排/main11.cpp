//��ʱ����scanf�Ļ������������ڲ˵�ѡ��ʱ���Ȱѻ������뵼�� ������������������롱����ȷ���������Ƿ������� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

struct worker
{
	int num;
	char name[20];
	int basic,job,pay,medical,gong,total;//�������ʡ�ְ���ʡ���λ������ҽ�Ʊ��ա�������
};struct worker wo[100];
int work_num;//ְ�������� 
int work_num_now;//���������ְ���ǵڼ��� 
int i;
double a_basic,a_job,a_pay,a_medical,a_gong,a_total;
int s_basic,s_job,s_pay,s_medical,s_gong,s_total;

void menu_main();
void search_id();
void search_name();
void choose_search();
void choose_delete();
void delete_id();
void delete_name();
void choose_updata();
void updata_id();
void updata_name();


void input_record()//���� 
{
	system("cls");
	printf("                 ����ְ����Ϣ\n");
	printf("������ְ��������");
	scanf("%d",&work_num);
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		printf("������ְ��ID��       ");
		scanf("%d",&wo[work_num_now].num); 
		printf("������ְ��������     ");
		scanf("%s",&wo[work_num_now].name);		
		printf("������ְ���������ʣ� "); 
		scanf("%d",&wo[work_num_now].basic);
		printf("������ְ��ְ���ʣ� ");
		scanf("%d",&wo[work_num_now].job);
		printf("������ְ����λ������ ");
		scanf("%d",&wo[work_num_now].pay);
		printf("������ְ��ҽ�Ʊ��գ� ");
		scanf("%d",&wo[work_num_now].medical);
		printf("������ְ��������   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;
        work_num_now++;

	}
	printf("\n\n¼����ϰ���������ز˵�");
	getch(); 
	menu_main();
}

void show_record()//�鿴 
{
	system("cls");
	printf("                 �鿴ְ����Ϣ\n");
	printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		
		printf("%6d",wo[work_num_now].num); 
		printf("%8s",wo[work_num_now].name);		
		printf("%11d",wo[work_num_now].basic);
		printf("%11d",wo[work_num_now].job);
		printf("%11d",wo[work_num_now].pay);
		printf("%11d",wo[work_num_now].medical);
		printf("%9d",wo[work_num_now].gong);
		printf("%10d\n",wo[work_num_now].total);		
	    work_num_now++;

    }
    printf("\n\n����������ز˵�");
	getch(); 
   	menu_main();
}


void search_record()//��ѯ 
{
	system("cls");
	printf("                 ��ѯְ����Ϣ\n\n");
	printf("1. ��ID����\n");
	printf("2. ����������\n");
	printf("3. �������˵�\n");
    printf("��ѡ�� ");
    choose_search();
	
}

void choose_search()//��������Ϊ�û�Ҫ���
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:search_id();break;
		case 2:search_name();break;
		case 3:menu_main();break; 
		default:printf("�����������������: ");getchar();choose_search();
	}
 } 


void search_id()//��ID���� 
{
	system("cls");
	printf("                 ��ID����\n");
	
	int the_id,TF=0;//�Ƿ��д�ID 
	printf("����Ҫ���ҵ�ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);	 	
	 }
	else printf("�޴�ID\n"); 
  	
    printf("\n\n�������������һ��");
	getch();
	search_record();
}

void search_name()//���������� 
{
	system("cls");
	printf("                 ����������\n");
	
    char the_name[20];
    int TF=0;
	printf("����Ҫ���ҵ�����:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);	 	
	 }
	else printf("���޴���\n");	
  	
    printf("\n\n�������������һ��");
	getch();
	search_record();
}





void add_record()//��� 
{
	system("cls");
	printf("                 ���ְ����Ϣ\n");
	
	printf("���������ְ��������");
	int add_num; 
	scanf("%d",&add_num);
	
	work_num_now=work_num;
	work_num+=add_num;
	while(add_num--)
	{
		printf("������ְ��ID��       ");
		scanf("%d",&wo[work_num_now].num); 
		printf("������ְ��������     ");
		scanf("%s",&wo[work_num_now].name);		
		printf("������ְ���������ʣ� "); 
		scanf("%d",&wo[work_num_now].basic);
		printf("������ְ��ְ���ʣ� ");
		scanf("%d",&wo[work_num_now].job);
		printf("������ְ����λ������ ");
		scanf("%d",&wo[work_num_now].pay);
		printf("������ְ��ҽ�Ʊ��գ� ");
		scanf("%d",&wo[work_num_now].medical);
		printf("������ְ��������   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;
        work_num_now++;

	}


    printf("\n\n����������ز˵�");
	getch();
	menu_main();
}

void delete_record()//ɾ�� 
{
	system("cls");
	printf("                 ɾ��ְ����Ϣ\n");
	
 	printf("1. ��IDɾ��\n");
	printf("2. ������ɾ��\n");
	printf("3. �������˵�\n");
    printf("��ѡ�� ");
    choose_delete();
  	
    printf("\n\n����������ز˵�");
	getch();
	menu_main();
}

void choose_delete()//��������Ϊ�û�Ҫ���
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:delete_id();break;
		case 2:delete_name();break;
		case 3:menu_main();break; 
		default:printf("�����������������: ");getchar();choose_delete();
	}
 }
 
 
void delete_id()//��IDɾ�� 
{
	system("cls");
	printf("                 ��IDɾ��\n");
	
	int the_id,TF=0;//�Ƿ��д�ID 
	printf("����Ҫɾ����ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
        for(;i<work_num;i++)
         wo[i]=wo[i+1];
        work_num--; 
	}
	else printf("�޴�ID\n"); 
  	
    printf("\n\nIDΪ%d��ְ��ɾ���ɹ�\n\n�������������һ��",the_id);
	getch();
	delete_record();	
}

void delete_name()//������ɾ��
{
	system("cls");
	printf("                 ������ɾ��\n");
	
    char the_name[20];
    int TF=0;
	printf("����Ҫɾ��������:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
        for(;i<work_num;i++)
         wo[i]=wo[i+1];
        work_num--; 	 	
	 }
	else printf("���޴���\n");	
  	
    printf("\n\n%s��ɾ��\n\n�������������һ��",the_name);
	getch();
	delete_record();
}	
 
 



void updata_record()//���� 
{
	system("cls");
	printf("                 ����ְ����Ϣ\n");
	
	printf("1. ��ID����\n");
	printf("2. ����������\n");
	printf("3. �������˵�\n");
    printf("��ѡ�� ");
    choose_updata();

    printf("\n\n����������ز˵�");
	getch();	
	menu_main();
}

void choose_updata()//��������Ϊ�û�Ҫ���
{
	int how_search;
	scanf("%d",&how_search);
	switch(how_search)
	{
		case 1:updata_id();break;
		case 2:updata_name();break;
		case 3:menu_main();break; 
		default:printf("�����������������: ");getchar();choose_updata();
	}
 }
 
 
void updata_id()//��ID���� 
{
	system("cls");
	printf("                 ��ID����\n");
	
	int the_id,TF=0;//�Ƿ��д�ID 
	printf("����Ҫ���µ�ID:"); 
	scanf("%d",&the_id);
	for(i=0;i<work_num;i++)
	{
		if(wo[i].num==the_id)
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);
			 	
	 	printf("����¸�ְ����Ϣ\n");
		printf("������ְ��ID��       ");
		scanf("%d",&wo[i].num); 
		printf("������ְ��������     ");
		scanf("%s",&wo[i].name);		
		printf("������ְ���������ʣ� "); 
		scanf("%d",&wo[i].basic);
		printf("������ְ��ְ���ʣ� ");
		scanf("%d",&wo[i].job);
		printf("������ְ����λ������ ");
		scanf("%d",&wo[i].pay);
		printf("������ְ��ҽ�Ʊ��գ� ");
		scanf("%d",&wo[i].medical);
		printf("������ְ��������   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;	 	
     }
	else printf("�޴�ID\n"); 
  	
    printf("\n\nIDΪ%d��ְ�����³ɹ�\n\n�������������һ��",the_id);
	getch();
	updata_record();	
}

void updata_name()//�����ָ���
{
	system("cls");
	printf("                 ����������\n");
	
    char the_name[20];
    int TF=0;
	printf("����Ҫ���µ�����:"); 
	scanf("%s",the_name);
	for(i=0;i<work_num;i++)
	{
		
		if(!strcmp(the_name,wo[i].name))
		 {
		 	TF=1;break;
		 }
	} 
	if(TF)
	 {
	    printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");	 	
		printf("%6d",wo[i].num); 
		printf("%8s",wo[i].name);		
		printf("%11d",wo[i].basic);
		printf("%11d",wo[i].job);
		printf("%11d",wo[i].pay);
		printf("%11d",wo[i].medical);
		printf("%9d",wo[i].gong);
		printf("%10d\n",wo[i].total);
			 	
	 	printf("����¸�ְ����Ϣ\n");
		printf("������ְ��ID��       ");
		scanf("%d",&wo[i].num); 
		printf("������ְ��������     ");
		scanf("%s",&wo[i].name);		
		printf("������ְ���������ʣ� "); 
		scanf("%d",&wo[i].basic);
		printf("������ְ��ְ���ʣ� ");
		scanf("%d",&wo[i].job);
		printf("������ְ����λ������ ");
		scanf("%d",&wo[i].pay);
		printf("������ְ��ҽ�Ʊ��գ� ");
		scanf("%d",&wo[i].medical);
		printf("������ְ��������   ");
		scanf("%d",&wo[work_num_now].gong);getchar();
		wo[work_num_now].total=wo[work_num_now].basic+wo[work_num_now].job+wo[work_num_now].pay-wo[work_num_now].gong-wo[work_num_now].medical;	 	
	 }
	else printf("���޴���\n");	
  	
    printf("\n\n%s�Ѹ���\n\n�������������һ��",the_name);
	getch();
	updata_record();
}	

void statistics_record()//ͳ�� 
{
	system("cls");
	printf("                 ͳ��ְ����Ϣ\n");
	
	
	printf("  ID��    ����   ��������   ְ����   ��λ����   ҽ�Ʊ���   ������    �ܹ���\n");
	i=work_num;	
	work_num_now=0;
	while(i--)
	{
		
		printf("%6d",wo[work_num_now].num); 
		printf("%8s",wo[work_num_now].name);		
		printf("%11d",wo[work_num_now].basic);
		printf("%11d",wo[work_num_now].job);
		printf("%11d",wo[work_num_now].pay);
		printf("%11d",wo[work_num_now].medical);
		printf("%9d",wo[work_num_now].gong);
		printf("%10d\n",wo[work_num_now].total);		
	    work_num_now++;

    }	
    s_basic=s_job=s_pay=s_medical=s_gong=s_total=0;
    for(i=0;i<work_num;i++)
    {
    	s_basic+=wo[i].basic;
    	s_job+=wo[i].job;
    	s_pay+=wo[i].pay;
    	s_medical+=wo[i].medical;
    	s_gong+=wo[i].gong;
    	s_total+=wo[i].total;
   	}
   	a_basic=(double)s_basic/(work_num);
   	a_job=(double)s_job/(work_num);
   	a_pay=(double)s_pay/(work_num);
   	a_medical=(double)s_medical/(work_num);
   	a_gong=(double)s_gong/(work_num);
   	a_total=(double)s_total/(work_num);
   	
    printf("����ƽ������    %9.2f%11.2f%11.2f%11.2f%9.2f%10.2f",a_basic,a_job,a_pay,a_medical,a_gong,a_total);
	
    printf("\n\n����������ز˵�");
	getch();
	menu_main();
}

void file_save()//���� 
{
	system("cls");
	printf("                 ������Ϣ���ļ�\n");
	
	FILE *filep;
	int i;
	if((filep=fopen("F:\\C\\15C����ʵѵ����\\15zhigong.txt","wb"))==NULL)
	 {
	 	printf("cannot open file\n");
	 	return;
	  } 
	for(i=0;i<work_num;i++)
	 if(fwrite(&wo[i],sizeof(struct worker),1,filep)!=1)
	  {
	  	 printf("file write error\n");
	  	 getch();
	  	 return;
	  }  
	 fclose(filep);
	  
	
    printf("\n\n�ļ��ѱ���\n\n����������ز˵�");
	getch();
	menu_main();
}


void file_in()//���� 
{
	system("cls");
	printf("                 ������Ϣ�ļ�\n");
	
	int i=0,F=2;//F���ڹر� 
	FILE *filep;
	filep=fopen("F:\\C\\15C����ʵѵ����\\15zhigong.txt","rb");
	while(1)
	{
		if( feof(filep))break;
		
		fread(&wo[i],sizeof(struct worker),1,filep);
		
		i++;

	
		
	}
	work_num=--i;
	fclose(filep);
	
	
    printf("�ļ�����ɹ�\n\n����������ز˵�");
	getch();
	menu_main();
}

void choose()//�˵�ѡ�� 
{
	int menu ;
	scanf("%d",&menu);
	getchar();
	switch(menu)
	{
		case 1:input_record();break;
		case 2:show_record();break;
		case 3:search_record();break;
		case 4:add_record();break;
		case 5:delete_record();break;
		case 6:updata_record();break;
		case 7:statistics_record();break;
		case 8:file_save();break;
		case 9:file_in();break;
		case 0:exit(0);
		default:printf("�����������������: ");choose();
	}
}


void menu_main()//��ʾ�˵� 
{
	system("cls");
	printf("               ְ�����ʹ���ϵͳ\n");
	printf("=======================================================\n");
	printf("                    �˵�\n");
	printf("               1 ����ְ����Ϣ\n");
	printf("               2 �鿴ְ����Ϣ\n");
	printf("               3 ��ѯְ����Ϣ\n");
	printf("               4 ���ְ����Ϣ\n");
	printf("               5 ɾ��ְ����Ϣ\n");
	printf("               6 ����ְ����Ϣ\n");
	printf("               7 ͳ��ְ����Ϣ\n");
	printf("               8 ������Ϣ���ļ�\n");	
	printf("               9 ������Ϣ�ļ�\n");	
	printf("               0 �˳�ϵͳ\n\n");
	printf("��ѡ��"); 
	choose();

}





int main()
{
	menu_main();	
}
