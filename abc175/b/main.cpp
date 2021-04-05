#include <bits/stdc++.h>
using namespace std;

int N, COUNT=0;
int x,y,z;

int main(){
    cin >> N;
    vector<int> array(N);
    for(int i=0;i<N;i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    
    for(x=0;x<N;x++){
        for(y=x+1;y<N;y++){
            for(z=y+1;z<N;z++){
                if(array[z]<array[x]+array[y] && array[x]!=array[y] && array[y]!=array[z]){
                    ///cout << x << y << z << endl;
                    COUNT++;
                }
            }
        }
    }

    cout << COUNT << endl;



    
}
