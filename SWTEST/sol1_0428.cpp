#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int sdx[] = {-1,0,1,0};
int sdy[] = {0,-1,0,1};

int M,S;
int sx,sy;
int smell[4][4];
vector<string> dic;
struct Fish{
    int r;
    int c;
    int dir;
};

vector<Fish> fish;

void makeDic(int cnt,string s){
    if(cnt >= 3){
        dic.push_back(s);
        return;
    }
    for(int i = 1; i <= 4; i++){
        char c = i + '0';
        makeDic(cnt+1,s+ c);
    }
}

bool compare(pair<int,string> a, pair<int,string> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}


int main() {

    //입력
    cin >> M >>S;
    for(int i = 0; i < M; i++){
        int fx, fy, d;
        cin >>fx >>fy >> d;
        fish.push_back({fx-1,fy-1,d-1});
    }
    cin >>sx>> sy;
    sx--; sy--;

    //사전만들기
    makeDic(0,"");

    int turn = 0;
    while(S--){
        //1.복제 물고기 만들기
        vector<Fish> nFish;
        nFish = fish;

        //2.물고기 이동
        vector<Fish> move[4][4];
        for(int i = 0; i <fish.size(); i++){
            int x = fish[i].r;
            int y = fish[i].c;
            int dir = fish[i].dir;
            for(int d = 0; d < 8; d++){ //여기 더 간단하게?
                int ndir = dir-d;
                if(ndir < 0) ndir += 8;
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
                if(smell[nx][ny] != 0 && smell[nx][ny] >= turn) continue;
                if(sx == nx && sy == ny) continue;
                x = nx; y = ny; dir = ndir;
                break;
            }
            move[x][y].push_back({x,y,dir});
        }
        
        //3.상어이동
        vector<pair<int,string>> sharkM;
        for(int i = 0; i < dic.size(); i++){
            int x = sx; int y = sy;
            int fishCnt = 0; bool flag = true;
            bool eat[4][4];
            memset(eat,false,sizeof(eat));
            for(int k = 0; k < 3; k++){
                int dir = dic[i][k] -'0';
                dir--;
                x += sdx[dir];
                y += sdy[dir];
                if(x < 0 || y < 0 || x >= 4 || y >= 4){
                    flag = false;
                    break;
                }

                if(!eat[x][y]){
                    fishCnt += move[x][y].size();
                    eat[x][y] = true;
                }
            }

            if(flag){
                sharkM.push_back({fishCnt,dic[i]});
            }

          }

        sort(sharkM.begin(),sharkM.end(),compare);
        for(int i = 0; i < sharkM[0].second.length(); i++){
            int dir = sharkM[0].second[i] -'0';
            dir--;
            sx += sdx[dir];
            sy += sdy[dir];
            if(move[sx][sy].size() > 0){ //냄새 뿌리기
                smell[sx][sy] = turn +2;
                move[sx][sy].clear();
            }
        }
        
        //복제마무리?
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(move[i][j].size() > 0){
                    for(int k = 0; k < move[i][j].size(); k++){
                        nFish.push_back(move[i][j][k]);
                    }
                }
            }
        }

        fish = nFish;

        turn++;
    }


    int answer = 0;
    answer = fish.size();
    cout<<answer<<"\n";


    return 0;
}