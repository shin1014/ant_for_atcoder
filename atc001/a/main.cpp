#include <bits/stdc++.h>
using namespace std;


int dfs(int x, int y, vector<vector<char>> &table, vector<vector<bool>> &flags, int H, int W){
    if(x>W-1 || y>H-1 || x<0 || y<0){
        return 0;
    }
    if(flags[y][x] == true){
        return 0;
    }
    flags[y][x] = true;
    char target = table[y][x];
    if(target == '#'){
        return 0;
    }else{
        dfs(x+1, y, table, flags, H, W);
        dfs(x-1, y, table, flags, H, W);
        dfs(x, y+1, table, flags, H, W);
        dfs(x, y-1, table, flags, H, W);
    }
    return 0;
}

int main(){
    int H, W;
    int sx, sy, gx, gy;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    vector<vector<bool>> flags(H, vector<bool>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> table[i][j];
            flags[i][j] = false;
            if(table[i][j]=='s'){
                sx = j;
                sy = i;
            }else if(table[i][j]=='g'){
                gx = j;
                gy = i;
            }
        }
    }

    dfs(sx, sy, table, flags, H, W);

    if(flags[gy][gx]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}
