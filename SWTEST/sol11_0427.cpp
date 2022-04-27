#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N;
int map[25][25];
vector<int> v[410];
struct Info{
    int friends = 0;
    int empty = 0;
    int x = 0;
    int y = 0;
};


bool compare(Info a, Info b){
    if(a.friends == b.friends){
        if(a.empty == b.empty){
            if(a.x == b.x){
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.empty > b.empty;
    }
    return a.friends > b.friends;
}

int main() {
    cin >> N;
    int T = N*N;
    while(T--){
        int s;
        cin>> s;
        for(int i = 0; i < 4; i++){
            int b;
            cin>> b;
            v[s].push_back(b);
        }
        vector<Info> pos;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] != 0) continue;
                int empty = 0; int friends = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(map[nx][ny] == 0){
                        empty++;
                    }else{
                        auto itr = find(v[s].begin(),v[s].end(),map[nx][ny]);
                        if(itr != v[s].end()) friends++;
                    }
                }
                pos.push_back({friends,empty,i,j});
            }
        }

        sort(pos.begin(),pos.end(),compare);
        map[pos[0].x][pos[0].y] = s;
    }





    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int s = map[i][j];
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                auto itr = find(v[s].begin(),v[s].end(),map[nx][ny]);
                if(itr != v[s].end()) cnt++;
            }
            if(cnt == 1) answer += 1;
            else if(cnt == 2) answer += 10;
            else if(cnt == 3) answer += 100;
            else if(cnt == 4) answer += 1000;
        }
    }

    cout<<answer<<"\n";


    return 0;
}
