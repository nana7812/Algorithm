#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int N,M;
int a[55][55];

int main() {

    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    vector<pair<int,int>> pos;
    pos.push_back({N-1,0}); pos.push_back({N-1,1});
    pos.push_back({N-2,0}); pos.push_back({N-2,1});
    while(M--){
        vector<vector<bool>> c(N,vector<bool>(N, false));

        //1~3단계
        int d,s;
        cin>>d>>s;
        d--;
        int move = s % N;
        for(int i = 0; i < pos.size(); i++){ //이동
            int nx =  pos[i].first + dx[d] * move;
            int ny = pos[i].second + dy[d] * move;
            if(nx >= N) nx -= N;
            if(ny >= N) ny -=N;
            if(nx < 0) nx += N;
            if(ny < 0) ny += N;
            c[nx][ny] = true;
            a[nx][ny]++; //증가
        }
        pos.clear(); //구름 제거

        //4단계
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(c[i][j]){
                    int cnt = 0;
                    for(int k = 1; k < 8; k+=2){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(a[nx][ny] > 0) cnt++;
                    }
                    a[i][j] += cnt;
                }
            }
        }

        //5딘계
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(a[i][j] >= 2 && !c[i][j]){
                    pos.push_back({i,j});
                    a[i][j] -= 2;
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            answer += a[i][j];
        }
    }

    cout<<answer<<"\n";

    return 0;
}
