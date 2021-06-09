#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long double N,K;

int main(){
    cin >> N >> K;
    vector<long double> p(N+1, 0);
    for(int i=1;i<=N;i++){  //iは1回目のサイコロの目
        long double count = 0, temp=i;
        while(temp<K){
            temp = temp*2;
            count++;
        }
        p[i] = (1/N) * pow(0.5, count);
    }

    long double ans=0;
    rep(i,N+1){
        ans += p[i];
    }
    
    cout << setprecision(15) << ans << endl;
}
