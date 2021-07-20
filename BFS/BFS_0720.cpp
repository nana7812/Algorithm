#include <vector>
#include <queue>

using namespace std;

bool check[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int bfs(int x, int y, int m, int n,vector<vector<int>> picture){
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    sum++;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = qx+ dx[k];
            int ny = qy + dy[k];
            if(0<=nx && nx < m && 0 <= ny && ny < n){
                if(check[nx][ny] == false && picture[qx][qy] == picture[nx][ny]){
                    q.push({nx,ny});
                    check[nx][ny] = true;
                    sum++;
                }
            }
        }
    }
    return sum;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            check[i][j] = false;
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == false && picture[i][j] != 0){
                int maxSize = bfs(i,j,m,n,picture);
                if(maxSize > max_size_of_one_area){
                    max_size_of_one_area = maxSize;
                }
                 number_of_area++;
            }
        }
    }
        
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}