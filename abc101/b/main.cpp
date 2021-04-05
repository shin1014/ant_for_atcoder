#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string strN;
    cin >> N;
    strN = to_string(N);

    int sum=0;
    for(int i=0;i<strN.length();i++){
        sum += strN[i] - '0';
    }

    if(N%sum==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
