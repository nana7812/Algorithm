#include <iostream>
#include <vector>
using namespace std;


int N, M, H;
int answer;
bool ladder[15][35];

bool check(){
    for(int i = 1; i <= N; i++){
        int cur = i;
        for(int j = 1; j <= H; j++){
            if(ladder[cur][j]){
                cur++;
            }else if(ladder[cur-1][j]){
                cur--;
            }
        }
        if(cur != i) return false;
    }
    return true;
}

void dfs(int idx, int cnt){
    if(cnt >= 4) return;

    if(check()){
        if(answer == -1 || answer > cnt){
            answer = cnt;
            return;
        }
    }

    for(int i = idx; i <= H; i++){
        for(int j = 1; j <= N; j++){
            if(ladder[j-1][i]) continue;
            if(ladder[j][i]) continue;
            if(ladder[j+1][i]) continue;

            if(answer == -1 || cnt+1 < answer) {
                ladder[j][i] = true;
                dfs(i,cnt + 1);
                ladder[j][i] = false;
            }
        }
    }
}

int main() {
    cin >> N>> M >> H;
    for(int i = 0; i < M; i++){
        int a,b;
        cin>> a>> b;
        ladder[b][a] = true;
    }

    answer = -1;
    dfs(1,0);

    cout<<answer<<"\n";

    return 0;
}