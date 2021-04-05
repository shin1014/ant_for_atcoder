#include <bits/stdc++.h>
using namespace std;

struct _point{
    double x;
    double y;
};
int N;
struct _point *Array;
double MAX=0;

double distance(struct _point a, struct _point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


int main(){
    cin >> N;
    Array = new struct _point[N];
    for(int i=0;i<N;i++){
        cin >> Array[i].x;
        cin >> Array[i].y;
    }

    for(int p=0;p<N;p++){
        for(int q=0;q<N;q++){
            if(MAX<distance(Array[p], Array[q])){
                MAX = distance(Array[p], Array[q]);
            }
        }
    }

    cout << fixed << setprecision(6);
    cout << MAX << endl;
}
