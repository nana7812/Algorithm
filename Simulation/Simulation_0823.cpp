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

int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};
int R,C,M;
int Answer;
struct Shark{
    int r,c,s,d,z;
};
vector<Shark> shark[102][102];

bool change(int r, int c){
    return 0 < r && r <= R && 0 < c && c<= C;
}
int changeDir(int d){
    if(d == 1) return 2;
    if(d == 2) return 1;
    if(d == 3) return 4;
    if(d == 4) return 3;
}

int main(){
    cin>> R>>C>> M;
    for(int i = 0; i < M; i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        if(d == 1 || d == 2) s %= ((R-1)*2);
        if(d== 3 || d== 4) s%= ((C-1) *2);
        shark[r][c].push_back({r,c,s,d,z});
    }
    int idx = 0;
    while(++idx <=C){
        for(int i = 1; i <= R; i++){
            if(!shark[i][idx].empty()){
                Answer += shark[i][idx][0].z;
                shark[i][idx].pop_back();
                break;
            }
        }
        vector<Shark> newSharks[102][102];
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <=C; j++){
                if(shark[i][j].empty()) continue;
                Shark cur = shark[i][j][0];
                shark[i][j].pop_back();
                int &cr = cur.r;
                int &cc = cur.c;
                int cs = cur.s;
                int &cd = cur.d;
                int cz = cur.z;

                while(cs--){
                    int nr = cr+ dx[cd];
                    int nc = cc+ dy[cd];
                    if(0 >= nr || nr > R || 0 >= nc || nc > C){
                        cd = changeDir(cd);
                    }
                    cr += dx[cd];
                    cc += dy[cd];
                }
                if(!newSharks[cr][cc].empty()){
                    if(newSharks[cr][cc][0].z < cz){
                        newSharks[cr][cc].pop_back();
                        newSharks[cr][cc].push_back(cur);
                    }
                }else{
                    newSharks[cr][cc].push_back(cur);
                }
            }
        }
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                shark[i][j] = newSharks[i][j];
            }
        }
    }
    cout<<Answer<<"\n";
    return 0;
}
