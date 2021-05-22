//20:49
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int a, b;
int main(){
    cin >> a >> b;
    if(a%2==0){
        cout << "Even" << endl;
        return 0;
    }
    if(b%2==0){
        cout << "Even" << endl;
        return 0;
    }

    cout << "Odd" << endl;
    return 0;
}
