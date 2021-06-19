#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N,M,X;
int main(){
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    rep(i,N){
        cin >> C[i];
        rep(j,M){
            cin >> A[i][j];
        }
    }

    int min=100000*12+1;
    for(int bit=0;bit<(1 << N);++bit){
        vector<int> P(M,0);
        int sum=0;
        for(int x=0;x<N;x++){
            if(bit & (1<<x)){
                sum += C[x];
                for(int y=0;y<M;y++){
                    P[y] += A[x][y];
                }
            }
        }
        int s;
        bool flag=true;
        for(s=0;s<M;s++){
            if(P[s]<X) flag=false;
        }
        if(flag){
            chmin(min,sum);
        }
    }

    if(min==100000*12+1) cout << -1 << endl;
    else cout << min << endl;

}
