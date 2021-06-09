#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

string S;
int front[2], back[2];
int f,b;

int main(){
    cin >> S;
    front[0] = S[0] - '0';
    front[1] = S[1] - '0';
    back[0] = S[2]- '0';
    back[1] = S[3] - '0';

    f = front[0]*10 + front[1];
    b = back[0]*10 + back[1];


    bool yymm=false, mmyy=false;
    
    if(1<=b && b<=12){   //YYMM
        yymm=true;
    }
    if(1<=f && f<=12){   //MMYY
        mmyy=true;
    }

    if(yymm&&mmyy)  cout << "AMBIGUOUS" << endl;
    else if(mmyy) cout << "MMYY" << endl;
    else if(yymm) cout << "YYMM" << endl;
    else  cout << "NA" << endl;
    
}
