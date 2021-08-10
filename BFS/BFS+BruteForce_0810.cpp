#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int N, M;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[51][51];
int d[51][51];
vector<pair<int,int>> Virus;
vector<string> Com;

void combination(int total,int cnt,int num,string s){
    if(cnt >= M){
        Com.push_back(s);
        return;
    }
    for(int i = num; i < total; i++){
        char c = i + '0';
        combination(total,cnt+1,i+1,s+c);
    }
}

int main() {
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){
                Virus.push_back({i,j});
            }
        }
    }

    //조합 만들기
    combination(Virus.size(),0,0,"");

    //조합만큼 확인
    int answer = -1;
    for(int i = 0; i < Com.size(); i++){
        memset(d,-1,sizeof(d));
        queue<pair<int,int>> q;
        for(auto s : Com[i]){
            int is = s - '0';
            q.push({Virus[is].first,Virus[is].second});
            d[Virus[is].first][Virus[is].second] = 0;
        }
        while(!q.empty()){
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = qx+ dx[k];
                int ny = qy + dy[k];
                if(0>nx || nx >= N || 0> ny || ny >= N) continue;
                if(a[nx][ny] != 1 && d[nx][ny] == -1){
                    q.push({nx,ny});
                    d[nx][ny] = d[qx][qy] +1;
                }
            }
        }

        bool impossible = false; int temp = 0;
        for(int h = 0; h < N; h++){
            for(int w = 0; w< N; w++){
                if(a[h][w] == 0 && d[h][w] == -1){
                    impossible = true;
                }
                if(a[h][w] == 0 && d[h][w] > temp) temp = d[h][w];
            }
        }

        if(impossible == false){
            if(answer == -1 || answer > temp) answer = temp;
        }

    }
    cout<<answer;
    return 0;
}