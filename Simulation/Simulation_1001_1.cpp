#include <iostream>
#include <vector>
#define MAX 55
using namespace std;

struct Fireball{
    int x;
    int y;
    int massive;
    int speed;
    int dir;
};
int N, M, K;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int same[] = {0,2,4,6};
int notSame[] = {1,3,5,7};

vector<Fireball> a[MAX][MAX];
vector<Fireball> fireball;

int main(){
    cin>> N>> M>> K;
    for(int i = 0; i < M; i++){
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        fireball.push_back({r,c,m,s,d});
        a[r][c].push_back({r,c,m,s,d});
    }
    while(K--){
        //이동
        //모두 이동할거니까 원래 위치에 있던 파이어 볼 없애기
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                a[i][j].clear();
            }
        }
        for(int i = 0; i < fireball.size(); i++){
            int x = fireball[i].x;
            int y = fireball[i].y;
            int m = fireball[i].massive;
            int s = fireball[i].speed;
            int d = fireball[i].dir;
            //1-N 연결
            int move = s % N;
            int nx = x + dx[d] * move;
            int ny = y + dy[d] * move;
            if(nx > N) nx -= N;
            if(ny > N) ny -= N;
            if(nx < 1) nx += N;
            if(ny < 1) ny += N;
            a[nx][ny].push_back({nx,ny,m,s,d});
            fireball[i].x = nx;
            fireball[i].y = ny;
        }

        //이동후 어떠한 위치에 볼이 2개이상인 경우
        vector<Fireball> temp;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(a[i][j].size() == 0) continue;
                if(a[i][j].size() == 1){
                    temp.push_back({a[i][j][0]}); //여기문법!!!
                    continue;
                }
                int mSum = 0;
                int sSum = 0;
                int total = a[i][j].size();
                bool even = true;
                bool odd = true;
                for(int k = 0; k < a[i][j].size(); k++){
                    mSum += a[i][j][k].massive;
                    sSum += a[i][j][k].speed;
                    if(a[i][j][k].dir % 2 == 0) odd = false;
                    else even = false;
                }
                int nm = mSum/5;
                int ns = sSum/total;
                if(nm == 0) continue;
                if(even == true || odd == true){
                    for(int k = 0; k < 4; k++){
                        temp.push_back({i,j,nm,ns,same[k]});
                    }
                }else{
                    for(int k = 0; k < 4; k++){
                        temp.push_back({i,j,nm,ns,notSame[k]});
                    }
                }
            }
        }
        fireball = temp;
    }

    int answer = 0;
    for(int i = 0; i <fireball.size();i++){
        answer += fireball[i].massive;
    }
    cout<<answer<<"\n";

    return 0;
}