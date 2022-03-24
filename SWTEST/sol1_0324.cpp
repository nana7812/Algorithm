#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int R,C,T;
int x1,x2;
int a[51][51];

int main() {

    cin>> R>> C>> T;
    int flag = 0;
    for(int i= 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>a[i][j];
            if(a[i][j] == -1){
                if(flag == 0){
                    x1 = i;
                    flag++;
                }else{
                    x2 = i;
                }
            }
        }
    }
    while(T--){
        int temp[R][C];
        memset(temp,0,sizeof(temp));
        temp[x1][0] = temp[x2][0] = -1;
        //미세먼지 확산
        for(int i = 0; i < R; i++){
            for(int j= 0; j < C; j++){
                if(a[i][j] >= 1){
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                        if(a[nx][ny] == -1) continue;
                        temp[nx][ny] += a[i][j]/5;
                        cnt++;
                    }
                    temp[i][j] += a[i][j] - (a[i][j]/5) * cnt;
                }
            }
        }

        //memcpy(a,temp,sizeof(temp));
       // cout<<"전파"<<"\n";
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                a[i][j] = temp[i][j];
            }

        }

        //공기청정기
        //위쪽
        for(int i = x1-1; i > 0; i--){
            a[i][0] = a[i-1][0];
        }
        for(int i = 0; i < C-1; i++){
            a[0][i] = a[0][i+1];
        }
        for(int i = 0; i < x1; i++){
            a[i][C-1] = a[i+1][C-1];
        }
        for(int i = C-1; i > 1; i--){
            a[x1][i] = a[x1][i-1];
        }
        a[x1][1] = 0;
        //아래쪽
        for(int i = x2+1; i < R-1; i++){
            a[i][0] = a[i+1][0];
        }
        for(int i = 0; i < C-1; i++){
            a[R-1][i] = a[R-1][i+1];
        }
        for(int i = R-1; i > x2; i--){
            a[i][C-1] = a[i-1][C-1];
        }
        for(int i = C-1; i > 1; i--){
            a[x2][i] = a[x2][i-1];
        }
        a[x2][1] = 0;
//        cout<<"공청"<<" \n";
//        for(int i = 0; i < R; i++){
//        for(int j = 0; j < C; j++){
//            cout<<a[i][j]<<" ";
//            }
//            cout<<"\n";
//        }

    }

    int answer = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(a[i][j] >= 1){
                answer += a[i][j];
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}