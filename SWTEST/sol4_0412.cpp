#include <iostream>
#include <vector>

using namespace std;

int N, M,T;
int map[51][51];


void rotate(int i,int d){
    if(d == 0){
        int temp = map[i][M-1];
        for(int j = M-1; j >=1; j--){
            map[i][j] = map[i][j-1];
        }
        map[i][0] = temp;

    }else if(d == 1){
        int temp = map[i][0];
        for(int j = 0; j <=M-2; j++){
            map[i][j] = map[i][j+1];
        }
        map[i][M-1] = temp;
    }
}


int main() {

    cin>> N >> M>> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
        }
    }
    while(T--){
        int x,d,k;
        cin>> x>> d>> k;

        //회전
        for(int i = 0; i < N; i++){
            if((i+1) % x != 0) continue;
            for(int j = 0; j < k; j++){
                rotate(i,d);
            }
        }

        int temp[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                temp[i][j] = map[i][j];
            }
        }

        bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(temp[i][j] == 0) continue;
                if(i == 0){
                    int idx1 = j-1; int idx2 = j+1;
                    if(j == 0) idx1 = M-1;
                    if(j == M-1) idx2 = 0;
                    if(map[i][j] == map[i+1][j]){
                        temp[i][j] = 0;
                        temp[i+1][j] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }
                }else if(i == N-1){
                    int idx1 = j-1; int idx2 = j+1;
                    if(j == 0) idx1 = M-1;
                    if(j == M-1) idx2 = 0;
                    if(map[i][j] == map[i-1][j]){
                        temp[i][j] = 0;
                        temp[i-1][j] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }
                }else{
                    int idx1 = j-1; int idx2 = j+1;
                    if(j == 0) idx1 = M-1;
                    if(j == M-1) idx2 = 0;
                    if(map[i][j] == map[i-1][j]){
                        temp[i][j] = 0;
                        temp[i-1][j] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i+1][j]){
                        temp[i][j] = 0;
                        temp[i+1][j] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(map[i][j] == map[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }
                }
            }
        }

        if(!flag){
            //평균구하기
            int cnt = 0; int sum = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(temp[i][j] > 0){
                        cnt++;
                        sum += temp[i][j];
                    }
                }
            }
            
            if(cnt > 0){
                if(sum%cnt == 0){
                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < M; j++){
                            if(temp[i][j] == 0) continue;
                            if(temp[i][j] > sum/cnt) temp[i][j]--;
                            else if(temp[i][j] < sum/cnt) temp[i][j]++;
                        }
                    }
                }else{
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) {
                            if (temp[i][j] == 0) continue;
                            if (temp[i][j] > sum / cnt) temp[i][j]--;
                            else temp[i][j]++;
                        }
                    }

                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = temp[i][j];
            }
        }
        
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            answer += map[i][j];
        }
    }

    cout<<answer<<"\n";


    return 0;
}