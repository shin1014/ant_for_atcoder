#include <bits/stdc++.h>
using namespace std;

int32_t MAX=0;

struct Data{
    int32_t  beauty, delicious, popularity;
    /*
    void set_abs(){
        if(beauty<0){
            beauty = beauty*-1;
        }
        if(popularity<0){
            popularity = popularity*-1;
        }
        if(delicious<0){
            delicious = delicious*-1;
        }
        
    }
    */
};

int32_t abs(int32_t x){
    if(x<0){
        x = x*-1;
    }
    return x;
}

int kaijo(int x){
    int m;
    if(x==0){
        return 1;
    }else{
        return x*kaijo(x-1);
    }
}

void sum(Data *array, int M, int nums[]){
    int32_t b=0, d=0, p=0;
    int i;
    for(i=0;i<M;i++){
        b += array[nums[i]].beauty;
        d += array[nums[i]].delicious;
        p += array[nums[i]].popularity;
    }
    b = abs(b);
    d = abs(d);
    p = abs(p);

    if(MAX<b+d+p){
        MAX=b+d+p;
    }
}



int main(){
    int N, M;
    cin >> N >> M;
    Data *array;
    array = new Data[N];

    int i;
    for(i=0;i<N;i++){
        cin >> array[i].beauty >> array[i].delicious >> array[i].popularity;
    }






    ///printf("%d,%d,%d\n", array[0].beauty, array[0].delicious, array[0].popularity);
}

/*
全探索したいが、Mの値によってループのレイヤー数が変動するため多重ループではうまくいかない。
よって樹形図のイメージから再帰関数とするのが解法の一つ？
分岐するから再帰は不適切？

指定した番号のデータの和を計算するsum()を用意

M個の重複しない数の組み合わせ＝M!通り
二次元配列を用意
table[y][0]をまず定める。　y=M!である。　（組み合わせの総数）
table[y][x]のうち、xはyの値より大きいNまでの数全てである。

これはできそうだがtableの生成が大変で無駄が多いので筋が悪い解法と言える




*/