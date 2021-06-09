#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
//12:50

int N;

int main(){
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long sum=0;
    /*
    for(int i=0;i<N;i++){
        auto b = lower_bound(B.begin(),B.end(), A[i]+1) - B.begin();
        auto bb = upper_bound(B.begin(),B.end(), A[i]) - B.begin();
        auto c = lower_bound(C.begin(),C.end(), B[b]+1) - C.begin();
        sum += (N-c);
        // for(int j=b;j<N;j++){
        //     auto c = lower_bound(C.begin(),C.end(), B[j]+1) - C.begin();
        //     sum += N-c;
        // }
    }
    */

   rep(i,N){
       auto a = lower_bound(A.begin(),A.end(), B[i]) - A.begin();
       auto c = upper_bound(C.begin(),C.end(), B[i]) - C.begin();
       sum += a*(N-c);
   }

    cout << sum << endl;
}
