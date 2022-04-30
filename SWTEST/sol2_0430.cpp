#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int a[25][25];
int mark[25][25];
int answer;
struct Pos{
    int x;
    int y;
};
Pos p[4];


void marking(){
    //모든 선거구 일단 5번으로 설정
    for(int i= 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mark[i][j] = 5;
        }
    }

    int area = 0;
    for(int i =  0; i < p[1].x; i++){
        if(i >= p[0].x) area++;
        for(int j = 0; j <= p[0].y - area; j++){
            mark[i][j] = 1;
        }
    }

    area = 0;
    for(int i = 0; i <= p[2].x; i++){
        if(i > p[0].x) area++;
        for(int j = p[0].y+area +1; j < N; j++){
            mark[i][j] = 2;
        }
    }

    area = 0;
    for(int i = N-1; i >= p[1].x; i--){
        if(i < p[3].x) area++;
        for(int j = 0; j < p[3].y-area; j++){
            mark[i][j] = 3;
        }
    }

    area = 0;
    for(int i = N-1; i > p[2].x; i--){
        if(i <= p[3].x) area++;
        for(int j = p[3].y + area; j < N; j++){
            mark[i][j] = 4;
        }
    }

    vector<int> people(6,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            people[mark[i][j]] += a[i][j];
        }
    }
    sort(people.begin(),people.end());
    int diff = people[5] - people[1];
    answer = min(answer,diff);

}


int main(){
    answer = 987654321;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >>a[i][j];
        }
    }


    for(int x = 0; x < N; x++){
        for(int y = 1; y < N; y++){
            for(int d1 = 1; x+d1 < N && y- d1 >= 0 ; d1++){
                for(int d2 = 1; x+d2 < N && y + d2 < N && x+d1+d2 < N && y+d2- d1 >= 0 && y -d1 + d2 < N; d2++){
                    p[0].x = x; p[0].y = y;
                    p[1].x = x + d1; p[1].y = y - d1;
                    p[2].x = x + d2; p[2].y = y + d2;
                    p[3].x = x + d1 + d2; p[3].y = y - d1 + d2;

                    marking();
                }
            }
        }
    }

    cout<<answer<<" ";

    return 0;
}