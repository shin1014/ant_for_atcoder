#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

/*
N桁の二進数でbit全探索。
全ての証言と一致する組み合わせを探し、するならそのうちで1である桁数を数えて保存。
*/

int N;
int main(){
    cin >> N;
    vector<vector<pair<int, int>>> s(N);
    rep(i,N){
        int a; cin >> a;
        rep(j,a){
            int f,b;
            cin >> f >> b;
            s[i].push_back(make_pair(f-1,b));
        }
    }
    int ans=-1;
    for(int bit=0;bit<(1<<N);bit++){
        bool ok = true;
        for(int i=0;i<N;i++){
            if(!(bit & (1<<i))) continue;
            for(auto v:s[i]){
                if(v.second==1){
                    if(!(bit & (1<<v.first))) ok=false;
                }
                else if(v.second==0){
                    if((bit & (1<<v.first))) ok=false;
                }
            }
        }
        if(ok){
            int count=0;
            for(int x=0;x<N;x++){
                if(bit & (1<<x)){
                    count++;
                }
            }
            chmax(ans,count);
        }
    }

    cout << ans << endl;
}
