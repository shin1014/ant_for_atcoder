#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long long N,Q;

int main(){
    cin >> N >> Q;
    vector<long long> A(N);
    vector<long long> K(Q);
    vector<long long> SUM(N,0);
    rep(i,N) cin >> A[i];
    rep(j,Q) cin >> K[j];
    long long temp=1;
    rep(x,N){
        SUM[x] = A[x] - (x + 1);
    }
    /// itrは，要求個の有効数字を用意できる最小のインデックス
    /// SUM[itr]はその時の有効数字数であるから，
    //cout << endl;
    rep(i,Q){
        auto itr = lower_bound(SUM.begin(),SUM.end(),K[i]) - SUM.begin();
        //cout << itr << endl;
        if(itr==N){
            cout << A[itr-1] + (K[i] - SUM[itr-1]) << endl;
        }else{
            //cout << itr << endl;
            cout << (A[itr]) - (SUM[itr] - K[i] + 1) << endl;
        }
        
    }

}
