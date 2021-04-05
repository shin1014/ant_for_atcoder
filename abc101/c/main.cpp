#include <bits/stdc++.h>
using namespace std;

int COUNT;
int N,K;

void p_array(int *array){
    for(int x=0;x<N;x++){
        cout << array[x];
        cout << " ";
    }
    cout << endl;
}

void override(int *array, int K, int head, int min){
    for(int i = head;i<head+K;i++){
        array[i] = min;
    }
    COUNT++;
    ///p_array(array);
}



int main(){
    cin >> N >> K;
    int *array, min, mindex;
    array = new int[N];
    cin >> array[0];
    min = array[0];
    for(int i=1;i<N;i++){
        cin >> array[i];
        if(min>array[i]){
            min = array[i];
            mindex = i;
        }
    }

    if(mindex+K>N-1){   //overflow
        ///cout << "over" << endl;
        override(array, K, N-K, min);
        for(int j=0;j<N-K;j=j+K){
            override(array, K, j, min);
        }
    }else if(mindex-K<0){   //underflow
        ///cout << "under" << endl;;
        override(array, K, 0, min);
        for(int j=mindex;j<N;j=j+K-1){
            override(array, K, j, min);
        }
    }else{  //inside
        ///cout << "inside" << endl;
        while(true){
            for(int x=0;x<N;x++){
                if(x+K-1<N && array[x]==min && array[x+K-1]!=min){ //右に塗れる
                    for(int y=x;y<=x+K-1;y++){
                        array[y] = min;
                    }
                }
            }
            for(int s=N-1;s>0;s--){
                if(s-K+1>0 && array[s]==min && array[s-K+1]!=min){ //左に塗れる
                    for(int t=s;t<=s-K+1;t--){
                        array[s] = min;
                    }
                }
            }
            int z;
            for(z=0;z<N;z++){
                if(array[z]!=min){
                    continue;
                }
            }
            if(z==N){
                break;
            }
        }
        /*

        int j=mindex;
        while(j<N){ ///plus direction override
            override(array, K, j-1, min);
            j += K;
        }
        j = mindex;
        while(j>0){ ///plus direction override
            override(array, K, j, min);
            j -= K;
        }
        */
    }
    
    cout << COUNT << endl;

}

/*
選んだ要素の中の最小値で上書き
つまり、最終的には全体の最小値に塗りつぶされる

1. 最小値を探索　そのインデックスを保持
2. index+K < N  index-K > 0 を確認する
3. arrayの外になるならそれを優先して端まで塗りつぶし、反対まで降っていく
4. arrayの内側ならまず+の方向へ塗りつぶし　端を超えたらN-Kをインデックスとして塗りつぶし
5. その次-の方向へ塗りつぶし、0を下回ったらK-1をインデックスとして塗りつぶし
6. 塗りつぶしの旅にcountを増加させてcoutに出力


*/
