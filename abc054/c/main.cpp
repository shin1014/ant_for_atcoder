#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<bool>> table(8, vector<bool>(8, false));

int DFS(int x, vector<bool> visited);

int main(){
    cin >> N >> M;
    int a, b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        table[a-1][b-1] = true;
        table[b-1][a-1] = true;
    }

    vector<bool> visited(8, false);
    visited[0] = true;
    cout << DFS(0, visited) << endl;

    return 0;
}

int DFS(int x, vector<bool> visited){
    int count=0;
    int all_visited = true;
    for(int i=0;i<N;i++){
        if(visited[i] == false){
            all_visited = false;
            break;
        }
    }

    if(all_visited == true) return 1;

    for(int i=0;i<N;i++){
        if(table[x][i] == false) continue; //node isn't connected
        if(visited[i] == true) continue; //node was visited

        visited[i] = true;
        count += DFS(i, visited);
        visited[i] = false;
    }

    return count;
}
