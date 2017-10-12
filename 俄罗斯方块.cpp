#include<stdio.h>  
#include<stdlib.h>  
#include<windows.h>  
#include<time.h>  
#include<conio.h>  
  
#define MOD 28  
#define SIZE_N 30  
#define SIZE_M 30 
  
int cur_x,cur_y;  
int score,mark,next,map[SIZE_N][SIZE_M],Gamespeed=300;  
  
int shape[28][6]={//���Ǹ��Ƚ�͵���ķ���������7�ַ��飬������ת�ܹ�28��  
    {0,-1,0,-2,1,0}, {0,1,1,0,2,0}, {-1,0,0,1,0,2}, {0,-1,-1,0,-2,0},  
    {0,-1,0,1,-1,0}, {0,1,1,0,-1,0}, {1,0,0,-1,0,1}, {1,0,-1,0,0,-1},  
    {-1,1,0,1,1,0}, {0,-1,1,0,1,1}, {-1,0,0,-1,1,-1}, {-1,-1,-1,0,0,1},  
    {-1,0,0,1,1,1}, {0,1,1,-1,1,0}, {-1,0,0,1,1,1}, {0,1,1,-1,1,0},  
    {-1,0,0,-1,0,-2}, {-1,0,-2,0,0,1}, {0,1,0,2,1,0}, {0,-1,1,0,2,0},  
    {0,1,1,0,1,1}, {0,-1,1,0,1,-1}, {-1,0,0,-1,-1,-1}, {-1,0,-1,1,0,1},  
    {0,1,0,2,0,3}, {1,0,2,0,3,0}, {0,-1,0,-2,0,-3}, {-1,0,-2,0,-3,0}  
};  
  
void gotoxy(int x,int y){//gotoxy��TC������system.h���ļ����һ����  
    COORD c;  
    c.X=x-1; c.Y=y-1;  
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);  
}  
void Gameover(){//��Ϸ�������ж�  
    int i,j,flag=0;  
    for(j=1;j<SIZE_M-1;j++){  
        if(map[1][j]!=0){  
            flag=1;break;  
        }  
    }  
    if(flag==1){  
        for(i=1;i<SIZE_N-1;i++){  
            gotoxy(2,i+1);  
            for(j=1;j<SIZE_M-1;j++){  
                printf("��");  
            }puts("");  
        }  
        gotoxy(7,9);  
        printf("GAME OVER!");  
        getch();
        gotoxy(1,SIZE_N+1);  
        exit(0);  
    }  
}  
void ShowMap(int id){  
    int i,j;  
    gotoxy(1,1);  
    if(id!=-1){  
        for(i=0;i<SIZE_N;i++){  
            for(j=0;j<SIZE_M;j++){  
                if(i==0&&j==0 || i==0&&j==SIZE_M-1 || j==0&&i==SIZE_N-1 || j==SIZE_M-1&&i==SIZE_N-1)printf(" ");  
                else if(i==0 || i==SIZE_N-1)printf("--");  
                else if(j==0 || j==SIZE_M-1)printf("|");  
                else if(map[i][j]==2) printf("��");  
                else if(i==cur_x+shape[id][0] && j==cur_y+shape[id][1] ||  
                    i==cur_x+shape[id][2] && j==cur_y+shape[id][3] ||  
                    i==cur_x+shape[id][4] && j==cur_y+shape[id][5] ||  
                    i==cur_x && j==cur_y)  
                    printf("��");  
                else if(map[i][j]==0) printf("  ");   
            }  
            if(i==1)printf("   next:");  
            if(i==11)printf("   score :   %d",score);  
            if(i==14)printf("   speed :   %d",score/100+1);  
            puts("");  
        }  
    }  
    else {  
        mark=1;  
        for(i=0;i<SIZE_N;i++){  
            for(j=0;j<SIZE_M;j++){  
                if(i==0&&j==0 || i==0&&j==SIZE_M-1 || j==0&&i==SIZE_N-1 || j==SIZE_M-1&&i==SIZE_N-1)printf(" ");  
                else if(i==0 || i==SIZE_N-1)printf("--");  
                else if(j==0 || j==SIZE_M-1)printf("|");  
                else if(map[i][j]==2) printf("��");  
                else if(map[i][j]==0) printf("  ");   
            }  
            if(i==1)printf("   next:");  
            if(i==11)printf("   score :   %d",score);  
            if(i==14)printf("   speed :   %d",score/100+1);  
            puts("");  
        }  
    }  
    /*���� next ����Ĵ����Ȳ����ٻ�ͼ*/  
    gotoxy(30,6); printf("  ");  
    for(i=0;i<6;i=i+2){  
        gotoxy(30+2*shape[id][i+1],6+shape[id][i]); printf("  ");  
    }  
    gotoxy(30,6); printf("��");  
    for(i=0;i<6;i=i+2){  
        gotoxy(30+2*shape[next][i+1],6+shape[next][i]); printf("��");  
    }  
    Sleep(Gamespeed);  
}  
  
