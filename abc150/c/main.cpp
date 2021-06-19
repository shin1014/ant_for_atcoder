#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    int A[N],P[N],Q[N];
    rep(i,N){
        A[i] = i+1;
        cin >> P[i];
    }
    rep(i,N) cin >> Q[i];
    int a,b,count=0;
    do{
        count++;
        bool eq_P=true, eq_Q=true;
        rep(i,N){
            if(eq_P && P[i]!=A[i]) eq_P = false;
            if(eq_Q && Q[i]!=A[i]) eq_Q = false;
        }
        if(eq_P) a=count;
        if(eq_Q) b=count;
    }while(next_permutation(A,A+N)); 

    cout << abs(a-b) << endl;

}
