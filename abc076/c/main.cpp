#include <bits/stdc++.h>
using namespace std;

string S, Sd, T;
int reload(int head);


int main(){
    cin >> Sd;
    cin >> T;

    if(Sd.length() < T.length()){
        cout << "UNRESTOREBLE" << endl;
        return -1;
    }

    for(int i=0;i<Sd.length();i++){
        for(int j=0;j<T.length();j++){
            if(Sd[i] == T[j] && i>=j){
                reload(i);
                break;
            }
        }
    }

    cout << Sd << endl;

}

int reload(int head){
    for(int i=head;i<T.length();i++){
        Sd[i] == T[i-head];
    }

    return 0;
}
