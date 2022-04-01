#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;



int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,M;
int a[51][51];
int answer;
vector<pair<int,int>> virus;


void spreadVirus(string v){
    vector<vector<int>> d(N,vector<int>(N,-1));
    queue<pair<int,int>> q;
    for(int i = 0; i < v.length(); i++){
        int idx = v[i] - '0';
        int x = virus[idx].first;
        int y = virus[idx].second;
        q.push({x,y});
        d[x][y] = 0;
    }

    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(d[nx][ny] != -1 || a[nx][ny] == 1) continue;
            else{
                d[nx][ny] = d[qx][qy] + 1;
                q.push({nx,ny});
            }
//            if(a[nx][ny] == 0){
//                d[nx][ny] = d[qx][qy] + 1;
//                q.push({nx,ny});
//            }else if(a[nx][ny] == 2){
//                d[nx][ny] = d[qx][qy];
//                q.push({nx,ny});
//            }
        }
    }

//    cout<<"---------------"<<"\n";
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < N; j++){
//            if(d[i][j] >= 0){
//                cout<<"+";
//            }
//            cout<<d[i][j]<<" ";
//        }
//        cout<<"\n";
//    }

    bool flag = true; int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0){
                if(d[i][j] == -1){
                    flag = false;
                    break;
                }else{
                    if(ans < d[i][j]){
                        ans = d[i][j];
                    }
                }
            }
        }
    }

    if(flag){
        //cout<<ans<<" "<<"\n";
        if(answer == -1 || answer > ans){
            answer = ans;
        }
    }

}



void chooseVirus(int cnt, int idx, string v){
    if(cnt >= M){
        spreadVirus(v);
        return;
    }

    for(int i = idx; i < virus.size(); i++){
        char c = i + '0';
        chooseVirus(cnt+1,i+1,v+c);
    }

}


int main() {
    answer = -1;
    cin >> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }

    chooseVirus(0,0,"");

    cout<<answer<<"\n";


    return 0;
}