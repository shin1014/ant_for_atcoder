#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
//12:37
int N;

int main(){
    cin >> N;
    if(N%2!=0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> d(N);
    rep(i,N) cin >> d[i]; 
    sort(d.begin(), d.end());

    int center = N/2;
    if(d[center]==d[center-1]){
        cout << 0 << endl;
        return 0;
    }else{
        cout << d[center]-d[center-1] << endl;
    }
    
    return 0;

}
