#include <bits/stdc++.h>
using namespace std;

int main(){
    int D, N;
    cin >> D >> N;

    int base=1;
    int answer;

    int i;
    for(i=0;i<D;i++){
        base = base*100;
    }

    answer = base*N;
    
    if(answer%(base*100)==0){
        answer = answer+base;
    }

    cout << answer << endl;

}