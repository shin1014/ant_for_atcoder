#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;
int main(){
    cin >> N;
    vector<int> array(N);
    rep(i,N){
        cin >> array[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<N;j++){
            if(i==array[j]){
                array[j] = 0;
                break;
            }
        }
    }

    bool ok=true;
    rep(x,N){
        if(array[x]!=0){
            ok=false;
            break;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
