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
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct Client{
    int sx;
    int sy;
    int ex;
    int ey;
    bool arrive = false;
};
Client client[410];

int N,M,engine;
int taxiX,taxiY;
int m[21][21];
bool check[21][21];
priority_queue<pair<int,pair<pair<int,int>,int>>> pq;//거리,행,열,번호

int diff;
int BFS(int num,int sx,int sy, int ex,int ey){
    memset(check,false,sizeof(check));
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    check[sx][sy] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(qx == ex && qy == ey){
            //cout << num + 1 << "거리" << qc << "위치" << qx << " " << qy << "\n";
            pq.push({-qc, {{-qx, -qy}, num}});
            if(diff == -1 || diff > qc ) diff = qc;
            return num;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0>nx || 0> ny || nx >= N || ny >= N ) continue;
            if(m[nx][ny] == 1 || check[nx][ny] == true) continue;
            if(diff != -1  && qc+1 > diff ) continue;
            q.push({{nx,ny},qc+1});
            check[nx][ny] = true;
        }
    }
    return -1;
}


int main(){
    cin>> N>> M>>engine;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>m[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    x--;y--;
    taxiX = x;
    taxiY = y;

    int a,b,c,d;
    for(int i = 0; i < M; i++){
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        client[i].sx = a;
        client[i].sy = b;
        client[i].ex = c;
        client[i].ey = d;
    }
    while(engine >= 0){
        //승객 위치별 최단거리 확인;
        diff = -1;
        pq = priority_queue<pair<int,pair<pair<int,int>,int>>>();
        bool f = false;
        for(int i = 0; i < M; i++){
            if(client[i].arrive) continue;
            c = BFS(i,taxiX,taxiY,client[i].sx,client[i].sy);
            if(c != -1){
                f = true;
            }
        }
        if(!f && c == -1){
            cout<<-1<<"\n";
            return 0;
        }
        //택시 -> 최단거리 승객
        int d = -pq.top().first;
        //cout<<"택시번호"<<pq.top().second.second+1<<" "<<"최단거리 "<<d<<"\n";
        engine -=d;
        if(engine <= 0){
            //cout<<"택시-> 승객 연료 바닥"<<"\n";
            break;
        }
        //+택시위치 이동 할말 고민 어차피 도착지에서 바꿔도 되니까..

        // 출발지-> 도착지
        int c = pq.top().second.second;
        memset(check,false,sizeof(check));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{client[c].sx,client[c].sy},{engine,0}});
        check[client[c].sx][client[c].sy]= true;
        bool finish = false; //도착지 도달했는
        bool possible = true;
        while(!q.empty()){
            int qx = q.front().first.first;
            int qy = q.front().first.second;
            int qe = q.front().second.first;
            int qd = q.front().second.second;
            q.pop();
            if(qx == client[c].ex && qy == client[c].ey){
                finish = true;
                if(qe < 0){
                    possible = false;
                    //cout<<"택시 -> 도착 연료바닥"<<"\n";
                    break;
                }else{
                    engine = qe;
                    engine += (qd*2);
                    client[c].arrive = true;
                    taxiX = qx;
                    taxiY = qy;
                    //cout<<"남은 연료 "<<engine<<"\n";
                    break;
                }
            }
            for(int i = 0; i < 4; i++){
                int nx = qx+ dx[i];
                int ny = qy + dy[i];
                if(0>nx || 0> ny || nx >= N || ny >= N ) continue;
                if(m[nx][ny] == 1 || check[nx][ny] == true) continue;
                q.push({{nx,ny},{qe-1,qd+1}});
                check[nx][ny] = true;
            }
        }
        //도착 못함
        if(!finish) break;
        //이동중 연료 바닥
        if(!possible) break;

        //모든 승객이 도착했는지 확인
        bool all = true;
        for(int i = 0; i < M; i++){
            if(!client[i].arrive){
                all = false;
                break;
            }
        }
        //다 도착함
        if(all){
            cout<<engine<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";

    return 0;
}
