#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N,D;
int main(){
    cin >> N >> D;
    vector<vector<int>> array(N, vector<int>(D));
    rep(i,N){
        rep(j,D){
            cin >> array[i][j];
        }
    }
    double dist;
    int count=0;
    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            dist=0;
            rep(k,D){
                dist += pow(array[i][k]-array[j][k],2);
            }
            dist = sqrt(dist);
            if(floor(dist)==dist) count++;
        }
    }

    cout << count/2 << endl;


    

}
