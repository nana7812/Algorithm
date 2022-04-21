#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};

int R,C,M;
int answer;
struct Shark{
    int r,c,s,d,z;
};
vector<Shark> shark[102][102];

bool change(int r, int c){
    return 0 < r && r <= R  && 0 < c && c <= C;
}


int changeDir(int d){
    if(d== 1) return 2;
    if(d== 2) return 1;
    if(d == 3) return 4;
    if(d == 4) return 3;
}


int main() {
    cin >> R >> C >> M;
    //상어벡터
    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin>> r >> c >> s >> d >> z;

        if(d == 1 || d == 2) s  %=  ((R - 1) * 2);
        if(d == 3 || d == 4) s  %=  ((C - 1) * 2);
        shark[r][c].push_back({r, c, s, d, z});
    }


    for(int idx = 1; idx <= C; idx++){
        //i열에서 가장가까운 j행에 있는 상어 잡기
        for(int j = 1; j <= R; j++){
            if(!shark[j][idx].empty()){
                answer += shark[j][idx][0].z;
                shark[j][idx].pop_back();
                break;
            }
        }

            vector<Shark> nShark[102][102];
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    if (shark[i][j].empty()) continue;
                    Shark cur = shark[i][j][0];
                    shark[i][j].pop_back();
                    int &cr = cur.r;
                    int &cc = cur.c;
                    int cs = cur.s;
                    int &cd = cur.d;
                    int cz = cur.z;
                    while(cs--){
                        int nr = cr + dx[cd];
                        int nc = cc + dy[cd];
                        if(!change(nr,nc)) {
                            cd = changeDir(cd);
                        }
                        cr += dx[cd];
                        cc += dy[cd];
                    }
                    if(!nShark[cr][cc].empty()) {
                        if(nShark[cr][cc][0].z < cz) {
                            nShark[cr][cc].pop_back();
                            nShark[cr][cc].push_back(cur);
                        }
                    }else{
                        nShark[cr][cc].push_back(cur);
                    }
                }
            }

            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    shark[i][j] = nShark[i][j];
                }
            }

        }
        cout << answer << "\n";
        return 0;

}