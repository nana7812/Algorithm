#include <iostream>
using namespace std;

int N, M, T;
int X,D,K;
int a[51][51];
int t[51][51];



int main(){
    cin>> N >> M >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
        }
    }
    bool flag;
    while(T--){
        cin>>X>>D>>K;
        for(int i = 0; i < N; i++){
            //배수인 원판
            if((i+1)%X == 0){
                if(D == 0){
                    for(int r = 0; r < K; r++) {
                        int temp = a[i][M - 1];
                        for (int j = M - 1; j >= 1; j--) {
                            a[i][j] = a[i][j - 1];
                        }
                        a[i][0] = temp;
                    }
                }else if(D == 1){
                    for(int r = 0; r < K; r++) {
                        int temp = a[i][0];
                        for (int j = 0; j < M - 1; j++) {
                            a[i][j] = a[i][j + 1];
                        }
                        a[i][M - 1] = temp;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                t[i][j] = a[i][j];
            }
        }

        //원판에 수가 존재 하는 지 확인
       flag = false;
        //안에서
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(t[i][j] == 0) continue;
                if(i == 0){
                    int idx1 = j -1;
                    int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 == M) idx2 = 0;
                    if(a[i][j] == a[i][idx1]){
                        t[i][j] = 0;
                        t[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        t[i][j] = 0;
                        t[i][idx2] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i+1][j]){
                        t[i][j] = 0;
                        t[i+1][j] = 0;
                        flag = true;
                    }
;                }else if(i == N-1){
                    int idx1 = j -1;
                    int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 == M) idx2 = 0;
                    if(a[i][j] == a[i][idx1]){
                        t[i][j] = 0;
                        t[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        t[i][j] = 0;
                        t[i][idx2] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i-1][j]){
                        t[i][j] = 0;
                        t[i-1][j] = 0;
                        flag = true;
                    }
                }else{
                    int idx1 = j -1;
                    int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 == M) idx2 = 0;
                    if(a[i][j] == a[i][idx1]){
                        t[i][j] = 0;
                        t[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        t[i][j] = 0;
                        t[i][idx2] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i+1][j]){
                        t[i][j] = 0;
                        t[i+1][j] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i-1][j]){
                        t[i][j] = 0;
                        t[i-1][j] = 0;
                        flag = true;
                    }
                }
            }
        }
        
        if(!flag){
        //평균 구하기
        int average = 0; int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j =0; j < M; j++){
                if(t[i][j] > 0){
                    cnt++;
                }
                average += t[i][j];
            }
        }
        //액션
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(t[i][j] == 0) continue;
                    if(average%cnt == 0){
                        if(t[i][j] >average/cnt){
                            t[i][j]--;
                        }else if(t[i][j] < average/cnt){
                            t[i][j]++;
                        }
                    }else{
                        if(t[i][j] >average/cnt){
                            t[i][j]--;
                        }else if(t[i][j] <= average/cnt){
                            t[i][j]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i <N; i++){
            for(int j = 0; j < M; j++){
                a[i][j] = t[i][j];
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            answer += a[i][j];
        }
    }
    cout<<answer<<"\n";
    return 0;
}