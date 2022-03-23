#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int N,M,K;
int nutrition[11][11];
int add[11][11];
vector<int> tree[11][11];

int main() {

    cin>> N>> M>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>add[i][j];
            nutrition[i][j] = 5;
        }
    }
    for(int i = 0; i < M; i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        tree[x][y].push_back(z);
    }

    while(K--){
        //봄
        vector<int> temp[11][11];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(tree[i][j].size() == 0) continue;
                sort(tree[i][j].begin(),tree[i][j].end());
                int die = 0;
                for(int k = 0; k < tree[i][j].size(); k++){
                    int age = tree[i][j][k];
                    if(nutrition[i][j] - age >= 0){
                      nutrition[i][j] -= age;
                      temp[i][j].push_back({age+1});
                    }else{
                        die += age/2;
                    }
                }
                //여름
                nutrition[i][j] += die;
            }
        }

        //복사
        for(int i = 0; i <N; i++){
            for(int j = 0; j < N; j++){
                tree[i][j] = temp[i][j];
            }
        }

        //가을
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N;j++){
                for(int k = 0; k < tree[i][j].size(); k++){
                    if(tree[i][j][k] % 5 == 0){
                        for(int d = 0; d < 8; d++){
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if(0> nx || nx >= N || 0 > ny || ny >= N) continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }

        //겨울
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                nutrition[i][j] += add[i][j];
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            answer += tree[i][j].size();
        }
    }
    cout<<answer<<" ";
    return 0;
}