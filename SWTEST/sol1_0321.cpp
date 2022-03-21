#include <vector>
#include <iostream>

using namespace std;

int N, M,answer;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct CCTV{
    int num;
    int x;
    int y;
};

vector<CCTV> cctv;

void on(vector<vector<int>> &v, int x, int y, int dir,int num){
    int nx = x; int ny = y;
    while((0<=nx && nx < N && 0 <= ny && ny < M) && v[nx][ny] != 6){
        v[nx][ny] = num;
        nx += dx[dir];
        ny += dy[dir];
    }

}

void dfs(int cnt, vector<vector<int>> v){
    if(cnt == cctv.size()){
        int temp = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(v[i][j] == 0) temp++;
            }
        }
        if(answer == -1 ||temp < answer) answer = temp;
        return;
    }


    for(int i = 0; i < 4; i++){
        vector<vector<int>> tempV = v;
        if(cctv[cnt].num == 1){
            on(tempV,cctv[cnt].x,cctv[cnt].y,i,cctv[cnt].num);
        }else if(cctv[cnt].num == 2){
            on(tempV,cctv[cnt].x,cctv[cnt].y,i,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+2)%4,cctv[cnt].num);
        }else if(cctv[cnt].num == 3){
            on(tempV,cctv[cnt].x,cctv[cnt].y,i,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+3)%4,cctv[cnt].num);
        }else if(cctv[cnt].num == 4){
            on(tempV,cctv[cnt].x,cctv[cnt].y,i,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+2)%4,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+3)%4,cctv[cnt].num);
        }else if(cctv[cnt].num == 5){
            on(tempV,cctv[cnt].x,cctv[cnt].y,i,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+1)%4,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+2)%4,cctv[cnt].num);
            on(tempV,cctv[cnt].x,cctv[cnt].y,(i+3)%4,cctv[cnt].num);
        }

        dfs(cnt+1,tempV);
    }
}

int main() {
    cin>> N>> M;
    vector<vector<int>> a(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
            if(1<= a[i][j] && a[i][j] <= 5){
                cctv.push_back({a[i][j],i,j});
            }
        }
    }

    answer = -1;
    dfs(0, a);
    cout<<answer<<" ";

    return 0;
}