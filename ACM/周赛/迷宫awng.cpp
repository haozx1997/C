# include<stdio.h>
# include<stdlib.h>
int map[5][5];
int dir[4][2]={1,0,-1,0,0,1,0,-1};  //可走的四个方向
struct node{
       int x,y;
};
struct node queue[50],record[5][5];//queue记录可走的点，广搜；record记录改点的前驱
void bfs()   
{
       int head,tail,i;
       struct node cur,next;//cur为当前位置，next为下一个位置
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
                            record[next.x][next.y].y=cur.y;//记录next的前驱，即next的坐标（因为next记录的是第一个到达该地点的前驱，随后被标记走过，故不用担心被后来的前驱坐标所覆盖）
                            if(next.x==4&&next.y==4)
                                   return ;
                            else
                            {
                                   map[next.x][next.y]=1;//标记走过
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
       while(i!=0||j!=0)//根据record的记录，从后往前回溯其路径，并存在queue中
       {
              m=i;n=j;
              i=record[m][n].x;
              j=record[m][n].y;
              queue[k].x=i;
              queue[k++].y=j;
       }
       for(i=k-1;i>=0;i--)//输出路径
              printf("(%d, %d)\n",queue[i].x,queue[i].y);
       return 0;
}
