#include <iostream>

using namespace std;

int N, K;
int a[210];
bool robot[210];

int changeIdx(int n){
    if(n-1 < 0) return 2*N-1;
    return n-1;
}

int main() {

    cin >> N>> K;
    for(int i = 0; i < 2* N; i++){
        cin>>a[i];
    }

    int in = 0, out = N-1;
    int turn = 1;
    while(true){
        //1.
        in = changeIdx(in); out = changeIdx(out);
        if(robot[out]){
            robot[out] = false;
        }

        //2.
        int idx1 = out;
        for(int i = 1; i < N; i++){
            int idx2 = changeIdx(idx1);
            if(robot[idx2] && !robot[idx1] && a[idx1] != 0){
                robot[idx2] = false;
                robot[idx1] = true;
                a[idx1]--;
            }
            idx1 = changeIdx(idx1);
        }
        if(robot[out]){
            robot[out] = false;
        }

        //3.
        if(a[in] > 0 &&!robot[in]){
            robot[in] = true;
            a[in]--;
        }

        //4.
        int cnt = 0; bool flag = false;
        for(int i = 0; i < 2*N; i++){
            if(a[i] == 0){
                cnt++;
                if(cnt == K){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;

        turn++;
    }

    cout<<turn<<"\n";

    return 0;
}