#include <iostream>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,Q,L;
int a[70][70];
int temp[70][70];
bool check[70][70];

void rotate(int r, int c){
    int n = pow(2,L);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[r+i][c+j] = a[r+n-1-j][c+i];
        }
    }
}

pair<int,int> sol(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    int sum = a[x][y]; int cnt = 1;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(check[nx][ny]) continue;
            if(a[nx][ny] == 0) continue;
            q.push({nx,ny});
            check[nx][ny] = true;
            sum += a[nx][ny];
            cnt++;
        }
    }
    return make_pair(sum,cnt);
}

int main() {

    cin >> N>> Q;
    N = pow(2,N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> a[i][j];
        }
    }


    while(Q--){
        memset(temp,0,sizeof(temp));
        cin>>L;
        int l = pow(2,L);
        for(int i = 0; i < N; i +=l){
            for(int j = 0; j < N; j+=l){
                rotate(i,j);
            }
        }

        memcpy(a,temp,sizeof(temp));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp[i][j] == 0) continue;
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(temp[nx][ny] > 0) cnt++;
                }
                if(cnt < 3) a[i][j]--;
            }
        }
    }

    int ans1= 0, ans2 = 0;
    for(int i = 0; i <N; i++){
        for(int j = 0; j <N; j++){
            if(a[i][j] != 0 && !check[i][j]){
                auto t = sol(i,j);
                ans1 += t.first;
                if(ans2 < t.second){
                    ans2 = t.second;
                }
            }
        }
    }

    cout<<ans1<<"\n";
    cout<<ans2<<"\n";


    return 0;
}
