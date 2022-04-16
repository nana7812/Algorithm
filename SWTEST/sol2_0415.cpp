#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int a[201];
bool robot[201];

int IDX(int n){
    if(n == 0){
        return 2*N -1;
    }else{
        return n-1;
    }
}


int main() {
    cin >> N >> K;
    for(int i = 0; i < 2*N; i++){
        cin>>a[i];
    }

    int in = 0; int out = N-1;
    int turn = 1;
    while(true){
        //1.벨트 이동
        in = IDX(in); out = IDX(out);
        if(robot[out]) robot[out] = false;


        //2.로봇이동
        int idx1 = out;
        for(int i = 1; i < N; i++){
            int idx2 = IDX(idx1);
            if(robot[idx2] && !robot[idx1]  && a[idx1] != 0 ){
                robot[idx2] = false;
                robot[idx1] = true;
                a[idx1]--;
                if(a[idx1] == 0) K--;
            }
            idx1 = IDX(idx1);
        }
        
        if(robot[out]) robot[out] = false;

        //3.로봇 올리기
        if(a[in] > 0 && !robot[in]){
            robot[in] = true;
            a[in]--;
           if(a[in] == 0) K--;
        }



        //4.내구도 확인
        if(K <= 0) break;

        turn++;
    }

    cout<<turn<<"\n";
    return 0;
}
