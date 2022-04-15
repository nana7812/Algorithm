#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,M,fuel;
int x,y;
int map[21][21];
int start[21][21];
pair<int,int> finish[401];
bool c[21][21];

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int choose(){
    if(start[x][y] > 0){
        return 0;
    }

    memset(c,false,sizeof(c));
    vector<pair<int,int>> pos;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    c[x][y] = true;
    int cnt = -1;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N){
                if(map[nx][ny] == 1 || c[nx][ny]) continue;
                if(cnt == -1){
                    q.push({{nx,ny},qc+1});
                    c[nx][ny] = true;
                    if(start[nx][ny] > 0){
                        cnt = qc+1;
                        pos.push_back({nx,ny});
                    }
                }else if(cnt == qc+1 && start[nx][ny] > 0){
                    pos.push_back({nx,ny});
                }
            }
        }
    }
  
   if(cnt == -1) return cnt;
    sort(pos.begin(),pos.end(),compare);
    x = pos[0].first; y = pos[0].second;
    return cnt;
}

int arrive(int n){
    if(x == finish[n].first && y == finish[n].second){
        return 0;
    }
    
    memset(c,false,sizeof(c));

    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    c[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        if(qx == finish[n].first && qy == finish[n].second){
            x = qx;
            y = qy;
            return qc;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N){
                if(c[nx][ny] || map[nx][ny] == 1) continue;
                q.push({{nx,ny},qc+1});
                c[nx][ny] = true;
            }
        }
    }

    return -1;
}


int main() {

    cin>> N>> M>> fuel;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }

    cin>> x>> y;
    x--;y--;

    for(int i = 1; i <= M; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        start[a-1][b-1] = i;
        finish[i].first = c-1;
        finish[i].second = d-1;
    }

    bool flag = false;
    while(M--){
       // cout<<x<<" "<<y<<"시작"<<"\n";
        //승객고르기_거리
        int scnt = choose();
        //거리만큼 갈 수 있는지 확인
        if(fuel - scnt < 0 || scnt == -1){
            flag = true;
            break;
        }
        //승객 위치로 이동가능
        fuel -= scnt;
        int m = start[x][y]; //태운 승객
        start[x][y] = 0; //태운 승객 위치는 0으로
        
        //도착지 최단거리
        int fcnt = arrive(m);

        //거리만큼 갈 수 있는지 확인
        if(fuel - fcnt < 0 || fcnt == -1){
            flag = true;
            break;
        }
        fuel -= fcnt;

        fuel += fcnt*2;
    }

    if(flag){
        cout<<-1<<"\n";
    }else{
        cout<<fuel<<"\n";
    }


    return 0;
}