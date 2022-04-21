#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,M;
int map[21][21];
bool check[21][21];


struct Block{
    int total = 0;
    int x = 0;
    int y = 0;
    vector<pair<int,int>> m;
    vector<pair<int,int>> r;
};

bool compare(Block a, Block b){
    if(a.total == b.total){
        if(a.r.size() == b.r.size()){
            if(a.x == b.x){
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.r.size() > b.r.size();
    }
    return a.total > b.total;
}

bool inside(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void down(){
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >= 0; j--){
//            if(map[j][i] < 0) continue;
//            int cur = j; int next = j+1;
//            while(inside(cur,next) && map[next][i] == -2){
//                map[next][i] = map[cur][i];
//                map[cur][i] = -2;
//                cur++;
//                next++;
//            }
            int cur = j; int next = j+1;
            while(inside(cur,next) && map[cur][i] >= 0 && map[next][i] == -2 ){
                map[next][i] = map[cur][i];
                map[cur][i] = -2;
                cur++;
                next++;
            }
        }
    }

}

void rotate(){
    //여기서 temp 선업하고 바로 원본으로 옮기까?
    int temp[21][21];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = map[j][N-1-i];
        }
    }
    memcpy(map,temp,sizeof(temp));

}

int main() {

    memset(map,-2,sizeof(map));
    cin>> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> map[i][j];
        }
    }


    int answer = 0;
    while(true){
        //1단계
        //블록 그룹들
        vector<Block> groups;
        memset(check,false,sizeof(check)); //일반 블록만
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] > 0 && !check[i][j]){
                    int color = map[i][j];
                    int total = 1;
                    vector<pair<int,int>> m; vector<pair<int,int>> r;
                    m.push_back({i,j});
                    //블록 만들 조건을 갖춰보자
                    //일단 기준 블록은 i,j
                    //그룹 만들어보기
                    vector<vector<bool>> c(N,vector<bool>(N,false)); //그룹용 이거 배열로 다시 해보기
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    c[i][j] = true;
                    while(!q.empty()){
                        int qx = q.front().first;
                        int qy = q.front().second;
                        q.pop();
                        for(int d = 0; d < 4; d++){
                            int nx = qx + dx[d];
                            int ny = qy + dy[d];
                            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if(map[nx][ny] < 0 || c[nx][ny]) continue;
                            if(map[nx][ny] == 0){
                                q.push({nx,ny});
                                c[nx][ny] = true;
                                total++;
                                r.push_back({nx,ny});
                            }else if(color == map[nx][ny]){
                                q.push({nx,ny});
                                c[nx][ny] = true;
                                total++;
                                m.push_back({nx,ny});
                                check[nx][ny] = true;//?
                            }
                        }
                    }

                    if(m.size() >= 1 && total >= 2){
                        groups.push_back({total,i,j,m,r});
                    }
                }
            }
        }

        //종료조건 만들기
        if(groups.size() == 0) break;

        //2단계
        //조건에 맞는 그룹하나를 pick.
        sort(groups.begin(),groups.end(),compare);
        Block block = groups[0];
        //점수획득
        answer += (block.total * block.total);
        //블록 제거_무지개
        for(int i = 0; i < block.r.size(); i++){
            int x = block.r[i].first;
            int y = block.r[i].second;
            map[x][y] = -2;
        }
        //블록 제거_일반
        for(int i = 0; i < block.m.size(); i++){
            int x = block.m[i].first;
            int y = block.m[i].second;
            map[x][y] = -2;
        }

        //3단계_ 중력
        down();
        //

        //4단계 _반시계
        rotate();

        //5단계_중력
        down();
        //
    }

    cout<<answer<<"\n";

    return 0;
}
