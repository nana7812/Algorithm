#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int N, K;
int map[105][105];


void addFish(){
    vector<pair<int,int>> v;
    int minV = 987654321;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 0) continue;
            if(map[i][j] < minV){
                v.clear();
                minV = map[i][j];
                v.push_back({i,j});
            }else if(map[i][j] == minV){
                v.push_back({i,j});
            }
        }
    }

    for(int i = 0; i < v.size(); i++){ //++i
        map[v[i].first][v[i].second]++;
    }
}



//잠
void build(){
    int s,w,h;
    s = w = h = 1;
    int idx = 0;
    while(true){
        if(s + w+ h -1 > N) break;
        for(int i = s; i < s + w; i++){
            for(int j = N; j > N- h; j--){
                int nr = N- w + i-s;
                int nc = s + w + N -j;
                map[nr][nc] = map[j][i];
                map[j][i] = 0;
            }
        }
        if(idx % 2) w++;
        else h++;

        s += (idx/2+1);
        idx++;
    }
}


void control(){
    int temp[105][105] = {0,};
    //memset(temp,0,sizeof(temp));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] != 0){
                temp[i][j] += map[i][j];
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(map[nx][ny] == 0) continue;
                    if(map[i][j] > map[nx][ny]){
                        int diff  = (map[i][j] - map[nx][ny])/5;
                        temp[i][j] -= diff;
                        temp[nx][ny] += diff;
                    }
                }
            }
        }
    }

    memcpy(map,temp,sizeof(temp));
}


void sortFish(){
    queue<int> q;
    for(int j = 1; j <= N; j++){
        if(map[N][j] == 0) continue;
        for(int i = N; i >= 1; i--){ //--i;
            if(map[i][j] == 0) break;

            q.push(map[i][j]);
            map[i][j] = 0;
        }
    }

    int col = 1;
    while(!q.empty()){
        map[N][col] = q.front(); //col++
        q.pop();
        col++;
    }
}

void divide(){
    int qN = N/ 4;
    int sCol[] = {0,N,N-qN +1, N};
    int cDir[] = {0,-1,1,-1};

    int srcY = 1;
    for(int i = 1; i <= 3; i++){ //++i
        int c = sCol[i];
        for(int j = 0; j < qN; j++){ //++j
            map[N-i][c] = map[N][srcY];
            map[N][srcY] = 0;
            c += cDir[i];
            srcY++;
        }
    }
}

int getDiff(){
    int maxV = 0;
    int minV = 987654321;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 0) continue;

            maxV = max(maxV,map[i][j]);
            minV = min(minV,map[i][j]);
        }
    }

    return (maxV - minV);
}

int main(){

    cin >>N >> K;
    for(int i = 1; i <= N; i++){
        cin>> map[N][i];
    }

    int answer = 0;
    while(true){
        addFish();
        build();
        control();
        sortFish();

        divide();
        control();
        sortFish();

        answer++;
        if(getDiff() <= K) break;
    }

    cout<<answer<<"\n";

    return 0;
}