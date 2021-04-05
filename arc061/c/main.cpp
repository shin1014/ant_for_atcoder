#include <bits/stdc++.h>
using namespace std;
string S;
long int N, SUM=0;
string TEMP = "";


int main(){
    cin >> S;
    N = S.length();

    for(int bit=0;bit < (1<<N-1);++bit){
        ///cout << bitset<10>(bit) << endl;;
        for(int j=0;j<N;j++){
            TEMP = S[(N-1)-j] + TEMP;
            if(bit & (1<<j)){
                SUM += stol(TEMP);
                TEMP = "";
            }
        }
        SUM += stol(TEMP);
        TEMP = "";
    }
    cout << SUM << endl;
}
