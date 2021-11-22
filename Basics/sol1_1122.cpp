#include <string>
using namespace std;


bool check[100][100][4]; //움직이는 길에 해당하는 모든 점 방향 체크해야함
// [x][y][nx][ny] [nx][ny][x][y] <- 이렇게 하면 더 간단함!!

int solution(string dirs) {
    int answer = 0;
    int x = 5; int y = 5;
    for(int i = 0; i < dirs.size(); i++){
        int nx = x; int ny = y; int nd = 0; int d = 0;
        if(dirs[i] == 'U'){
            nx = x - 1;
            d = 0;
            nd = 1;
        }else if(dirs[i] == 'D'){
            nx = x + 1;
            d = 1; 
            nd = 0;
        }else if(dirs[i] == 'R'){
            ny = y +1;
            d = 3;
            nd = 2;
        }else{
            ny = y -1;
            d = 2;
            nd = 3;
        }
        if(0 > nx || nx > 10 || 0 > ny || ny > 10) continue;
        if(!check[nx][ny][nd]){
            answer++;
            check[nx][ny][nd] = true;
            check[x][y][d] = true;
        }
        x = nx;
        y = ny;
    }
    return answer;
}