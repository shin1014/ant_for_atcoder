#include <bits/stdc++.h>
using namespace std;
int K, S;
int x, y, z, COUNT=0, temp;

int main(){
    cin >> K >> S;
    /*
    for(x=0;x<=K;x++){
        for(y=0;y<=K;y++){
            for(z=0;z<=K;z++){
                temp = x+y+z;
                if(temp==S) COUNT++;
                else if(temp>S) break;
            }
        }
    }
    */

   for(x=0;x<=K;x++){
       for(y=0;y<=K;y++){
           temp = S-x-y;
           if(temp>=0 && temp<=K){
               COUNT++;
           }

       }
   }

    cout << COUNT << endl;
}
