#include <iostream>
#include <cstring>
using namespace std;

int N, M, T;
int a[55][55];

void rotate(int idx, int d, int k){
    if(d == 0){
        while(k--){
            int temp = a[idx][M-1];
            for(int i = M-1; i > 0; i--){
                a[idx][i] = a[idx][i-1];
            }
            a[idx][0] = temp;
        }
    }else if(d == 1){
        while(k--){
            int temp = a[idx][0];
            for(int i = 0; i < M-1; i++){
                a[idx][i] = a[idx][i+1];
            }
            a[idx][M-1] = temp;
        }
    }
}

int main() {

    //memset(a,0,sizeof(a));
    cin >> N>> M>> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
        }
    }

    while(T--){
        int x, d,k;
        cin>> x>> d>> k;

        //1.
        for(int i = 0; i < N; i++){
            if((i+1) % x == 0){
                rotate(i,d,k);
            }
        }


        //2. 2-1
        int temp[55][55];
       // memset(temp,0,sizeof(temp));
        memcpy(temp,a,sizeof(a));
        bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(a[i][j] == 0) continue;
                if(i == 0){
                    int idx1 = j-1; int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 >= M) idx2 = 0;
                    if(a[i][j] == a[i+1][j]){
                        temp[i][j] = 0;
                        temp[i+1][j] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }
                }else if(i == N-1){
                    int idx1 = j-1; int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 >= M) idx2 = 0;
                    if(a[i][j] == a[i-1][j]){
                        temp[i][j] = 0;
                        temp[i-1][j] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }
                }else{
                    int idx1 = j-1; int idx2 = j+1;
                    if(idx1 < 0) idx1 = M-1;
                    if(idx2 >= M) idx2 = 0;
                    if(a[i][j] == a[i-1][j]){
                        temp[i][j] = 0;
                        temp[i-1][j] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i+1][j]){
                        temp[i][j] = 0;
                        temp[i+1][j] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx1]){
                        temp[i][j] = 0;
                        temp[i][idx1] = 0;
                        flag = true;
                    }else if(a[i][j] == a[i][idx2]){
                        temp[i][j] = 0;
                        temp[i][idx2] = 0;
                        flag = true;
                    }

                }
            }
        }

        memcpy(a,temp,sizeof(temp));

        //2-2
        if(!flag){
            int sum = 0; int cnt = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(a[i][j] > 0){
                        cnt++;
                        sum += a[i][j];
                    }
                }
            }
            
            if(cnt > 0) {
                int avg = sum / cnt;
                if (sum % cnt == 0) {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) {
                            if (a[i][j] > 0) {
                                if (a[i][j] > avg) a[i][j]--;
                                else if (a[i][j] < avg) a[i][j]++;
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) {
                            if (a[i][j] > 0) {
                                if (a[i][j] > avg) a[i][j]--;
                                else if (a[i][j] <= avg) a[i][j]++;
                            }
                        }
                    }
                }
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