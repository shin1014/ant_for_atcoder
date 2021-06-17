#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N,M;
int main(){
    cin >> N >> M;
    vector<vector<int>> sw(M);
    vector<int> p(M);
    rep(i,M){
        int k;
        cin >> k;
        rep(j,k){
            int temp;
            cin >> temp;
            temp--;
            sw[i].push_back(temp);
        }
    }
    rep(i,M) cin >> p[i];

    int ok=0;
    for(int bit=0;bit<(1<<N);++bit){
        bool flag=true;
        for(int x=0;x<M && flag;x++){
            int count=0; 
            for(auto v:sw[x]){
                if(bit & (1<<v)){
                    count++;
                }
            } 
            if(count%2!=p[x]) flag = false;
        }
        if(flag==true) ok++;
        
    }
    cout << ok << endl;
    return 0;
}
