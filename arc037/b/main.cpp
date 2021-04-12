#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int s;
    int g;
};

int N, M, Count=0;
struct Pair *pairlist;
bool Flags[200];
void dfs(int x);

int main(){
    cin >> N >> M;
    pairlist = new struct Pair[M];
    for(int i=0;i<M;i++){
        cin >> pairlist[i].s;
        cin >> pairlist[i].g;
    }
    for(int j=1;j<=N;j++){
        Flags[j] = false;
    }
    for(int k=1;k<=N;k++){
        if(Flags[k]==false){
            Count++;
            dfs(k);
        }
    }
    cout << Count << endl;
}

void dfs(int x){
    if(Flags[x]==true){
        Count--;
        return;
    }else{
        Flags[x] = true;
    }
    for(int i=0;i<M;i++){
        if(x==pairlist[i].s){
            dfs(pairlist[i].g);
        }
    }
}