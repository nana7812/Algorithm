#include <iostream>
using namespace std;

int dice[10];
int pos[4];
int map[35];
int change[35];
bool check[35];
int score[35];

int answer = 0;

void dfs(int cnt, int sum){
    if(cnt == 10){
        if(sum > answer){
            answer = sum;
        }
        return;
    }

    for(int i = 0; i < 4; i++){ //말
        int prev = pos[i]; //말의 위치
        int now = prev;
        int move = dice[cnt];

        if(change[now] > 0){
            now = change[now];
            move--;
        }

        while(move--){
            now = map[now];
        }

        if(now != 21 && check[now]) continue;

        check[prev] = false;
        check[now] = true;
        pos[i] = now;

        dfs(cnt+1, sum + score[now]);

        pos[i] = prev;//원래 위치로 되돌려 놓기
        check[prev] = true;
        check[now] = false;
    }
}

int main(){

    for(int i = 0; i < 21; i++) map[i] = i+1;
    map[21] = 21;
    for(int i = 22; i < 27; i++) map[i] = i+1;
    map[27] = 20; map[28] = 29; map[29] = 30; map[30] = 25;
    map[31] = 32; map[32] = 25;

    change[5] = 22; change[10] = 31; change[15] = 28;
    change[25] = 26;//?

    for(int i = 0; i < 21; i++) score[i] = 2 * i;
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26;
    score[31] = 22; score[32] = 24;

    for(int i = 0; i < 10; i++){
        cin >> dice[i];
    }

    dfs(0,0);

    cout<<answer<<"\n";

    return 0;
}