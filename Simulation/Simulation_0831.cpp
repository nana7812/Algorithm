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
#include <array>
using namespace std;

int N;
int m[21][21];

int diff(int x, int y, int d1, int d2){
    vector<int> p(5,0);

    for(int r = 1; r <= N; r++){
        for(int c = 1; c<= N; c++){
            //1번
            if(1<=r && r < x+ d1 && 1<= c && c <= y &&!(r >= x && c >= y-(r-x))){
                p[0] += m[r][c];
            }
            //2번
            else if(1 <= r && r <= x+d2 && y < c && c<= N && !(r >= x && c <= y+(r-x))){
                p[1] += m[r][c];
            }
            //3번
            else if(x+d1 <= r && r <= N && 1 <= c && c < y- d1+d2 && !(r <=x +d1 +d2 && c >= (y-d1+d2-(x+d1+d2-r)))){
                p[2] += m[r][c];
            }
            //4번
            else if(x+d2 < r && r <= N && y- d1+d2 <= c && c <= N && !(r <= x + d1+d2 && c <= (y-d1+d2+(x+d1+d2-r)))){
                p[3] += m[r][c];
            }else{
                p[4] += m[r][c];
            }
        }
    }

    sort(p.begin(),p.end());
    return p[4] - p[0];
}

int minDiff(){
    int res = 987654321;
    for(int x = 1; x<= N-2;x++){
        for(int y = 2; y <= N-1; y++){
            for(int d1 = 1; d1 <= y-1&& d1 <= N-x-1; d1++){
                for(int d2 = 1; d2 <= N- y && d2<= N-x-1;d2++){
                    res = min(res,diff(x,y,d1,d2));
                }
            }
        }
    }
    return res;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> m[i][j];
        }
    }

    cout << minDiff();
    return 0;

}