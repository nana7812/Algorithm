#include <string>
#include <iostream>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
bool check[11][11][4];
int solution(string dirs) {
    int answer = 0;
    int x = 5; int y = 5;
    for(int i = 0; i < dirs.size(); i++){
        char dir = dirs[i];
        int k = 0; int l = 0;
        if(dir == 'U'){
            k = 0;
            l= 1;
        }else if(dir == 'D'){
            k = 1;
            l = 0; 
        }else if(dir == 'R'){
            k = 2;
            l = 3;
        }else if(dir == 'L'){
            k = 3;
            l = 2;
        }
        int nx = x+dx[k];
        int ny = y + dy[k];
        if(0 > nx || nx > 10 || 0 > ny || ny >10 ) continue;
        if(check[nx][ny][l] == false && check[x][y][k] == false){
            cout<<i+1<<" ";
            answer++;
            check[nx][ny][l] = true;
            check[x][y][k] = true;
        }
        x = nx;
        y = ny;
    }
    return answer;
}