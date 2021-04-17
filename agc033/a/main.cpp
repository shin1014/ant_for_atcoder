#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> table;
vector<vector<bool>> flags;
queue<int> x_que;
queue<int> y_que;
queue<int> c_que;
int c = 0;

void PAINT(int x, int y);

int main(){
    cin >> H >> W;
    table.resize(H);
    flags.resize(H);
    for(int i=0;i<H;i++){
        table[i].resize(W);
        flags[i].resize(W);
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> table[i][j];
            if(table[i][j]=='#'){
                flags[i][j] = true;
                x_que.push(j);
                y_que.push(i);
                c_que.push(0);
            }else{
                flags[i][j] = false;
            }
        }
    }

    int x, y, count;
    while(!x_que.empty()){
        x = x_que.front();
        y = y_que.front();
        c = c_que.front();
        count = c;
        x_que.pop();
        y_que.pop();
        c_que.pop();
        PAINT(x+1, y);
        PAINT(x-1, y);
        PAINT(x, y+1);
        PAINT(x, y-1);
    }

    cout << count << endl;
}

void PAINT(int x, int y){
    if(x<0 || y<0 || x>=W || y>=H){
        return;
    }
    if(table[y][x] == '.' && flags[y][x] == false){
            table[y][x] = '#';
            flags[y][x] = true;
            x_que.push(x);
            y_que.push(y);
            c_que.push(c+1);
     }
}