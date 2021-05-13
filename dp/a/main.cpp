#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
vector<long long> dp(100005, INF);

int N;
int main(){
    cin >> N;
    vector<long long> hight(N);
    for(int i=0;i<N;i++){
        cin >> hight[i];
    }
    
    dp[0] = 0;
    for(int i=1;i<N;i++){
        chmin(dp[i], dp[i-1] + abs(hight[i]-hight[i-1]));
        if(i>1) chmin(dp[i], dp[i-2] + abs(hight[i] - hight[i-2]));
    }

    cout << dp[N-1] << endl; 

}
