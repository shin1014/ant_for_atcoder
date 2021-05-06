#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> w(N), stack(N);
    for(int i=0;i<N;i++){
        cin >> w[i];
    }

    ///sort(w.begin(), w.end());

    int point=0;
    stack[point] = w[0];
    for(int j=1; j<N;j++){
        bool flag=false;
        for(int k=0;k<=point;k++){ // search other stack
            if(stack[k]>=w[j]){
                stack[k] = w[j];
                flag = true;
                break;
            }
        }
        if(flag==false){
            point++;
            stack[point] = w[j];
        }
    }

    cout << point+1 << endl;
}
