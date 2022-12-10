#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool ischeck(vector<string> place, int x, int y){
    vector<vector<bool>> c(5,vector<bool>(5,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    place[x][y] = 'O';
    c[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(place[qx][qy] == 'P'){
            return false;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
            if(c[nx][ny]) continue;
            if(place[nx][ny] == 'X') continue;
            if(qc +1 <= 2){
                if(place[nx][ny] == 'P'){
                    return false;
                }
                q.push({{nx,ny},qc+1});
                c[nx][ny] = true;
            }
        }
    }
    return true;
}
 
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++){
        bool flag = true;
        for(int j = 0; j < places[i].size(); j++){
            for(int k = 0; k < places[i][j].size(); k++){
                if(places[i][j][k] == 'P'){
                    flag = ischeck(places[i],j,k);
                    if(!flag){
                        break;
                    } 
                }
            }
            if(!flag) break;
        }
        if(flag){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    return answer;
}