#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(vector<vector<int>> picture,int x, int y, vector<vector<bool>> &check){
    int cnt = 1;
    check[x][y] = true;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},picture[x][y]});
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0> nx || nx >= picture.size()|| 0 > ny || ny >= picture[0].size()) continue;
            if(check[nx][ny]) continue;
            if(picture[nx][ny] == qc){
                q.push({{nx,ny},picture[nx][ny]});
                cnt++;
                check[nx][ny] = true;
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> check(picture.size(),vector<bool>(picture[0].size(),false));

    for(int i = 0; i <picture.size(); i++){
        for(int j = 0; j < picture[i].size(); j++){
            if(check[i][j] == false && picture[i][j] != 0){
                number_of_area++;
                int oneArea = bfs(picture,i,j,check);
                if(max_size_of_one_area < oneArea){
                    max_size_of_one_area = oneArea;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}ㄴ