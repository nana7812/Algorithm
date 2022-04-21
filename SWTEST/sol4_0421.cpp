#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int td[] = {2,1,3,0};

int N,M;
int total = 0, score = 0;
int m[50][50];
vector<int> tmp; //구슬


void Ball(){
    tmp.clear();
    int x,y,d = 0, t = 1;
    x = N/2, y = N/2;

    int cnt = 0;
    while(cnt != total){
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < t; i++){
                int nx = x + dx[td[d]];
                int ny = y + dy[td[d]];
                if(m[nx][ny]){
                    tmp.push_back(m[nx][ny]);
                    cnt++;
                }
                x = nx;
                y = ny;
                if(cnt == total) return;
            }
            d = (d+1) % 4;
        }
        t++;
    }
}

void updateMap(){
    memset(m,0,sizeof(m));
    int x,y,d = 0;
    int t = 1;
    x = N/2, y = N/2;
    int cnt = 0;
    while(cnt != tmp.size()){
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < t; i++){
                int nx = x + dx[td[d]];
                int ny = y + dy[td[d]];
                m[nx][ny] = tmp[cnt++];
                x = nx;
                y = ny;
                if(cnt == tmp.size()) return;
            }
            d = (d+1)%4;
        }
        t++;
    }
}

void explode(){
    bool flag = true;
    while(flag){
        vector<int> ttmp;
        int tt;
        flag = false;
        for(int i = 0; i < tmp.size(); i++){
            tt = i;
            while(tmp[tt] == tmp[i] && tt < tmp.size()) tt++;
            if(tt - i < 4){
                for(int j = i; j < tt; j++){
                    ttmp.push_back(tmp[i]);
                }
            }else{
                score += tmp[i] * (tt-i);
                flag = true;
            }
            i = tt-1;
        }
        tmp = ttmp;
    }

}

void change(){
    vector<int> ttmp;
    int tt;
    for(int i = 0; i < tmp.size(); i++){
        if(ttmp.size() >= N*N) break;
        tt = i;
        while(tmp[tt] == tmp[i] && tt< tmp.size()) tt++;
        int A = tt-i, B = tmp[i];
        ttmp.push_back(A);
        ttmp.push_back(B);
        i = tt-1;
    }
    if(ttmp.size() >= N*N)
        while(ttmp.size() >= N*N) ttmp.pop_back();
    tmp = ttmp;
    total = tmp.size();
}

int main() {

    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>m[i][j];
            if(m[i][j] > 0) total++;
        }
    }
    int d,s;
    while(M--){
        cin>>d>> s;
        d--;
        //구슬 깨기
        int x = N/2, y = N/2;
        for(int i = 0; i < s; i++){
            x += dx[d];
            y += dy[d];
            if(m[x][y] == 0) continue;
            m[x][y] = 0;
            total--;
        }

        Ball();

        explode();

        change();

        updateMap();

    }


    cout<<score<<" ";


    return 0;
}