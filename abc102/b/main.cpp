#include <bits/stdc++.h>
using namespace std;

int32_t abs(int32_t x){
    if(x<0){
        x=x*-1;
    }
    return x;
}

int main(){
    int32_t N;
    cin >> N;
    int32_t *array;
    array = new int32_t[N];
    for(int i=0;i<N;i++){
        cin >> array[i];
    }

    int max=0;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(max<abs(array[x]-array[y])){
                max = abs(array[x]-array[y]);
            }
        }
    }

    cout << max << endl;

}
