#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<utility>
#include<cmath>

using namespace std;

int N,M,D,ans=0;
int Map[16][16];
vector<pair<int,int>> Ene,a1,a2,a3;
void temp(){
    for(int i=1 ; i<=M-2 ; i++){
        for(int j=i+1 ; j<=M-1 ; j++){
            for(int k=j+1 ; k<=M ; k++){
                a1.clear();
                a2.clear();
                a3.clear();
                for(int p=0 ; p< Ene.size() ; p++){
                    if(pow(Ene[p].first-i,2) + pow(Ene[p].second-(N+1),2)<D){
                        a1.push_back(make_pair(Ene[p].first,Ene[p].second));
                    }
                    if(pow(Ene[p].first-j,2) + pow(Ene[p].second-(N+1),2)<D){
                        a2.push_back(make_pair(Ene[p].first,Ene[p].second));
                    }
                    if(pow(Ene[p].first-k,2) + pow(Ene[p].second-(N+1),2)<D){
                        a3.push_back(make_pair(Ene[p].first,Ene[p].second));
                    }
                }
                sort(a1.begin(),a1.end());
                sort(a2.begin(),a2.end());
                sort(a3.begin(),a3.end());
            }
        }
    }
}

int main(){
    cin >> N >> M >> D;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=M ; j++){
            cin >> Map[j][i];
            if(Map[j][i]==1){
                Ene.push_back(make_pair(j,i));
            }
        }
    }
    temp();
    cout << ans;
    return 0;
}