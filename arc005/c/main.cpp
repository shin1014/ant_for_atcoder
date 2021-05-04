#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> table;
vector<vector<bool>> flags;
vector<vector<int>> dist;

int sx, sy, gx, gy;
deque<int> x_que;
deque<int> y_que;

int PAINT(int x, int y);

int main(){
    cin >> H >> W;
    table.resize(H);
    dist.resize(H);
    flags.resize(H);
    for(int i=0;i<H;i++){
        table[i].resize(W);
        dist[i].resize(W);
        flags[i].resize(W);
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> table[i][j];
            if(table[i][j] == 's'){
                sx = j;
                sy = i;
            }else if(table[i][j] == 'g'){
                gx = j;
                gy = i;
            }
            dist[i][j] = -1;
            flags[i][j] = false;
        }
    }

    dist[sy][sx] = 0;
    x_que.push_back(sx);
    x_que.push_back(sy);
    int x, y;
    while(!x_que.empty()){
        x = x_que.front();
        y = y_que.front();
        x_que.pop_front();
        y_que.pop_front();

        /*
        cout << "(" << x << ", " << y << ")" << endl;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout << dist[i][j];
            }
            cout << endl;
        }
        cout << endl;
        */

        switch (PAINT(x+1, y)){
            case 0:
                dist[y][x+1] = dist[y][x];
                break;
            case 1:
                dist[y][x+1] = dist[y][x] + 1;
                break;
            default:
                break;
        }
        switch (PAINT(x-1, y)){
            case 0:
                dist[y][x-1] = dist[y][x];
                break;
            case 1:
                dist[y][x-1] = dist[y][x] + 1;
                break;
            default:
                break;
        }
        switch (PAINT(x, y+1)){
            case 0:
                dist[y+1][x] = dist[y][x];
                break;
            case 1:
                dist[y+1][x] = dist[y][x] + 1;
                break;
            default:
                break;
        }
        switch (PAINT(x, y-1)){
            case 0:
                dist[y-1][x] = dist[y][x];
                break;
            case 1:
                dist[y-1][x] = dist[y][x] + 1;
                break;
            default:
                break;
        }
 
    }
    //cout << dist[gy][gx] << endl;
    if(dist[gy][gx] <= 2 && dist[gy][gx] >= 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int PAINT(int x, int y){
    if(x<0 || x>=W || y<0 || y>=H){
            return -1;
    }
    if(table[y][x] != '#'  && flags[y][x] == false){
        flags[y][x] = true;
        x_que.push_front(x);
        y_que.push_front(y);
        return 0;
    }else if(table[y][x] == '#' && flags[y][x] == false){
        flags[y][x] = true;
        x_que.push_back(x);
        y_que.push_back(y);
        return 1;
    }else{
        return -1;
    }
}
