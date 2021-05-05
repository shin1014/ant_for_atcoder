#include <bits/stdc++.h>
using namespace std;

int N, M;

int cheak(vector<bool> bridges,int head, int tail);

int main(){
    cin >> N >> M;
    vector<pair<int, int>> demands(M);
    vector<bool> bridges(N-1, true);
    for(int i=0;i<M;i++){
        cin >> demands[i].second;
        cin >> demands[i].first;

        demands[i].first--;
        demands[i].second--;
    }

    sort(demands.begin(), demands.end());

    int count=0;
    for(int i=0;i<M;i++){
        if(cheak(bridges, demands[i].second, demands[i].first)) continue;
        else{
            bridges[demands[i].first - 1] = false;
            count++;
        }
    }

    cout << count << endl;



}

int cheak(vector<bool> bridges,int head, int tail){
    for(int i=head;i<tail;i++){
        if(bridges[i] == false) return 1;
    }
    return 0;
}
