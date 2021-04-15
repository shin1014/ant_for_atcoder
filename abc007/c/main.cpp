#include <bits/stdc++.h>
using namespace std;

int R, C;
int sx, sy, gx, gy;
vector<vector<char>> table;
queue<int> x_que;
queue<int> y_que;
vector<vector<int>> dist;
void Push(int x, int y);
void Pop();
int cheak(int x, int y);

int main(){
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    table.resize(R);
    dist.resize(R);
    for(int i=0;i<R;i++){
        table[i].resize(C);
        dist[i].resize(C);
    }
    for(int y=0;y<R;y++){
        for(int x=0;x<C;x++){
            cin >> table[y][x];
            dist[y][x] = -1;
        }
    }

    sx--;
    sy--;
    gx--;
    gy--;

    dist[sy][sx] = 0;
    Push(sx, sy);
    
    int x, y;
    while(!x_que.empty()){
        x = x_que.front();
        y = y_que.front();
        Pop();

        if(x+1<C){
            if(cheak(x+1, y)){
                dist[y][x+1] = dist[y][x] + 1;
                Push(x+1, y);
            }
        }
        if(x-1>=0){
            if(cheak(x-1, y)){
                dist[y][x-1] = dist[y][x] + 1;
                Push(x-1, y);
            }
        }
        if(y+1<R){
            if(cheak(x, y+1)){
                dist[y+1][x] = dist[y][x] + 1;
                Push(x, y+1);
            }
        }
        if(y-1>=0){
            if(cheak(x, y-1)){
                dist[y-1][x] = dist[y][x] + 1;
                Push(x, y-1);
            }
        }
    }

    cout << dist[gy][gx] << endl;

    


}

int cheak(int x, int y){
    if(table[y][x]=='.' && dist[y][x]==-1) return true;
    else return false;
}

void Push(int x, int y){
    x_que.push(x);
    y_que.push(y);
}

void Pop(){
    x_que.pop();
    y_que.pop();
}