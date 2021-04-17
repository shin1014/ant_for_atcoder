#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> table;
vector<vector<int>> dist;
vector<vector<int>> pre_x;
vector<vector<int>> pre_y;

queue<int> x_que;
queue<int> y_que;
int Push(int x, int y);
int cheak(int x, int y);

int main(){
    cin >> H >> W;
    table.resize(H);
    dist.resize(H);
    pre_x.resize(H);
    pre_y.resize(H);
    for(int i=0;i<H;i++){
        table[i].resize(W);
        dist[i].resize(W);
        pre_x[i].resize(W);
        pre_y[i].resize(W);
    }

    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            cin >> table[y][x];
            dist[y][x] = -1;
            pre_x[y][x] = -1;
            pre_y[y][x] = -1;
        }
    }

    x_que.push(0);
    y_que.push(0);
    dist[0][0] = 0;

    int x, y;
    while(!x_que.empty()){
        x = x_que.front();
        y = y_que.front();
        x_que.pop();
        y_que.pop();

        if(Push(x+1, y)){
            dist[y][x+1] = dist[y][x] + 1;
            pre_x[y][x+1] = x;
            pre_y[y][x+1] = y;
        }
        if(Push(x-1, y)){
            dist[y][x-1] = dist[y][x] + 1;
            pre_x[y][x-1] = x;
            pre_y[y][x-1] = y;
        }
        if(Push(x, y+1)){
            dist[y+1][x] = dist[y][x] + 1;
            pre_x[y+1][x] = x;
            pre_y[y+1][x] = y;
        }
        if(Push(x, y-1)){
            dist[y-1][x] = dist[y][x] + 1;
            pre_x[y-1][x] = x;
            pre_y[y-1][x] = y;
        }
    }

    if(dist[H-1][W-1] == -1){
        cout << -1 << endl;
        return 0;
    }else{
        int xx=W-1, yy=H-1, tempx, tempy;
        while(xx!=-1 && yy!=-1){
            table[yy][xx] = 'o';
            tempx = pre_x[yy][xx];
            tempy = pre_y[yy][xx];
            xx = tempx;
            yy = tempy;
        }
    }

    int count=0;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(table[y][x] != 'o' && table[y][x] == '.'){
                count++;
            }
        }
    }

    cout << count << endl;



}

int Push(int x, int y){
    if(x<W && x>=0 && y<H && y>=0 && cheak(x, y)){
            x_que.push(x);
            y_que.push(y);
            return true;
    }else{
        return false;
    }
}

int cheak(int x, int y){
    if(table[y][x] == '.' && dist[y][x] == -1) return true;
    else return false;
}
