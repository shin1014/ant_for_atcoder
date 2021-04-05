#include <bits/stdc++.h>
using namespace std;

int abs(int x){
    if(x<0){
        x=x*-1;
    }
    return x;
}

int calc(vector<int> array, int b, int N){
    int sum=0;
    for(int j=0;j<N;j++){
        sum += abs(array[j]- (b+(j+1)));
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    vector<int> array_a(N), array_b(N);
    for(int i=0;i<N;i++){
        cin >> array_a[i];
    }
    array_b = array_a;

    for(int j=0;j<N;j++){
        array_b[j] -= (j+1);
    }
    
    int b1, b2, sum1, sum2, sum3, ans;
    if(N%2==1){
        b1 = array_b[N/2];
        cout << calc(array_a, b1, N) << endl;
    }else{
        b1 = array_b[N/2];
        cout << calc(array_a, b1, N) << endl;
        /*
        b2 = array_b[N/2+1];
        cout << min(calc(array_a, b1, N), calc(array_a, b2, N)) << endl;
        */
    }
    
}
