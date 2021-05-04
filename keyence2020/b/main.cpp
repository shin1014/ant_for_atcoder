#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    long long x, len;
    vector<pair<long long, long long>> ROBOTS(N);
    for(int i=0;i<N;i++){
        cin >> x;
        cin >> len;
        ROBOTS[i].second = x - len;
        ROBOTS[i].first = x + len;
    }

    sort(ROBOTS.begin(), ROBOTS.end());

    long long point=0, count=0;
    for(int j=0;j<N;j++){
        if(point<=ROBOTS[j].second || point==0){
            count++;
            point = ROBOTS[j].first;
        }
    }

    cout << count << endl;


}
