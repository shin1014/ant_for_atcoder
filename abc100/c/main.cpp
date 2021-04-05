#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int *array;
    array = new int[N];
    int i;
    for(i=0;i<N;i++){
        cin >> array[i];
    }

    int ANS=0, t_count;

    while(true){
        t_count = 0;
        for(i=0;i<N;i++){
            if(array[i]%2==0 && t_count==0){ // can /2
                array[i] = array[i]/2;
                t_count++;
            }else{
                array[i] = array[i]*3;
            }
        }
        if(t_count==0){
            break;
        }
        ANS++;
    }

    cout << ANS <<endl;
    
}

/*

「*3 or /2」をできるだけ多く行う。　演算後の値も整数に収める必要があるため/2は有限回。
「*3」はいくらでもできそうだが、「全ての値を3倍することはできない」という制限がある。
言い換えれば「どこか一つは/2をする必要がある」

したがって
1. /2ができるか判定
2. できるなら割る
3. できないなら*3

1-3を繰り返し、 *3の回数==N となったら終了

さらに、最大化するなら2で割るのは1ループにつき一回だけにするのが良い！

*/