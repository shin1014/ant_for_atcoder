#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long long N, W;

int main(){
   cin >> N >> W;
   vector<long long> w(N);
   vector<long long> v(N);
   rep(i, N)  cin >> w[i] >> v[i];

   vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
   //dp[i][j]:=容量jのナップサックにi番目まで荷物を選んだ時について、その時の最大価値を格納

    for(long long sum_w=0;sum_w<=W;sum_w++){   //重さを緩和
        for(int i=0;i<N;i++){   //カエルと同じ　現在のsum_wに飛んでこられるなら飛ぶイメージ
            if(sum_w-w[i]>=0){
                chmax(dp[i+1][sum_w], dp[i][sum_w-w[i]]+v[i]);
            }
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }

    cout << dp[N][W] << endl;
}
