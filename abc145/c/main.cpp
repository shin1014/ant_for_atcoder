#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
//20:29
int N;
int main(){
    cin >> N;
    int P[N];
    rep(i,N){
        if(i==0) P[i] = 0;
        else P[i] = P[i-1] + 1; 
    }

    vector<pair<int,int>> point(N);
    rep(i,N){
        cin >> point[i].first >> point[i].second;
    }
    double x,y,sum=0;
    double count=0;
    do{
        for(int i=1;i<N;i++){
            x = point[P[i]].first - point[P[i-1]].first;
            y = point[P[i]].second - point[P[i-1]].second;
            sum += sqrt(pow(x,2)+pow(y,2));
        }
        count++;
    }while(next_permutation(P,P+N));
    cout << setprecision(10) <<sum/count << endl;
}
