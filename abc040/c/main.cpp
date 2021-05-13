#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    vector<int> h(N);
    rep(i, N){
        cin >> h[i];
    }

    vector<int> dp(N, 1000000000);
    dp[0] = 0;
    for(int i=0;i<N;i++){
        chmin(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
        if(i>1) chmin(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
    }

    cout << dp[N-1] << endl;

}
