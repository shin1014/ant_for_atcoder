#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int A=S[0], B=S[1], C=S[2], D=S[3], N=S.length(), SUM=0;
    string Answer="";
    for(int bit=0; bit<(1<<N); ++bit){
        ///cout << bitset<10>(bit) << endl;
        SUM = 0;
        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                if(Answer == ""){
                    Answer += S[i];
                    SUM += S[i] - '0';
                }else{
                    Answer += "+";
                    Answer += S[i];
                    SUM += S[i] - '0';
                }

            }else{
                if(Answer == ""){
                    Answer += S[i];
                    SUM += S[i] - '0';
                }else{
                    Answer += "-";
                    Answer += S[i];
                    SUM -= S[i] - '0';
                }
            }
        }
        if(SUM==7){
            cout << Answer << "=7" << endl;
            return 0;
        }else{
            SUM = 0;
            Answer = "";
            continue;
        }
    }


}
