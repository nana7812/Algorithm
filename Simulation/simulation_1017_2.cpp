#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    int TC;
    cin>> TC;
    while(TC--){
        int R,C,T;
        int x1,y1,x2,y2;
        cin>>R>>C>>T;
        vector<vector<int>> a(R,vector<int>(C));
        //입력
        int cnt = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin>>a[i][j];
                if(a[i][j] == -1){
                    if(cnt == 0){
                        x1 = i;
                        y1 = j;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                    cnt++;
                    a[i][j] = 0;
                }
            }
        }
        //실행
        while(T--){
            vector<vector<int>> temp(R,vector<int>(C,0));
            //미세먼지 확산
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(a[i][j] > 0){ //미세먼지 존재
                        int spreadCnt = 0;
                        int spreadDust = a[i][j]/5;
                        for(int k = 0; k < 4; k++){
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
                            if((nx == x1 && ny == y1) || (nx == x2 && ny == y2)) continue;
                            temp[nx][ny] += spreadDust;
                            spreadCnt++;
                        }
                        temp[i][j] += a[i][j] - (spreadDust*spreadCnt);
                    }
                }
            }
            //임시
//            cout<<"확산"<<"\n";
//            for(int i = 0; i < R; i++){
//                for(int j = 0; j < C; j++){
//                    cout<<temp[i][j]<<" ";
//                }
//                cout<<"\n";
//            }
            //공기청정기 가동
            //위쪽 공기청정기
            int temp1 = temp[x1][C-1];
            for(int i = C-1; i >= 1; i--){
                temp[x1][i] = temp[x1][i-1];
            }
            int temp2 = temp[0][C-1];
            for(int i = 0; i < x1-1; i++){
                temp[i][C-1] = temp[i+1][C-1];
            }
            temp[x1-1][C-1] = temp1;
            int temp3 = temp[0][0];
            for(int i = 0; i < C-2; i++){
                temp[0][i] = temp[0][i+1];
            }
            temp[0][C-2] = temp2;
            for(int i = x1-1; i >=2; i--){
                temp[i][0] = temp[i-1][0];
            }
            temp[1][0] = temp3;
            //아래쪽 공기청정기
            temp1 = temp[x2][C-1];
            for(int i = C-1; i >=1 ; i--){
                temp[x2][i] = temp[x2][i-1];
            }
            temp2 = temp[R-1][C-1];
            for(int i = R-1; i > x2+1; i--){
                temp[i][C-1] = temp[i-1][C-1];
            }
            temp[x2+1][C-1] = temp1;
            temp3 = temp[R-1][0];
            for(int i = 0; i < C-2; i++){
                temp[R-1][i] = temp[R-1][i+1];
            }
            temp[R-1][C-2] = temp2;
            for(int i = x2+1; i < R - 2; i++){
                temp[i][0] = temp[i+1][0];
            }
            temp[R-2][0] = temp3;
            //temp a에 복사
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    a[i][j] = temp[i][j];
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(a[i][j] > 0){
                    answer += a[i][j];
                }
            }
        }
        cout<<answer<<"\n";
    }

    return 0;
}