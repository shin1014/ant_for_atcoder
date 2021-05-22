#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

long long N;

int main(){
    cin >> N;
    vector<long long> array(N);
    rep(i,N) cin >> array[i];

    int flag = true;
    long long count=0;
    
    while(flag){
        rep(i,N){
            if(array[i]%2==1){
                flag = false;
                break;
            }else{
                array[i] = array[i]/2;
            }
        }
        if(flag==false) break;
        count++;
    }
    
    cout << count << endl;
    return 0;
}
