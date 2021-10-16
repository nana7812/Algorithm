#include<iostream>
#include<vector>
using namespace std;

int N,H;
int answer;
int ladder[35][15];

//bool go(int x, int y){
//    int nx = x;
//    int ny = y;
//    while(nx != H){
//        if(ladder[nx][ny] == 1){
//            ny += 1;
//        }else if(ladder[nx][ny]== 2){
//            ny -= 1;
//        }
//        nx +=1;
//    }
//    return ny == y;
//}
int start(int c){
    int r = 1;
    while(r<= H){
        if(ladder[r][c] == 1){
            c +=1;
        }else if(ladder[r][c] == 2){
            c -= 1;
        }
        r+=1;
    }
    return c;
}

bool go(){
    for(int i = 1; i <= N; i++){
        int res = start(i);
        if(res != i) return false;
    }
    return true;
}
//void make(int x, int y, int cnt){
//    ladder[x][y] = 2;
//    ladder[x][y+1] = 1;
//    if(cnt > 2){
//        return;
//    }
//
//    bool finish = true;
//    for(int i = 1; i <= N; i++){
//        if(!go(1,i)){
//            finish = false;
//            break;
//        }
//    }
//
//    if(finish){
//        if(answer == -1 || answer > cnt+1)  answer = cnt+1;
//        return;
//    }else{
//        for(int i = x; i <= H; i++){
//            for(int j = 1; j <= N-1; j++){
//                if(i == x && j < y)continue;
//                if(ladder[i][j] != 1 && ladder[i][j+1] != 2 && ladder[i][j] != 2 && ladder[i][j+1] != 1 ){
//                    make(i,j,cnt+1);
//                    ladder[i][j] = 0;
//                    ladder[i][j+1] = 0;
//                }
//            }
//        }
//    }
//
//}

int main(){
    int T;
    cin>> T;
    while(T--){
        answer = -1;
        int M;
        cin>> N>> M>> H;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= H; j++){
                ladder[j][i] = 0;
            }
        }
        for(int i = 0; i < M; i++){
            int a,b;
            cin>>a>>b;
            ladder[a][b] = 1;
            ladder[a][b+1] = 2;
        }
        vector<pair<int,int>> temp;
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= N-1; j++){
                if(ladder[i][j] != 0) continue;
                if(ladder[i][j+1] != 0) continue;
                temp.push_back({i,j});
            }
        }

        if(go()){
            cout<<0<<"\n";
            return 0;
        }
            int tempSize = temp.size();
            for(int i = 0; i < tempSize; i++){
                int x = temp[i].first;
                int y = temp[i].second;
                if(ladder[x][y] != 0 || ladder[x][y+1] != 0) continue;
                ladder[x][y] = 1;
                ladder[x][y+1] = 2;
                if(go()){
                    if(answer == -1 || answer > 1){
                        answer = 1;
                    }
                }
                for(int j = i+1; j <tempSize; j++){
                    int x2 = temp[j].first;
                    int y2 = temp[j].second;
                    if(ladder[x2][y2] != 0 || ladder[x2][y2+1] != 0) continue;
                    ladder[x2][y2] = 1;
                    ladder[x2][y2+1] = 2;
                   if(go()){
                       if(answer == -1 || answer > 2){
                           answer = 2;
                       }
                   }
                    for(int l = j+1; l <tempSize; l++){
                        int x3 = temp[l].first;
                        int y3 = temp[l].second;
                        if(ladder[x3][y3] != 0 || ladder[x3][y3+1] != 0) continue;
                        ladder[x3][y3] = 1;
                        ladder[x3][y3+1] = 2;
                        if(go()){
                            if(answer == -1 || answer > 3){
                                answer = 3;
                            }
                        }
                        ladder[x3][y3] = 0;
                        ladder[x3][y3+1] = 0;
                    }
                    ladder[x2][y2] = 0;
                    ladder[x2][y2+1] = 0;
                }
                ladder[x][y] = 0;
                ladder[x][y+1] = 0;
            }

        cout<<answer<<"\n";
    }
    return 0;
}