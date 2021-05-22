#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N, K;

int main(){
    cin >> N >> K;
    vector<long long> h(N);
    vector<long long> dp(N+K, INF);
    rep(i, N) cin >> h[i];
    dp[0] = 0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=K;j++){
            chmin(dp[i+j], dp[i] + abs(h[i+j]-h[i]));
        }
    }
    cout << dp[N-1] << endl;
}
