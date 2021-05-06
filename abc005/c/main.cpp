#include <bits/stdc++.h>
using namespace std;
//すでにできているたこ焼きを売る
int T, N, M;


int main(){
    cin >> T;
    cin >> N;
    vector<int> ty(N);
    for(int i=0;i<N;i++){
        cin >> ty[i];
    }
    cin >> M;
    vector<int> cu(M);
    for(int j=0;j<M;j++){
        cin >> cu[j];
    }
    
    if(N<M){
        cout << "no" << endl;
        return 0;
    }

    int a = 0, b = 0;
    bool flag;
    
    for(b=0;b<M;b++){
        flag = false;
        for(a=0;a<N;a++){
            if(ty[a] >= cu[b] - T && ty[a] <= cu[b]){
                flag = true;
                ty[a] = -1;
                return 0;
            }
        }
        if(flag == false){
            break;
        }

    }

    if(flag){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}
