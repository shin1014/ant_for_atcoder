#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> TIME(N);
    for(int i=0;i<N;i++){
        cin >> TIME[i];
    }

    int t1=0, t2=0, MIN=99999; 
    for(int bit=0;bit<(1<<N);++bit){
        ///cout << bitset<4>(bit) << endl;
        for(int j=0;j<N;j++){
            if(bit & (1<<j)){
                t1 += TIME[(N-1)-j];
            }else{
                t2 += TIME[(N-1)-j];
            }
        }
        MIN = min(MIN, max(t1,t2));
        t1=0;
        t2=0;
    }

    cout << MIN << endl;
}
