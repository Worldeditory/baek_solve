#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
int dy[4] = { -1, 0, 1, 0 }; // 서쪽은 0, 북쪽은 1, 동쪽은 2, 남쪽은 3
int dx[4] = { 0, -1, 0, 1 };
using namespace std;
typedef struct decar{
    int x;
    int y;
}de;
typedef struct {
    int time;
    char di;
}ord;
int map[110][110],check[110][110],x,y;
int main(){
    int N,K;//N*N크기 맵에 K개의 사과
    int way = 2,num_ord;
    ord order[110];
    de temp;
    scanf("%d",&N);
    scanf("%d",&K);
    queue<de> snake;
    for(int i=0 ; i<K ; i++){
        scanf("%d %d",&x,&y);
        map[x][y] = 1;
    }
    scanf("%d",&num_ord);
    for(int i=0 ; i<num_ord ; i++ ){
        scanf("%d %c",&order[i].time,&order[i].di);
    }
    int count_ord = 0;
    x=1; y=1;
    temp.x=1; temp.y=1;
    snake.push(temp);
    for(int i = 1; i<10000 ; i++){
        x+=dx[way];
        y+=dy[way];
        temp.x=x;
        temp.y=y;
        snake.push(temp);
        if(check[x][y] == 1 || x<1 || y<1 || x>N ||y>N){
            printf("%d",i);
            break;    
        }
        check[temp.x][temp.y] = 1;
        if(map[x][y]==1){
            map[x][y]=0;
        }
        else{
            temp = snake.front();
            //printf("x:%d y:%d size=%d\n",temp.x, temp.y, snake.size()); 
            snake.pop();
            check[temp.x][temp.y] = 0; 
        }
        if(i==order[count_ord].time){
            if(order[count_ord].di=='L'){
                way-=1;
                if(way == -1) way = 3;
            }
            if(order[count_ord].di=='D'){
                way=(way+1)%4;
            }
            count_ord++;
        }

    }
}