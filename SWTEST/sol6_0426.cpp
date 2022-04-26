#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int R,C,M;
int sharkNum[101][101];
struct Shark{
    int num;
    int r;
    int c;
    int s;
    int d;
    int z;
    bool live = false;
};

int changeDir(int d){
    if(d== 0) return 1;
    else if(d== 1) return 0;
    else if(d == 2) return 3;
    else if(d == 3) return 2;
}


int main() {
    cin>> R>> C>> M;
    //상어벡터
    vector<Shark> shark;
    for(int i = 0; i < M; i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        sharkNum[r-1][c-1] = i+1;
        shark.push_back({i+1,r-1,c-1,s,d-1,z,true});
    }

    if(M == 0){
        cout<<0<<"\n";
        return 0;
    }

    int answer = 0;
    for(int i = 0; i < C; i++){
        //i열에서 가장가까운 j행에 있는 상어 잡기
        for(int j = 0; j <R; j++){
            if(sharkNum[j][i] > 0){
                answer += shark[sharkNum[j][i]-1].z;
                shark[sharkNum[j][i]-1].live= false;
                sharkNum[j][i] = 0;
                break;
            }
        }


        //상어이동
        pair<int,int> move[R][C];
        for(int k = 0; k <shark.size(); k++){
            if(!shark[k].live) continue;
            sharkNum[shark[k].r][shark[k].c] = 0; //
            if(shark[k].d == 0 || shark[k].d == 1){
                shark[k].s = shark[k].s % (R*2 -2);
            }else if(shark[k].d == 2 || shark[k].d == 3){
                shark[k].s = shark[k].s % (C*2 -2);
            }
            int m = shark[k].s;
            int nx = shark[k].r; int ny = shark[k].c;
            //진짜 이동
            while(m--){
                nx += dx[shark[k].d];
                ny += dy[shark[k].d];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                    shark[k].d = changeDir(shark[k].d);
                    for(int t = 0; t < 2; t++){
                        nx += dx[shark[k].d];
                        ny += dy[shark[k].d];
                    }
                }
            }
            shark[k].r = nx; shark[k].c = ny;
            if(move[shark[k].r][shark[k].c].second < shark[k].z){
                shark[move[shark[k].r][shark[k].c].first-1].live = false;
                move[shark[k].r][shark[k].c] = {shark[k].num,shark[k].z};
            }else if(move[shark[k].r][shark[k].c].second > shark[k].z){
                shark[k].live = false;
            }
        }

        //이동 후 상태 다시 sharkNum에 업데이트
        for(int x = 0; x < R; x++){
            for(int y = 0; y < C; y++){
                if(move[x][y].first > 0){
                    sharkNum[x][y] = move[x][y].first;
                }
            }
        }

    }

    cout<<answer<<"\n";

    return 0;
}
