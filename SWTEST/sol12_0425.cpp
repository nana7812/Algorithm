#include <iostream>
#include <vector>
using namespace std;

int t[4][8];

void rotate(vector<int> d){
    for(int i = 0; i < 4; i++){
        if(d[i] == -1){
            int temp = t[i][0];
            for(int j = 0; j <= 6; j++){
                t[i][j] = t[i][j+1];
            }
            t[i][7] = temp;

        }else if(d[i] == 1){
            int temp = t[i][7];
            for(int j = 7; j >=1; j--){
                t[i][j] = t[i][j-1];
            }
            t[i][0] = temp;
        }
    }
}

int main() {

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            char a; cin>> a;
            t[i][j] = a - '0';
        }
    }

    int T;
    cin >> T;
    while(T--){
        vector<int> d(4,0);
        int a,b;
        cin>> a>> b;
        a--;
        d[a] = b;

        //왼쪽
        for(int i = a; i >= 1; i--){
            if(t[i][6] != t[i-1][2]){
                d[i-1] = -d[i];
            }else{
                break;
            }
        }

        //오른쪽
        for(int i = a; i <= 2; i++){
            if(t[i][2] != t[i+1][6]){
                d[i+1] = -d[i];
            }else{
                break;
            }
        }

         rotate(d);
    }

    int answer = 0; int plus = 1;
    for(int i = 0; i < 4; i++){
        if(t[i][0] == 1){
            answer += plus;
        }
        plus *= 2;
    }

    cout<<answer<<"\n";

    return 0;
}