#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

struct group{
    vector<pair<int,int>> block;
    int totalCnt = 0;
    int rainbowCnt = 0;
    int x = 0;
    int y = 0;
};

int N,M;
int color[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool inside(int x, int y){
    return 0<= x && x < N && 0 <= y && y < N;
}

bool cmp(group A, group B){
    if(A.totalCnt >= B.totalCnt){
        if(A.totalCnt == B.totalCnt){
            if(A.rainbowCnt >= B.rainbowCnt){
                if(A.rainbowCnt == B.rainbowCnt){
                    if(A.x >= B.x){
                        if(A.x == B.x){
                            if(A.y > B.y){
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void rotate(){
    int temp[21][21];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = color[j][N-1-i];
        }
    }
    memcpy(color,temp,sizeof(temp));
}

void drop(int idx){
    for(int i = N-1; i >= 0; i--){
        if(color[i][idx] < 0) continue;
        int cur = i; int next = i+1;
        while(inside(cur,next) && color[next][idx] == -2){
            color[next][idx] = color[cur][idx];
            color[cur][idx] = -2;
            cur++;
            next++;

        }
    }
}

int main(){

    int answer = 0;
    cin>>N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>color[i][j];
        }
    }
    while(true){
        //그룹생성
        bool c[21][21];
        memset(c,false,sizeof(c)); //초기화 꼭
        vector<group> blockGroup;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(color[i][j] >= 1 && !c[i][j]){
                    bool check[21][21];
                    memset(check,false,sizeof(check));
                    bool create = false;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(!inside(nx,ny)) continue;
                        if(color[nx][ny] == color[i][j] || color[nx][ny] == 0){
                            create = true;
                            break;
                        }
                    }
                    if(create) {
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        //  cout<<"("<<i<<" "<<j<<")";
                        check[i][j] = true;
                        group g;
                        g.x = i;
                        g.y = j;
                        g.totalCnt++;
                        g.block.push_back({i, j});
                        int cc = color[i][j];
                        while (!q.empty()) {
                            int qx = q.front().first;
                            int qy = q.front().second;
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                int  nx = qx + dx[k];
                                int  ny = qy + dy[k];
                                //  cout<<"확인"<<nx <<" "<<ny<<" ";
                                if (!inside(nx, ny)){
                                    //  cout<<"범위넘김"<<" ";
                                    continue;
                                }
                                if (check[nx][ny]) {
                                    //  cout<<"이미 방문"<<" ";
                                    continue;
                                }
                                if (color[nx][ny] == cc || color[nx][ny] == 0) {
                                    if (color[nx][ny] == 0) {
                                        g.rainbowCnt++;
                                    }
                                    if(color[nx][ny] == cc){
                                        c[nx][ny] = true;
                                    }
                                    q.push({nx, ny});
                                    //  cout<<"("<<i<<" "<<j<<")";
                                    check[nx][ny] = true;
                                    g.block.push_back({nx, ny});
                                    g.totalCnt++;
                                }
                            }
                        }
                        // cout<<"\n";
                        blockGroup.push_back(g);
                    }
                }
            }
        }
        //블록 없으면 중단
        if(blockGroup.size() == 0){
            break;
        }
        //그룹 선택기준
        sort(blockGroup.begin(),blockGroup.end(),cmp);
        //선택된 그룹 제거
        for(int i = 0; i < blockGroup[0].block.size(); i++){
            color[blockGroup[0].block[i].first][blockGroup[0].block[i].second] = -2; //제거단계
        }
        answer += (blockGroup[0].totalCnt * blockGroup[0].totalCnt);
        //중력작용
        for(int i = 0; i < N; i++){
            drop(i);
        }
        //반시계
        rotate();
        //중력작용
        for(int i = 0; i < N; i++){
            drop(i);
        }
    }
    cout<<answer<<"\n";

}