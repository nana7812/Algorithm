#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int T,N, M,K;
int a[101][101];
int d[101][101];
vector<string> com;

void make(int total, string s,int num,int cnt){
    if(cnt >= K){
        com.push_back(s);
        return;
    }
    for(int i = num; i< total;i++){
        char t = i +'0';
        make(total,s+t,i+1,cnt+1);
    }
    return;
}

int main() {


    cin>> T;
    int num = 0;
    while(T--){
        num++;
        cin>>N>> M>> K;
        vector<pair<int,int>> di;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>a[i][j];
                if(a[i][j] == 2){
                    di.push_back({i,j});
                }
            }
        }
        //조합만들기
        make(di.size(),"",0,0);

        //조합별로
        bool state = false; int answer = 987654321;
        for(int i = 0; i <com.size(); i++){
            memset(d,-1,sizeof(d));
            queue<pair<int,int>> q;

            //com[1] = '012' -> di[0] di[1] di[2] push
            for(int j = 0; j < com[i].size(); j++){
                int temp = com[i][j] -'0';
                q.push({di[temp].first,di[temp].second});
                d[di[temp].first][di[temp].second] = 0;
            }
            while(!q.empty()){
                int qx = q.front().first;
                int qy = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = qx+dx[k];
                    int ny = qy + dy[k];
                    if(0<= nx && nx < N && 0 <= ny && ny < M){
                        if(d[nx][ny] == -1 && a[nx][ny] != 1){
                            q.push({nx,ny});
                            d[nx][ny] = d[qx][qy] +1 ;
                        }
                    }
                }
            }


            int temp = 0; int check = false;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(d[i][j] > temp && a[i][j] == 0) {temp = d[i][j];}
                    if(d[i][j] == -1 && a[i][j] == 0){
                        check = true;
                    }
                }
            }

            if(check != true){
                answer = min(answer,temp);
                if(state == false){
                    state = true;
                }
            }
        }

        if(state == true){
           cout<<"#"<<num<<" "<<answer<<"\n";
        }else if(state == false){
           cout<<"#"<<num<<" "<<-1<<"\n";
        }


    }

    return 0;
}