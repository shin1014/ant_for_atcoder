#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    vector<pair<int, int>> boxes(N);
    for(int i=0;i<N;i++){
        cin >> boxes[i].first;
        cin >> boxes[i].second;
    }

    sort(boxes.begin(), boxes.end());

    int max_h=0, max_w=0, count = 0;
    for(int i=0;i<N;i++){
        if(max_h<boxes[i].first &&  max_w < boxes[i].second){
            max_h = boxes[i].first;
            max_w = boxes[i].second;
            count++;
        }
    }

    cout << count << endl;

}
