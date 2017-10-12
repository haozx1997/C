# include<stdio.h>
# include<stdlib.h>
int map[5][5];
int dir[4][2]={1,0,-1,0,0,1,0,-1};  //���ߵ��ĸ�����
struct node{
       int x,y;
};
struct node queue[50],record[5][5];//queue��¼���ߵĵ㣬���ѣ�record��¼�ĵ��ǰ��
void bfs()   
{
       int head,tail,i;
       struct node cur,next;//curΪ��ǰλ�ã�nextΪ��һ��λ��
       head=tail=0;
       cur.x=queue[tail].x;
       cur.y=queue[tail].y;
       tail++;
       while(head<tail)
       {
       	printf("%d_%d\n",cur.x,cur.y);
              cur=queue[head++];
              for(i=0;i<4;i++)
              {
                     next.x=cur.x+dir[i][0];
                     next.y=cur.y+dir[i][1];
                     if(next.x>=0&&next.y>=0&&next.x<5&&next.y<5&&map[next.x][next.y]==0)
                     {
                            record[next.x][next.y].x=cur.x;
                            record[next.x][next.y].y=cur.y;//��¼next��ǰ������next�����꣨��Ϊnext��¼���ǵ�һ������õص��ǰ������󱻱���߹����ʲ��õ��ı�������ǰ�����������ǣ�
                            if(next.x==4&&next.y==4)
                                   return ;
                            else
                            {
                                   map[next.x][next.y]=1;//����߹�
                                   queue[tail++]=next;
                            }
                     }
              }
       }
}
int main()
{
       int i,j,k,m,n;
       struct node cur;
       for(i=0;i<5;i++)
              for(j=0;j<5;j++)
                     scanf("%d",&map[i][j]);
       cur.x=0;
       cur.y=0;
       map[0][0]=1;
       queue[0]=cur;
       bfs();
       k=0;
       queue[k].x=4;
       queue[k++].y=4;
       i=j=4;
       while(i!=0||j!=0)//����record�ļ�¼���Ӻ���ǰ������·����������queue��
       {
              m=i;n=j;
              i=record[m][n].x;
              j=record[m][n].y;
              queue[k].x=i;
              queue[k++].y=j;
       }
       for(i=k-1;i>=0;i--)//���·��
              printf("(%d, %d)\n",queue[i].x,queue[i].y);
       return 0;
}
