#include <bits/stdc++.h>
using namespace std;

long long N, W;

int main(){
    cin >> N >> W;
    vector<long long> weight(N+1);
    vector<long long> value(N+1);
    vector<vector<long long> > dp(N+1, vector<long long>(W+1));
    for(long long i=0;i<N;i++){
        cin >> value[i] >> weight[i];
    }

    for(long long w=0;w<=W;w++){
        dp[0][w] = 0;
    }

    for(long long i=0;i<N;i++){   //取るか取らないかをひとつずつ試している
        for(long long w=0;w<=W;w++){  //最大重量を徐々に増やして試していく（ここがミソ！）
            dp[i+1][w] = dp[i][w];
            
            if(w>=weight[i]){   //取れるなら
                dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);  //とって得するなら取る、しないなら取らない（これによって）
            }else{  //取れないので取らない
                dp[i+1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;

}

/*
19行目から始まるループが重要な部分である
iを0から増やしていくことで、その時点における最適解を求めている。
これだけ聞くと、「後から見た時とったのが損だったパターン」を選択してしまいそうである。
しかし、DPのテーブルには取らなかった場合も記録されるためその心配はない。
i番目の荷物を取得することができ、かつ有益である場合はdp[i+1][w]に取得した場合の値が入る。
ここで、取得しなかった場合の値はi-1番目の時点における最大値であるはずである。
すなわち、i番目に取得しなかった場合も記録されており、またこれが参照されるのが22行目のmax()の部分である。

そもそも、i行目には0からwまでのマスがあり、20行目のように0からwまで埋められるのだから、
i回目の選択時点でとりうる値全てが記録されているはずである。
すなわち、本質的にはメモ化再帰による全探索に近い処理が行われていると言える。
*/
