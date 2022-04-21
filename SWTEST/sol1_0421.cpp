#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N;
int map[21][21];
vector<int> v[410];

struct Info{
    int like = 0;
    int empty = 0;
    int x = 0;
    int y = 0;
};

bool compare(Info a, Info b){
    if(a.like == b.like){
        if(a.empty == b.empty){
            if(a.x == b.x){
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.empty > b.empty;
    }
    return a.like > b.like;
}

int main() {

    cin>>N;
    int T = N*N;
    while(T--){
        //학생번호, 학생 선호도 입력받기
        int s;
        cin>>s;
        for(int i = 0; i < 4; i++){
            int a; cin>>a;
            v[s].push_back(a);
        }

        //학생위치 후보
        vector<Info> pos;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] != 0) continue;
                int e = 0, l = 0;
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(map[nx][ny] == 0) e++;
                    else{
                        for(int k = 0; k < v[s].size(); k++){
                            if(map[nx][ny] == v[s][k]){
                                l++;
                                break;
                            }
                        }
                    }
                }
                pos.push_back({l, e, i, j});
            }
        }

        //학생 위치 정하기
        sort(pos.begin(),pos.end(),compare);
        map[pos[0].x][pos[0].y] = s;

    }

    int answer = 0;
    //학생 만족도 계산
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int s = map[i][j]; int cnt = 0;
            for(int d = 0; d < 4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                for(int k = 0; k < v[s].size(); k++) {
                    if (map[nx][ny] == v[s][k]) {
                        cnt++;
                        break;
                    }
                }
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

