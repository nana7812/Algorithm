#include<iostream>
#include<vector>


using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int N, M;
int answer;
vector<vector<int>> map(10,vector<int>(10));
vector<pair<int,pair<int,int>>> camera;
vector<int> d(9);

void turnON(vector<vector<int>> & v,int dir, int x, int y ){
    int num = v[x][y];
    int nx, ny;
    while(true){
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(0> nx || nx >= N || 0 >ny || ny >= M )break;
        if(v[nx][ny] == 6) break;
        v[nx][ny] = num;
        x = nx;
        y = ny;
    }
}

void cctv(){
    vector<vector<int>> v(map);
    for(int i = 0; i < camera.size(); i++){
        int num = camera[i].first;
        int x = camera[i].second.first;
        int y = camera[i].second.second;
        if(num == 1){
            turnON(v,d[i],x,y);
        }else if(num == 2){
            turnON(v,d[i],x,y);
            turnON(v,(d[i]+2)%4,x,y);
        }else if(num == 3){
            turnON(v,d[i],x,y);
            turnON(v,(d[i]+1)%4,x,y);
        }else if(num == 4){
            turnON(v,d[i],x,y);
            turnON(v,(d[i]+1)%4,x,y);
            turnON(v,(d[i]+2)%4,x,y);
        }else{
            turnON(v,d[i],x,y);
            turnON(v,(d[i]+1)%4,x,y);
            turnON(v,(d[i]+2)%4,x,y);
            turnON(v,(d[i]+3)%4,x,y);
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 0) cnt++;
        }
    }
    if(answer == -1 || answer > cnt){
        answer = cnt;
    }
}

void makeCom(int cnt){
    if(cnt >= camera.size()){
        cctv();
        return;
    }
    for(int i = 0; i < 4; i++){
        d[cnt] = i;
        makeCom(cnt+1);
    }
}

int main(){
    int T;
    cin>> T;
    while(T--){
        answer = -1;
        camera.clear();
        cin>> N>> M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>map[i][j];
                if(1<= map[i][j] && map[i][j] <= 5){
                    camera.push_back({map[i][j],{i,j}});
                }
            }
        }
        //카메라 방향 조합 만들기
        makeCom(0);
        cout<<answer<<"\n";

    }
    return 0;
}