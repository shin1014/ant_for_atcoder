#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    int count=0;
    for(int i=1;i<=N;i++){
        int temp=0;
        for(int j=1;j<=i;j++){
            if(i%j==0 && i%2==1) temp++;
        }
        if(temp==8) count++;
        temp=0;
    }
    cout << count << endl;
}
