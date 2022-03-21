#include <string>
#include <vector>
#include <iostream>


using namespace std;

bool a[101][101];

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int main() {
    int N;
    cin>> N;
    while(N--){
        int x,y,d,g;
        cin>>y>>x>>d>>g;
        vector<int> dir;
        dir.push_back(d);
        for(int i = 1; i < pow(2,g); i *= 2){
            for(int j = i-1; j >=0; j--){
                dir.push_back((dir[j]+1)%4);
            }
        }

        a[x][y] = true;
        for(int i = 0; i < dir.size(); i++){
            x += dx[dir[i]];
            y += dy[dir[i]];
            a[x][y] = true;
        }
    }

    int answer = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]) answer++;
        }
    }

    cout<<answer<<"\n";

    return 0;
}