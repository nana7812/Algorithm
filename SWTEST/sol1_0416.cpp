#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
};

int N, M, K;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int same[] = {0,2,4,6};
int nsame[] = {1,3,5,7};

vector<Fireball> ball;
vector<Fireball> map[51][51];


int main() {
    //입력
    cin>> N>> M>> K;
    for(int i = 0; i <M; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        ball.push_back({a-1,b-1,c,d,e});
        map[a-1][b-1].push_back({a-1,b-1,c,d,e});
    }

    while(K--){

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j].clear();
            }
        }

        //1.
        for(int i = 0; i < ball.size(); i++){
            int r = ball[i].r;
            int c = ball[i].c;
            int m = ball[i].m;
            int s = ball[i].s;
            int d = ball[i].d;

            int move = s % N;
            int nr = r + dx[d] * move;
            int nc = c + dy[d] * move;
            if(nr >= N) nr -= N;
            if(nc >= N) nc -= N;
            if(nr < 0) nr += N;
            if(nc < 0) nc += N;

            map[nr][nc].push_back({nr,nc,m,s,d});
            ball[i].r = nr;
            ball[i].c = nc;
        }

        //2.
        vector<Fireball> temp;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j].size() == 0) continue;
                if(map[i][j].size() == 1){
                    temp.push_back({map[i][j][0]});
                    continue;//?
                }else{
                    int cnt = map[i][j].size();
                    int totalM = 0; int totalS = 0;
                    bool odd = true; bool even = true; //모두 짝수 또는 홀수인 경우
                    for(int k = 0; k < map[i][j].size(); k++){
                        totalM += map[i][j][k].m;
                        totalS += map[i][j][k].s;
                        if(map[i][j][k].d % 2 == 0) odd = false;
                        else even = false;
                    }
                    int nm = totalM/5;
                    int ns = totalS/cnt;
                    if(nm == 0) continue;
                    if(odd || even){
                        for(int k = 0; k < 4; k++){
                            temp.push_back({i,j,nm,ns,same[k]});
                        }
                    }else{
                        for(int k = 0; k < 4; k++){
                            temp.push_back({i,j,nm,ns,nsame[k]});
                        }
                    }
                }
            }
        }
        ball = temp;

    }

    int answer = 0;
    for(int i = 0; i < ball.size(); i++){
        answer += ball[i].m;
    }
    cout<<answer<<" ";

    return 0;
}