#include <bits/stdc++.h>
using namespace std;

long long X, Y, TEMP, COUNT=0;

int main(){
    cin >> X >> Y;

    TEMP = X;
    COUNT++;
    while(TEMP<Y){
        TEMP = TEMP * 2;
        if(TEMP>Y){
            break;
        }else{
            COUNT++;
        }
    }

    cout << COUNT << endl;

}
