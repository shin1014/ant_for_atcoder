#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long long N;

int main(){
    cin >> N;
    vector<vector<long long>> p(N+1, vector<long long>(3, 0));
    rep(i, N){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }

    vector<vector<long long>> dp(N+1, vector<long long>(3,0));
    // dp[i+1][j]:=i日目までに得た最大値にjを選択して得た点数
    dp[0][0] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k==j) continue;
                else chmax(dp[i+1][j], dp[i][k] + p[i][j]);
            }
        }
        
    }

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

}



/*

条件付きgreedy的なものを書いているが、これでは「結果として選ばない方が良かった最大値」を選んでしまうため不適。
前の日の情報を残して追加していくと言う発想は良かったので、それをDPに組み込んだ二次元DPで解くことを身につければ良い。

int main(){
    cin >> N;
    vector<vector<long long>> p(N+1, vector<long long>(3, 0));

    rep(i, N){
        cin >> p[i+1][0] >> p[i+1][1] >> p[i+1][2];
    }

    vector<long long> dp(N+1);
    long long max=0, max_index;
    for(long long x=0;x<3;x++){
        if(max<p[1][x]){
            max = p[1][x];
            max_index = x;
        }
    }
    dp[1] = max;

    long long pre=max_index;
    for(long long i=2;i<=N;i++){
         p[i][pre] = 0;
         max=0;
         for(long long x=0;x<3;x++){
            if(max<p[i][x]){
                max = p[i][x];
                max_index = x;
        }
        chmax(dp[i],dp[i-1] + max);
        pre = max_index;
    }
    }

    cout << dp[N] << endl;


}
*/
