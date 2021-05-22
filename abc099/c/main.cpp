#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    vector<long long> dp(N+1, INF);
    dp[0] = 0;
    for(int i=0;i<=N;i++){
        for(int j=1;i-pow(9,j)>=0;j++){
            chmin(dp[i], dp[i-pow(9,j)]+1);
        }
        for(int k=1;i-pow(6,k)>=0;k++){
            chmin(dp[i], dp[i-pow(6,k)]+1);
        }
        chmin(dp[i], dp[i-1]+1);
    }
    /*
    for(int i=0;i<N;i++){
        cout << dp[i] << " ";
    }
    */
  
    cout << dp[N] << endl;
}

//和をNにできるかどうか、またその回数の最小化と捉える？
//カエルの飛び方が今回の選択肢であると考えれば良い？