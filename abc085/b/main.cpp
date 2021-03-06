#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    vector<int> d(N);
    rep(i,N) cin >> d[i];

    sort(d.begin(),d.end(), greater<int>());

    int  m=100*100, count=0;;
    rep(i,N){
        if(chmin(m,d[i])) count++;
    }

    cout << count << endl;

}
