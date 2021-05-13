#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60;

long long N, M;

int main(){
    cin >> N >> M;
    vector<long long> dp(N+3, 0);
    vector<bool> trap(N+3, true);
    int temp;
    rep(i, M){
        cin >> temp;
        trap[temp] = false;
    }
    dp[0] = 1;

    for(int i=0;i<N;i++){
        if(trap[i]){
            if(trap[i+1]) dp[i+1] += dp[i];
            if(trap[i+2]) dp[i+2] += dp[i];
        }
        dp[i+1] %= 1000000007;
    }
    cout << dp[N] << endl;
}
