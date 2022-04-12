#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 987654321

int N;
int arr[21][21];
int mark[21][21];


void fill(int r, int c, int v){
    if(r < 0 || r > N-1 || c < 0 || c > N-1) return;
    if(mark[r][c] != 0) return;

    mark[r][c] = v;

    fill(r-1,c,v);
    fill(r+1,c,v);
    fill(r,c-1,v);
    fill(r,c+1,v);
}


int main() {

    cin>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>arr[i][j];
        }
    }

    int ret = INF;

    for(int x = 0; x <= N-3; x++){
        for(int y = 1; y <= N-2; y++){
            for(int d1 = 1; x+ d1 <= N-2 && y - d1 >= 0; d1++){
                for(int d2 = 1; x + d1 + d2 <= N-1 && y + d2 <= N-1; d2++){
                    memset(mark,0,sizeof(mark));
                    for(int i = 0; i <= d1; i++){
                        mark[x+i][y-i] = 5;
                        mark[x+d2+i][y+d2-i] = 5;
                    }
                    for(int i = 0; i <= d2; i++){
                        mark[x+i][y+i] = 5;
                        mark[x+d1+i][y-d1+i] = 5;
                    }

                    for(int r = x-1; r>= 0; r--){ //1번
                        mark[r][y] = 1;
                    }

                    for(int c = y+d2+1; c < N; c++){ //2번
                        mark[x+d2][c] = 2;
                    }

                    for(int c = y-d1-1; c >= 0; c--){ //3번
                        mark[x+d1][c] = 3;
                    }

                    for(int r = x+d1+d2+1; r < N; r++){ //4번
                        mark[r][y-d1+d2] = 4;
                    }

                    fill(0,0,1);
                    fill(0,N-1,2);
                    fill(N-1,0,3);
                    fill(N-1,N-1,4);

                    int people[6] = {0};
                    for(int r = 0; r <N; r++){
                        for(int c = 0; c < N; c++){
                            people[mark[r][c]] += arr[r][c];
                        }
                    }

                    people[5] += people[0];

                    int minP= INF,maxP= 0;
                    for(int i = 1; i <= 5; i++){
                        minP = min(minP,people[i]);
                        maxP = max(maxP,people[i]);
                    }

                    ret = min(ret,maxP - minP);

                }
            }
        }
    }

    cout<<ret<<"\n";

    return 0;
}