#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N;

int main(){
    cin >> N;
    int ans, max=-1;
    for(int i=1;i<=N;i++){
        int temp=i, count=0;
        while(temp%2==0){
            temp /= 2;
            count++;
        }
        if(max<count){
            max = count;
            ans = i;
        }
    }

    cout << ans << endl;
}
