#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N,A,B;

int main(){
    cin >> N >> A >> B;
    int len;
    int sum=0;
    int count=0;
    string s;
    rep(num,N+1){
        sum=0;
        s = to_string(num);
        rep(i,s.length()){
            sum += s[i]-'0';
        }
        if(sum>=A && sum<=B) count+=num;
    }

    cout << count << endl;
    
}
