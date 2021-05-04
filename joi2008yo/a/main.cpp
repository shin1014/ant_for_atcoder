#include <bits/stdc++.h>
using namespace std;

int MONEY = 1000;
vector<int> COINS = {500, 100, 50, 10, 5, 1};

int main(){
    int value, count = 0;
    cin >> value;
    MONEY -= value;

    while(MONEY!=0){
        for(int i=0;i<COINS.size();i++){
            if(MONEY - COINS[i] >= 0){
                MONEY -= COINS[i];
                count++;
                i--;
            }
        }
    }

    cout << count << endl;
}
