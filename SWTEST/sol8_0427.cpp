#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int same[] = {0,2,4,6};
int nsame[] = {1,3,5,7};

int N, M, K;

struct Fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
};
vector<Fireball> fireball;

int main() {

    cin>> N>> M>> K;
    for(int i = 0; i < M; i++){
        int r,c,m,s,d;
        cin>> r>>c>>m>>s>>d;
        fireball.push_back({r-1,c-1,m,s,d});
    }

    while(K--){
        vector<Fireball> move[N][N];
        for(int i = 0; i < fireball.size(); i++){
            int x = fireball[i].r;
            int y = fireball[i].c;
            int m = fireball[i].s % N;
            int nx = x + dx[fireball[i].d]*m;
            int ny = y + dy[fireball[i].d]*m;
            if(nx >= N) nx -= N;
            if(ny >= N) ny -= N;
            if(nx < 0) nx += N;
            if(ny < 0 ) ny += N;
            move[nx][ny].push_back({nx,ny,fireball[i].m,fireball[i].s,fireball[i].d});
        }

        vector<Fireball> nFireball;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(move[i][j].size() == 0) continue;
                if(move[i][j].size() == 1){
                    nFireball.push_back(move[i][j][0]);
                }else{
                    int nm = 0, ns = 0;
                    bool even = true, odd = true;
                    for(int k = 0; k < move[i][j].size(); k++){
                        nm += move[i][j][k].m;
                        ns += move[i][j][k].s;
                        if(move[i][j][k].d % 2 == 0){
                            odd = false;
                        }else{
                            even = false;
                        }
                    }
                    nm /= 5; ns /= move[i][j].size();
                    if(nm > 0){
                        if(even || odd){
                            for(int k = 0; k < 4; k++){
                                nFireball.push_back({i,j,nm,ns,same[k]});
                            }
                        }else{
                            for(int k = 0; k < 4; k++){
                                nFireball.push_back({i,j,nm,ns,nsame[k]});
                            }
                        }

                    }

                }
            }
        }

        fireball = nFireball;
    }

    int answer = 0;
    for(int i = 0; i < fireball.size(); i++){
        answer += fireball[i].m;
    }
    cout<<answer<<"\n";


    return 0;
}