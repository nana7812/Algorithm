#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int R,C,T;
int a[55][55];

int main() {

    cin >> R>>C>>T;
    int x1,x2; int cnt = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>a[i][j];
            if(a[i][j] == -1 ){
                if(cnt == 0){
                    x1 = i;
                    cnt++;
                }else{
                    x2 = i;
                }
            }
        }
    }

    while(T--){
        //미세먼지 확산
        int temp[55][55];
        memcpy(temp,a,sizeof(a));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(a[i][j] > 0){
                    int spread = a[i][j] / 5;
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                        if(a[nx][ny] == -1) continue;
                        temp[nx][ny] += spread;
                        cnt++;
                    }
                    temp[i][j] -= spread*cnt;
                }
            }
        }

        //
        memcpy(a,temp,sizeof(temp));
        
        //미세먼지 작동
        //위쪽
        int temp1 = a[x1][C-1];
        for(int i = C-1; i >= 2; i--){
            a[x1][i] = a[x1][i-1];
        }
        int temp2 = a[0][C-1];
        for(int i = 0; i <= x1-2; i++){
            a[i][C-1] = a[i+1][C-1];
        }
        a[x1-1][C-1] = temp1;
        int temp3 = a[0][0];
        for(int i = 0; i < C-2; i++){
            a[0][i] = a[0][i+1];
        }
        a[0][C-2] = temp2;
        for(int i = x1-1; i >=1; i--){
            a[i][0] = a[i-1][0];
        }
        a[1][0] = temp3;
        a[x1][1] = 0;
        //아래쪽
        temp1 = a[x2][C-1];
        for(int i = C-1; i >=2; i--){
            a[x2][i] = a[x2][i-1];
        }
        temp2 = a[R-1][C-1];
        for(int i = R-1; i >= x2+2; i--){
            a[i][C-1] = a[i-1][C-1];
        }
        a[x2+1][C-1] = temp1;
        temp3 = a[R-1][0];
        for(int i = 0; i < C-2; i++){
            a[R-1][i] = a[R-1][i+1];
        }
        a[R-1][C-2] = temp2;
        for(int i = x2+1; i < R-2; i++){
            a[i][0] = a[i+1][0];
        }
        a[R-2][0] = temp3;
        a[x2][1] = 0;

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


    return 0;
}