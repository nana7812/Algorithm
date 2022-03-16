#include <vector>
#include <iostream>
#include <map>
using namespace std;

void rotate(vector<vector<int>> &v,int n, int c){
    if(c == 1){
        int temp = v[n][7];
        for(int i = 7; i > 0; i--){
            v[n][i] = v[n][i-1];
        }
        v[n][0] = temp;
    }else{
        int temp = v[n][0];
        for(int i = 0; i < 7; i++){
            v[n][i] = v[n][i+1];
        }
        v[n][7] = temp;
    }
}


int main(){

    vector<vector<int>> v(4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            char n;
            cin>> n;
            v[i].push_back(n - '0');
        }
    }

    int k;
    cin>> k;
    while(k--){
        int cur; int dir;
        cin>>cur>>dir;
        cur--;

        vector<int> d(4,0);
        d[cur] = dir;

        //cur 기준 모든 왼쪽 확인
        for(int i = cur; i > 0; i--){
            if(v[i][6] == v[i-1][2]) break;
            d[i-1] = -d[i];
        }
        //cur 기준 모든 오른쪽 확인
        for(int i = cur; i < 3; i++){
            if(v[i][2] == v[i+1][6]) break;
            d[i+1] = -d[i];
        }

        for(int i = 0; i < 4; i++){
            if(d[i] != 0){
                rotate(v,i,d[i]);
            }
        }

    }

    int answer = 0; int s = 1;
    for(int i = 0; i < 4; i++){
        if(v[i][0] == 1){
            answer += s;
        }
        s *= 2;
    }

    cout<<answer<<"\n";

    return 0;
}