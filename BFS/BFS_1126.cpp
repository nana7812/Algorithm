#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool bfs(vector<string> places,int x, int y){
    vector<vector<bool>> c(5,vector<bool>(5,false));
    c[x][y] = true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt == 2) continue; //!!!cnt 2면 이제 끝
        
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= 5 || 0 > ny || ny >= 5 ) continue; //범위!!
            if(c[nx][ny]) continue;
            if(places[nx][ny] == 'X') continue;
            if(places[nx][ny] == 'O'){
                q.push({{nx,ny},cnt+1});
                c[nx][ny] = true;
            }else if(places[nx][ny] == 'P'){
                 return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k = 0; k < places.size(); k++){
        bool flag = true;
        for(int i = 0; i <places[k].size(); i++){
            for(int j = 0; j <places[k][i].size(); j++){
                if(places[k][i][j] == 'P'){
                    if(!bfs(places[k],i,j)){
                        flag = false;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        } 
    }
    return answer;
}