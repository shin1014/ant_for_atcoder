#include <bits/stdc++.h>
using namespace std;

/*
1. ボーナスがなければ、単純に配点の大きい問題から完答すれば良い
2. ボーナスの存在により、大きい順ではなくなる
3. つまり、中途半端に解くことはボーナスが得られないため考える必要なし
4. したがって、ボーナスの取り方を基準に全探索し、不足分は未解答の問題の中で最大配点のものを解いていけばいい(中途半端に解く問題が2つ以上になることはない)
*/

int main(){
    int D, G, POINT, MIN=99999, STEP;
    cin >> D >> G;
    vector<int> P(D+1), C(D+1), F(D+1);
    P[0] = -1;
    C[0] = -1;
    F[0] = -1;
    for(int i=1;i<=D;i++){
        cin >> P[i];
        cin >> C[i];
        F[i] = 1;
    }

    for(int bit=0;bit<(1<<D);++bit){
        POINT=0;
        STEP=0;
        ///cout << bitset<10>(bit) << endl;
        for(int j=0;j<D;j++){
            if(bit & (1<<j)){
                POINT += C[D-j];
                POINT += 100*(D-j)*P[D-j];
                STEP += P[D-j];
                F[D-j] = 0;
            }
        }
        if(POINT<G){
            for(int x=D;x>0;x--){
                if(F[x]!=0){
                    int temp=0;
                    while(G-POINT-temp*(x*100)>0 && temp<=P[x]){
                        temp++;
                    }
                    STEP += temp;
                    POINT += temp*(x*100);
                    ///cout << "temp: " << temp << endl;
                }
            }
        }
        if(POINT>=G){
            MIN = min(MIN, STEP);
        }
    }
    cout << MIN << endl;
}
