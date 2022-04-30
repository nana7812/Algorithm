#include <iostream>
using namespace std;

bool block[15][15];

int main(){
    int N;
    cin >> N;

    int answer = 0;
    while(N--){
        int t,xx,yy;
        cin >>t >>xx >> yy;
        //1.
        int x,y;
        //빨강에서 블록 떨어짐
        //초록 먼저 하자
        x = xx, y = yy;
        if(t == 1){
            while(!block[x][y] &&(!block[x+1][y] && x+1 < 10)){
                x += 1;
            }
            block[x][y] = true;
        }else if(t == 2){
            while(!block[x][y] &&(!block[x+1][y] && x+1 < 10)){
                if(!block[x][y+1] &&(!block[x+1][y+1] && x+1 < 10)){
                    x += 1;
                }else{
                    break;
                }
            }
            block[x][y] = true;
            block[x][y+1] = true;
        }else if(t == 3){
            x++;
            while(!block[x][y] &&(!block[x+1][y] && x+1 < 10)){
                x += 1;
            }
            block[x][y] = true;
            block[x-1][y] = true;
        }
        //파랑
        x = xx, y = yy;
        if(t == 1){
            while(!block[x][y] &&(!block[x][y+1] && y+1 < 10)){
                y += 1;
            }
            block[x][y] = true;
        }else if(t == 2){
            y++;
            while(!block[x][y] &&(!block[x][y+1] && y+1 < 10)){
                y += 1;
            }
            block[x][y] = true;
            block[x][y-1] = true;
        }else if(t == 3){
            while(!block[x][y] &&(!block[x][y+1] && y+1 < 10)){
                if(!block[x+1][y] &&(!block[x+1][y+1] && y+1 < 10)){
                    y += 1;
                }else{
                    break;
                }
            }
            block[x][y] = true;
            block[x+1][y] = true;
        }


        //2.
        //초록
        while(true){
            bool green = false; int gIdx = 0;
            for(int i = 9; i >= 6; i--){
                bool flag = true;
                for(int j = 0; j < 4; j++){
                    if(!block[i][j]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    answer++;
                    gIdx = i;
                    green = true;
                    break;
                }
            }

            if(green){
                for(int idx = gIdx-1; idx >= 4; idx--){
                    for(int j = 0; j < 4; j++){
                        block[idx+1][j] = block[idx][j];
                        block[idx][j] = false;
                    }
                }
            }

            if(!green) break;
        }

        //파랑
        while(true){
            bool blue = false; int bIdx = 0;
            for(int i = 9; i >= 6; i--){
                bool flag = true;
                for(int j = 0; j < 4; j++){
                    if(!block[j][i]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    answer++;
                    bIdx = i;
                    blue = true;
                    break;
                }
            }

            for(int idx= bIdx-1; idx >= 4; idx--){
                for(int j = 0; j < 4; j++){
                    block[j][idx+1] = block[j][idx];
                    block[j][idx] = false;
                }
            }
            if(!blue) break;
        }


        //3.
        //연한 초록칸에 있으면
        int gCnt = 0;
        for(int i = 4; i < 6; i++){
            for(int j = 0; j < 4; j++){
                if(block[i][j]){
                    gCnt++;
                    break;
                }
            }
        }
        //내리기
        while(gCnt--){
            for(int i = 8; i >= 4; i--){
                for(int j = 0; j < 4; j++){
                    block[i+1][j] = block[i][j];
                    block[i][j] = false;
                }
            }
        }

        //연한 파란칸
        int bCnt = 0;
        for(int i = 4; i < 6; i++){
            for(int j = 0; j < 4; j++){
                if(block[j][i]){
                    bCnt++;
                    break;
                }
            }
        }
        while(bCnt--){
            for(int i = 8; i >= 4; i--){
                for(int j = 0; j < 4; j++){
                    block[j][i+1] = block[j][i];
                    block[j][i] = false;
                }
            }
        }

    }

    cout<<answer<<"\n";

    int answer2 = 0;
    for(int i = 6; i < 10; i++){
        for(int j = 0; j < 4; j++){
            if(block[i][j]) answer2++;
            if(block[j][i]) answer2++;
        }
    }
    cout<<answer2<<"\n";

    return 0;
}