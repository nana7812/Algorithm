#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int power[13][13];
int nutrition[13][13];
vector<int> tree[13][13];
int N,M,K;


int main(){

        //초가
        cin>>N>>M>>K;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>>power[i][j];
                nutrition[i][j] = 5;
            }
        }
        int x,y,z;
        for(int i = 0; i < M; i++){
            cin>>x>>y>>z;
            x--; y--;
            tree[x][y].push_back(z);
        }
        while(K--){
            vector<pair<int,int>> tree5;
            //봄_여름
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(tree[i][j].size() <= 0) continue;
                    sort(tree[i][j].begin(),tree[i][j].end());
                    int treeSize = tree[i][j].size();
                    for(int k = 0; k < treeSize; k++){
                        if(nutrition[i][j] >= tree[i][j][k]){
                            nutrition[i][j] -= tree[i][j][k];
                            tree[i][j][k]++;
                            if(tree[i][j][k] % 5 == 0){
                                tree5.push_back({i,j});
                            }
                        }else{
                            for(int l = treeSize-1; l>= k; l--){
                                nutrition[i][j] += tree[i][j][l]/2;
                                tree[i][j].pop_back();
                            }
                            break;
                        }
                    }
                }
            }
            //가을
            for(int i = 0; i < tree5.size(); i++){
                for(int k = 0; k < 8; k++){
                    int nx = tree5[i].first + dx[k];
                    int ny = tree5[i].second + dy[k];
                    if(0 <= nx && nx < N && 0 <= ny && ny < N){
                        tree[nx][ny].push_back(1);
                    }
                }
            }
            tree5.clear();
            //겨울
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    nutrition[i][j] += power[i][j];
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                answer += tree[i][j].size();
            }
        }
        cout<<answer<<"\n";
    

    return 0;
}