#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<utility>

using namespace std;
int N,ans=0;
map<pair<int,int>,int> M;

void recur(int x, int y, char state){
    if(M[{x,y}] == 1){
        return;
    }
    if(state == 'U'){
        if(M[{x-1,y}] == 1){
            return;
        }
        if(M[{x,y-1}] == 1){
            return;
        }
    }
    if(x>N || y>N){
        return;
    }
    if(x==N && y==N){
        ans++;
        return;
    }
    if(state == 'R'){
        recur(x+1,y,'R');
        recur(x+1,y+1,'U');
    } else if(state == 'U') {
        recur(x+1,y,'R');
        recur(x+1,y+1,'U');
        recur(x,y+1,'D');

    } else if(state == 'D'){
        recur(x,y+1,'D');
        recur(x+1,y+1,'U');
    }
}

int main(){
    cin >> N;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            int a;
            cin >> a;
            M.insert({{j,i},a});
        }
    }
    recur(2,1,'R');
    cout << ans;
    return 0;
}