#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> points(N);
    for(int i=0;i<N;i++){
        cin >> points[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(N*100, 0));
    dp[0][0] = 1;

    for(int p=0;p<=N*100;p++){
        for(int i=0;i<N;i++){
            dp[i+1][p] |= dp[i][p];     //とりあえず、i番を選ばなければi+1番目もp点になる
            if(p>=points[i]){    //さらに、i番目の得点(points[i])がこの時点での最大点pを越えなければ、p-points[i] の部分にpoints[i]を加えることでi+1番時点でpに到達できる。
                dp[i+1][p] |= dp[i][p-points[i]];
            }
        }
    }

    int count=0;

    for(int x=0;x<N*100;x++){
        if(dp[N][x]) count++;
    }

    cout << count << endl;

}

/*
1<=N<=100 && 1<=p_i<=100 より、1<=points<=10000
これくらいなら配列として用意してもいいのでは？
-> サイズ10000の配列を用意して到達できたらtrue

vector<bool> array(10001, false);

for(int bit=0;bit < (1<<N);bit++){
    int SUM = 0;
    for(int i=0;i<N;i++){
        if(bit & (1 << i)){
            SUM += points[i];
        }
    }
    array[SUM] = true;
}

cout << count(array.begin(), array.end(), true) << endl;
*/
