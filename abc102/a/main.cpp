#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(N%2==0){
        cout << N << endl;
    }else{
        cout << 2*N << endl;
    }
}
    

/*
2とNのどちらでも割り切れる最小の正の整数
→2とNの倍数で最小→2N

*/
