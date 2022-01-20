#include <string>
#include <iostream>
using namespace std;

bool c[11][11][4];

bool inside(int x, int y){
    return 0 <= x && x<= 10 && 0 <= y && y <= 10;
}

int solution(string dirs) {
    int answer = 0;
    int x = 5 , y = 5;
    for(int i = 0; i < dirs.size(); i++){
       // cout<<i+1<<" "<<dirs[i]<<" "<<x <<" "<<y<<"\n";
        if(dirs[i] == 'U'){
            int nx = x -1;
            if(inside(nx,y)){
                if(!c[x][y][0] && !c[nx][y][1]){
                    answer++;
                    c[x][y][0] = true;
                    c[nx][y][1] = true;
                }
                x = nx;
            }
        }else if(dirs[i] == 'D'){
            int nx = x + 1;
            if(inside(nx,y)){
                if(!c[x][y][1] && !c[nx][y][0]){
                    answer++;
                    c[x][y][1] = true;
                    c[nx][y][0] = true;
                }
                x= nx;
            }
        }else if(dirs[i] == 'R'){
            int ny = y+1;
            if(inside(x,ny)){
                if(!c[x][y][2] && !c[x][ny][3]){
                    answer++;
                    c[x][y][2] = true;
                    c[x][ny][3] = true;
                }
                y = ny;
            }
        }else{
            int ny = y -1;
            if(inside(x,ny)){
                if(!c[x][y][3] && !c[x][ny][2]){
                    answer++;
                    c[x][y][3] = true;
                    c[x][ny][2] = true;
                }
                y = ny;
            }
        }
    }
    return answer;
}