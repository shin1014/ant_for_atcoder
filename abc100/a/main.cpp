#include <bits/stdc++.h>
using namespace std;

int cheak(int a, int b, int c);

int main(){
    int a, b; //get input
    cin >> a >> b;
    
    if(cheak(a,b,0)==1 || cheak(a,b,1)==1){
        cout << "Yay!" <<endl;
    }else{
        cout << ":(" << endl;
    }
}

int cheak(int a, int b, int c){
    int array[16]={0};
    int count[3]={0}; // a,b,free
    int i, j;

    if(a>8 || b>8){
        return 0;
    }

    for(i=0;i<a;i++){
        if(i*2+c<16){
            array[i*2+c] = 1;
        }
        if(i*2+1-c<16){
            array[i*2+1-c] = -1;
        }
    }

    for(j=0;j<16;j++){
        if(array[j]==1){
            count[0]++;
        }else if(array[j]==-1){
            count[1]++;
        }else if(array[j]==0){
            count[2]++;
        }
    }

    if((count[0]>=a && count[1]+count[2]>=b) || (count[0]>=b && count[1]+count[2]>=a))
    {
        return 1;
    }else{
        return 0;
    }
}