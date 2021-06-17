#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
long long __my_pow3(long long _x, long long _r, long long _n);
long long my_pow3(long long _x, long long _n);

long myPow(long x, long n, long m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

long long A,B,C;

int main(){
    cin >> A >> B >> C;

    if(C%2==1){ //Cが奇数の時，元の符号が保存
        if(A<B) cout << "<" << endl;
        else if(A>B) cout << ">" << endl;
        else cout << "=" << endl;
    }else{  //Cが偶数の時，絶対値で勝負
        if(abs(A) < abs(B)) cout << "<" << endl;
        else if(abs(A) > abs(B)) cout << ">" << endl;
        else cout << "=" << endl;
    }
}
