#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int A,B,C,X;

int main(){
    cin >> A >> B >> C >> X;
    int count=0;
    rep(i,A+1){
        rep(j,B+1){
            rep(k,C+1){
                if(500*i+100*j+50*k==X) count++;
            }
        }
    }

    cout << count << endl;
}