void init(int id){//��ʼ��������cur_x��cur_y��ȫ�ֱ�����������ƶ������λ��  
    memset(map,0,sizeof(map));  
    for(int i=0;i<SIZE_N;i++){  
        for(int j=0;j<SIZE_M;j++)  
            if(i==SIZE_N-1 || j==0 || j==SIZE_M-1)  
                map[i][j]=-1;  
    }  
    cur_x=0; cur_y=5;  
    ShowMap(id);  
}  
  
int judge_in(int x,int y,int id){//�ж��Ƿ���磬����˵�Ƿ�Ϸ�  
    if(map[x][y]!=0)return 0;  
    for(int i=0;i<6;i=i+2){  
        if(map[ x+shape[id][i] ][ y+shape[id][i+1] ]!=0)return 0;  
    }return 1;  
}  
  
void fun_score(){//�÷֣������е���˸������ͼ�ε�����ƽ��  
    for(int i=1;i<SIZE_N-1;i++){  
        int flag=0;  
        for(int j=1;j<SIZE_M-1;j++){  
            if(map[i][j]!=2){ flag=1;break; }  
        }  
        if(flag==0){  
            int k=3;  
            while(k--){  
                gotoxy(2,i+1);  
                for(int ii=1;ii<SIZE_M-1;ii++){  
                    if(map[i][ii]==2){  
                        if(k%2==1)printf("  ");  
                        else printf("��");  
                    }  
                }Sleep(100);  
            }  
            for(int ii=i;ii>1;ii--){  
                for(int jj=1;jj<SIZE_M-1;jj++)map[ii][jj]=map[ii-1][jj];  
            }  
            ShowMap(-1);  
            score+=10;  
            if(score%100==0 && score!=0)Gamespeed-=50;  
        }  
    }  
}  
  
int main(){  
    int i,id,set=1;  
      
    srand(time(NULL));  
    id=rand()%MOD; id=(id+MOD)%MOD;  
    next=rand()%MOD; next=(next+MOD)%MOD;  
      
    init(id);  
      
    while(1){  
Here:   mark=0;  
        if(set==0){  
            id=next;  
            next=rand()%MOD; next=(next+MOD)%MOD;  
            cur_x=0;cur_y=5;  
            set=1;  
        }  
          
        while(!kbhit()){  
            Gameover();  
            if(judge_in(cur_x+1,cur_y,id)==1) cur_x++;  
            else {  
                map[cur_x][cur_y]=2;  
                for(i=0;i<6;i=i+2)  
                    map[ cur_x+shape[id][i] ][ cur_y+shape[id][i+1] ]=2;  
                fun_score();  
                set=0;  
            }  
            if(mark!=1)ShowMap(id);  
            goto Here;  
        }//end of while(!kbhit())  
          
        char key;  
        key=getch();  
          
        if(key==72||key == 'w'||key == 'W'){  
            int tmp=id;  
            id++;  
            if( id%4==0 && id!=0 )id=id-4;  
            if(judge_in(cur_x,cur_y,id)!=1)id=tmp;  
        }  
        else if((key==80||key == 's'||key == 'S') && judge_in(cur_x+1,cur_y,id)==1)cur_x++;  
        else if((key==75||key == 'a'||key == 'A') && judge_in(cur_x,cur_y-1,id)==1)cur_y--;  
        else if((key==77||key == 'd'||key == 'D') && judge_in(cur_x,cur_y+1,id)==1)cur_y++;  
        else if(key==27){gotoxy(1,SIZE_N+1);exit(0);}  
    }
	return 0;  
}  
