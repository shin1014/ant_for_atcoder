#include <bits/stdc++.h>
using namespace std;

int N, Y;
int x, y, z, temp;

/*
    10000x+5000y+1000z = Y;
    10x+5y+z=Y/1000;
*/

int main(){
    cin >> N >> Y;
    for(x=N;x>=0;x--){
        if(10000*x>Y){
            continue;
        }
        for(y=N-x;y>=0;y--){
            temp = 10000*x+5000*y;
            if(temp>Y){
                continue;
            }else{
                if((Y-temp)%1000==0){
                    z = (Y-temp)/1000;
                    if(x+y+z==N){
                        cout << x << " " << y << " " << z << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;

    
    
}
