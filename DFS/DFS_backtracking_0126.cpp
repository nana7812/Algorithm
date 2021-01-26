#include <string>
#include <vector>

using namespace std;

int vx[12+1], vy[12+1];
int dfs(int y, int x,int n){
    
    //가지치기
    for(int i = 0; i < y; i++){
        if(y == vy[i]) return 0;//가로
        if(x == vx[i]) return 0;//세로
        if(abs(x-vx[i]) == abs(y-vy[i])) return 0;//대각선 
    }
    
    if(y == n-1){
        //퀸 배열이 성공적인지 체크 성공이면 1
        return 1;
    }
    //말의 위치 기억
    vy[y] = y; vx[y] = x;
    int r = 0;
    for(int i = 0; i < n; i++){
        r += dfs(y+1,i,n);
    }
    return r;
}

int solution(int n) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer += dfs(0,i,n);
    }
    
    return answer;
}