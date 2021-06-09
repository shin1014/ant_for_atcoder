#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long long N,K;
string S;

int main(){
    cin >> N >> K;
    cin >> S;
    if(S[K-1]=='A'){
        S[K-1] = 'a';
    }else if(S[K-1]=='B'){
        S[K-1] = 'b';
    }else{
        S[K-1] = 'c';
    }

    cout << S << endl;
}
