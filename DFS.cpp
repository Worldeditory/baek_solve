#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int N, ans;
string S;

int cal(int a, int b, char X){
    if(X == '+'){
        return a+b;
    } else if(X == '-'){
        return a-b;
    } else {
        return a*b;
    }
}

void recur(int idx, int now){
    if(idx > N-1){
        ans = max(ans,now);
        return;
    }
    char oper = (idx == 0) ? '+' : S[idx - 1];

    if(idx+2 < N){
        int bracket = cal(S[idx] - '0', S[idx+2] - '0' , S[idx + 1]);
        recur(idx+4 , cal(now, bracket, oper));
    }
    recur(idx + 2, cal(now, S[idx] - '0', oper));
}

int main(){
    cin >> N;
    cin >> S;

    ans = INT_MIN;
    recur(0,0);
    cout << ans;
    return 0;
}