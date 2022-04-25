#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool a[105][105];

int main() {

    int N;
    cin >> N;
    while(N--){
        int x,y,d,g;
        cin >>y>> x>> d>> g;
        int n = pow(2,g);
        vector<int> v(n);
        v[0] = d;
        for(int i = 1; i <= g; i++){
            int gg = pow(2,i);
            for(int j = 0; j < gg/2; j++){
                v[gg/2 + j] = (v[gg/2 -1 - j] +1) % 4;
            }
        }

        a[x][y] = true;
        for(int i = 0; i < v.size(); i++){
            x += dx[v[i]];
            y += dy[v[i]];
            a[x][y] = true;
        }

    }

    int answer = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1])
                answer++;
        }
    }

    cout<<answer<<"\n";

    return 0;
}
