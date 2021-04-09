#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
vector<vector<char>> MAP(SIZE, vector<char>(SIZE));
vector<vector<bool>> FLAGS(SIZE, vector<bool>(SIZE));

void dfs(int x, int y);

int main(){
    int x, y, count=0, temp=0;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            cin >> MAP[i][j];
            FLAGS[i][j] = false;
            if(MAP[i][j] == 'o'){
                count++;
            }
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(MAP[i][j]== 'o'){
                continue;
            }else{
                temp = 0;
                MAP[i][j] = 'o';
                dfs(j, i);
                
                for(int p=0;p<SIZE;p++){
                    for(int q=0;q<SIZE;q++){
                        if(FLAGS[p][q] == true){
                            FLAGS[p][q] = false;
                            temp++;
                        }
                    }
                }
                if(count == temp-1){
                    cout << "YES" << endl;
                    return 0;
                }else{
                    MAP[i][j] = 'x';
                    continue;
                }
            }
        }
    }

    cout << "NO" << endl;
}

void dfs(int x, int y){
    if(x<0 || x>=SIZE ||  y<0 || y>=SIZE){
        return;
    }else if(FLAGS[y][x]==true){
        return;
    }
    if(MAP[y][x]=='x'){
        FLAGS[y][x] = false;
        return;
    }else if(MAP[y][x]=='o'){
        FLAGS[y][x] = true;
    }
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}
