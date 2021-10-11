#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>
#include <array>
#define MAX 55
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int crossX[] = {-1,-1,1,1};
int crossY[] = {-1,1,1,-1};
int N,M;
int a[MAX][MAX];
bool c[MAX][MAX];
vector<pair<int,int>> command;
queue<pair<int,int>> cloud;

int main(){
    //입력
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        int d,s;
        cin>>d>>s;
        d--;
        command.push_back({d,s});
    }
    //비바라기생
    cloud.push({N-1,0});
    cloud.push({N-1,1});
    cloud.push({N-2,0});
    cloud.push({N-2,1});
    //명령수행
    for(int i = 0; i < command.size(); i++){
        memset(c,false,sizeof(c));
        int md = command[i].first;
        int ms = command[i].second;
        int cloudSize = cloud.size();
        for(int j = 0; j < cloudSize; j++){
            //(1)구름이 있는 칸 이동
            int cx = cloud.front().first;
            int cy = cloud.front().second;
            cloud.pop();
            int nx = cx;
            int ny = cy;
            for(int k = 0; k < ms; k++){
                nx += dx[md];
                ny += dy[md];
                if(nx < 0) nx = N-1;
                if(nx >= N) nx = 0;
                if(ny < 0) ny = N-1;
                if(ny >= N) ny = 0;
            }
//.         범위 벗어나는 칸 컨트롤 
//            int move = ms % N;
//            int nx = cx + dx[md] * move;
//            int ny = cy + dy[md] * move;
//            if(nx >= N) nx -= N;
//            if(ny >= N) ny -= N;
//            if(nx < 0) nx += N;
//            if(ny < 0) ny += N;
            cloud.push({nx,ny});
            c[nx][ny] = true;
            //(2)구름이 있는칸 물의 양 추가
            a[nx][ny]++;
        }
        //(4)구름이 증가한 칸 마법사전
        while(!cloud.empty()){
            int cx = cloud.front().first;
            int cy = cloud.front().second;
            cloud.pop(); //(3)번
            int cnt = 0;
            for(int k = 1; k < 8; k+=2){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N ) continue;
                if(a[nx][ny] >=1) cnt++;
            }
            a[cx][cy] += cnt;
        }
        //(5)물의 양이 2이상인칸 구름 생성
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(a[i][j] >= 2 && c[i][j] == false){
                    a[i][j] -= 2;
                    cloud.push({i,j});
                }
            }
        }
    }

    //정답 도출
    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            answer += a[i][j];
        }
    }
    cout<<answer<<"\n";

    return 0;
}