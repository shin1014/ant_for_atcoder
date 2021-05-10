#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> array(3);
    cin >> array[0] >> array[1] >> array[2];
    sort(array.begin(), array.end());

    int sum=0;
    for(int i=2;i>0;i--){
        sum += array[i] - array[i-1];
    }

    cout << sum << endl;
}
