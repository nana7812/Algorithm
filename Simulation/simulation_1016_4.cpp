#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin>> N;
        vector<vector<bool>> c(105,vector<bool>(105));
        while(N--){
            int x,y,d,g;
            cin>>x>>y>>d>>g;
            //방향 설정
            vector<int> v(pow(2,g));
            v[0] = d;
            for(int i = 1; i <= g; i++){
                int cur = pow(2,i-1);
                for(int j = 0; j < cur; j++){
                    v[cur+j] = (v[cur-1-j]+1)%4;
                }
            }
            //방향확인
//            for(int i = 0; i < v.size(); i++){
//                cout<<v[i]<<" ";
//            }
//            cout<<"\n";
            //좌표 표시
            c[y][x] = true;
            for(int i = 0; i < v.size(); i++){
                x += dx[v[i]];
                y += dy[v[i]];
                if(!c[y][x]){
                    c[y][x] = true;
                }
            }
        }
        //네 꼭짓점
        int answer = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if(c[i][j] && c[i][j+1] && c[i+1][j] && c[i+1][j+1]){
                    answer++;
                }
            }
        }
        cout<<answer<<"\n";
    }

    return 0;
}