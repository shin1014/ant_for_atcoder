#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){

    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    int alice=0, bob=0;
    rep(i,N){
        if(i%2==0){
            alice+=a[i];
        }else{
            bob+=a[i];
        }
    }
    cout << alice-bob << endl;
    
}
