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
        int temp=i, num=1;
        while(temp>=10){
            temp/=10;
            num++;
        }
        if(num%2==1) count++;
    }    

    cout << count << endl;
}
