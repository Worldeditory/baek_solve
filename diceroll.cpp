#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dy[4] = { 1, -1, 0, 0 }; // 동쪽은 0, 서쪽은 1, 북쪽은 2, 남쪽은 3
int dx[4] = { 0, 0, -1, 1 };
//밑면 0 윗면 5 동 서 남 북 1,2,3,4
void dice_roll(int* dice, int way){
    int tem[6];
    for(int i=0 ; i< 6 ;i++){
        tem[i]=dice[i];
    }
    if(way==0){//동
        dice[0]=tem[1];
        dice[1]=tem[5];
        dice[2]=tem[0];
        dice[5]=tem[2];
    }
    else if(way==1){//서
        dice[0]=tem[2];
        dice[1]=tem[0];
        dice[2]=tem[5];
        dice[5]=tem[1];
    }
    else if(way==2){//북
        dice[0]=tem[4];
        dice[3]=tem[0];
        dice[4]=tem[5];
        dice[5]=tem[3];
    }
    else if(way==3){//남
        dice[0]=tem[3];
        dice[3]=tem[5];
        dice[4]=tem[0];
        dice[5]=tem[4];   
    }
}

int main(){
    int dice[6]={0,0,0,0,0,0};//밑면 0 윗면 5 동 서 남 북 1,2,3,4
    int hei,wid;
    int x,y;
    int N_ord;
    int ord;
    int** map;
    scanf("%d %d %d %d %d",&hei,&wid,&x,&y,&N_ord);
    map = (int**)malloc(sizeof(int*)*hei);
    for(int i=0; i<hei ; i++){
         map[i] = (int*)malloc(sizeof(int)*wid);
    }
    for(int i = 0 ; i<hei ; i++){
        for(int j=0 ; j<wid ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i = 0 ; i<N_ord ; i++){
        scanf("%d",&ord);
        ord -= 1;
        x+=dx[ord];
        y+=dy[ord];
        // printf("x:%d y:%d\n",x,y);
        if(x>=hei || y>=wid || x<0 || y<0){
            x-=dx[ord];
            y-=dy[ord];
            continue;
        }
        dice_roll(dice, ord);
        if(map[x][y] == 0){
            map[x][y] = dice[0];
        }
        else{
            dice[0] = map[x][y];
            map[x][y]=0;
        }
        printf("%d\n",dice[5]);
    }
}