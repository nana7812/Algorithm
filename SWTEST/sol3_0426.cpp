#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};


int N,M,K;
int n[15][15];
vector<int> map[15][15];
int a[15][15];

int main() {

    cin>> N >> M>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
            n[i][j] = 5;
        }
    }
    for(int i = 0; i < M; i++){
        int x, y, z;
        cin >> x>> y>> z;
        map[x-1][y-1].push_back(z);
    }

    while(K--){
        vector<int> temp[15][15];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j].size() == 0) continue;
                int nutrition = n[i][j];
                int die = 0;
                sort(map[i][j].begin(),map[i][j].end());
                for(int k = 0; k < map[i][j].size(); k++){
                    int age = map[i][j][k];
                    if(nutrition - age >= 0){
                        nutrition -= age;
                        temp[i][j].push_back(age+1);
                    }else{
                        die += age/2;
                    }
                }
                n[i][j] = nutrition + die;
            }
        }


        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp[i][j].size() == 0) continue;
                for(int k = 0; k < temp[i][j].size(); k++){
                    int age = temp[i][j][k];
                    if(age % 5 == 0){
                        for(int d = 0; d < 8; d++){
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            temp[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                n[i][j] += a[i][j];
            }
        }


        //
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j] = temp[i][j];
            }
        }
    }


    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j].size() == 0) continue;
            answer += map[i][j].size();
        }
    }

    cout<<answer<<"\n";

    
    return 0;
}

