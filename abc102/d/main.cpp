#include <bits/stdc++.h>
using namespace std;


int search(int *array, int head, int tail, int x){
    int min = 99999999, index;
    for(int i=head;i<tail;i++){
        if(min>abs(x-array[i])){
            min = x-array[i];
            index = i;
        }        
    }
    return index;
}

int main(){
    int N, ANS;
    cin >> N;

    int32_t *array, *counter;
    array = new int[N];
    counter = new int[N];

    ///vector<int> array(N), counter(N);
    counter[0] = 0;
    for(int i=0;i<N;i++){
        cin >> array[i];
    }

    counter[0] = array[0];
    for(int j=0;j<N;j++){
        counter[j] = counter[j-1] + array[j];
    }
    
    int sum = counter[N-1];
    int pl,pc,pr;
    
    pc = search(counter, 0, N, sum/2);
    pl = search(counter, 0, pc, sum/4);
    pr = search(counter, sum/2, N, (sum/4)*3);

    cout << sum << endl;
    cout << pc << endl;
    cout << pl << endl;
    cout << pr << endl;
}
