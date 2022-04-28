#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct airCon{
    int num;
    int x;
    int y;
};

int R,C,K,W;
int space[25][25];
bool wall[25][25][25][25];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int wallX[2][3] = {{-1,0,1},{0,0,0}};
int wallY[2][3] = {{0,0,0},{-1,0,1}};
int windX[4][3] = {{-1,0,1},{-1,0,1},{-1,-1,-1},{1,1,1}};
int windY[4][3] = {{1,1,1},{-1,-1,-1},{-1,0,1},{-1,0,1}};

vector<airCon> airCons;
vector<pair<int,int>> check;

void turnON(int x, int y , int num){ //x,y 온풍기 위치임, num 1,2,3,4임
    vector<vector<bool>> c(R,vector<bool>(C,false));
    queue<pair<pair<int,int>,int>> q;
    int dir = num-1;
    c[x][y] = true;
    x += dx[dir]; y += dy[dir];
    space[x][y] += 5;
    c[x][y] = true;
    q.push({{x,y},5});
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qt = q.front().second;
        q.pop();
        if(qt <= 1) continue; //중단점 이렇게 함 지금 온도가 1이라면 다음은 없다
        for(int i = 0; i < 3; i++){
            int nx = qx + windX[dir][i];
            int ny = qy + windY[dir][i];
            if(0 > nx || nx >= R || 0 > ny || ny >=C) continue;
            if(c[nx][ny]) continue;
            if(i == 0 || i == 2){
                int wX = qx + wallX[dir/2][i];
                int wY = qy + wallY[dir/2][i];
                if(wall[qx][qy][wX][wY] || wall[wX][wY][nx][ny]) continue;
            }
            if(i == 1){
                if(wall[qx][qy][nx][ny]) continue;
            }
            space[nx][ny] += qt -1; //여기 온도 제대로 된건가 확인
            q.push({{nx,ny},qt-1});
            c[nx][ny] = true;
        }
    }

}

void adjust(vector<vector<int>> &temp,vector<vector<bool>> &c,int x, int y){
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(0 >nx || nx >= R || 0 > ny || ny >= C)continue;
        if(c[nx][ny]) continue;
        if(wall[x][y][nx][ny]) continue;
        if(abs(space[nx][ny]-space[x][y]) >= 4){
            int diff = abs(space[nx][ny]-space[x][y]);
            if(space[nx][ny] < space[x][y]){
                temp[x][y] -= diff/4;
                temp[nx][ny] += diff/4;
            }else if(space[nx][ny] > space[x][y]){
                temp[x][y] += diff/4;
                temp[nx][ny] -= diff/4;
            }
        }
    }
}


int main(){
    //입력, 초기화
    int chocolate = 0;
    cin>> R>> C>> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>space[i][j];
            if(1 <= space[i][j]){
                if(space[i][j] == 5){
                    check.push_back({i,j});
                }else{
                    airCons.push_back({space[i][j],i,j});
                }
                space[i][j] = 0;// 온푸익 위치에 따른건 어케할지 일단 고민.. ㅠㅠ
            }
        }
    }
    cin>> W;
    for(int i = 0; i < W; i++){
        int x,y,n;
        cin>>x>>y>>n;
        x--; y--;
        if(n == 0){
            wall[x-1][y][x][y] = true;
            wall[x][y][x-1][y] = true;
        }else{
            wall[x][y][x][y+1] = true;
            wall[x][y+1][x][y] = true;
        }
    }

    while(true) {
        //(1)온풍기에서 바람 나옴
        for (int i = 0; i < airCons.size(); i++) {
            turnON(airCons[i].x, airCons[i].y, airCons[i].num);
        }

        //(2)온도조절
        vector<vector<int>> temp(R, vector<int>(C, 0)); //동시진행 처리를 위한 임시 temp;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                temp[i][j] = space[i][j];
            }
        }
        vector<vector<bool>> c(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (space[i][j] > 0) {
                    adjust(temp, c, i, j);
                    c[i][j] = true;
                }
            }
        }
        for (int i = 0; i < R; i++) { //space에 동시진행 결과 채우기
            for (int j = 0; j < C; j++) {
                space[i][j] = temp[i][j];
            }
        }

        //(3) 바깥쪽 -1 감소
        for (int i = 0; i < C; i++) {
            if (space[0][i] > 0) space[0][i]--;
        }
        for (int i = 0; i < C; i++) {
            if (space[R - 1][i] > 0) space[R - 1][i]--;
        }
        for (int i = 1; i < R-1; i++) {
            if (space[i][0] > 0) space[i][0]--;
        }
        for (int i = 1; i < R-1; i++) {
            if (space[i][C - 1] > 0) space[i][C - 1]--;
        }

        //(4) 초콜릿섭취
        chocolate++;
        if (chocolate > 100) break;

        //(5) 특정 칸 온도체크
        bool flag = true;
        for (int i = 0; i < check.size(); i++) {
            if (space[check[i].first][check[i].second] < K) {
                flag = false;
                break;
            }
        }
        if (flag) break; // 조건 충족후 정료
    }

    //
//    for(int i = 0; i < R; i++) {
//        for(int j = 0; j < C; j++) {
//            cout << space[i][j] << " ";
//        }
//        cout<< "\n";
//    }
    //

    cout<<chocolate<<"\n";

}