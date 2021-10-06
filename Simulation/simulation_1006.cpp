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
#define MAX 25
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct Student{
    int num;
    int favorite[4];
};

struct position{
    int x;
    int y;
    int empty;
    int nearFriend;
};

int N, answer;
int a[MAX][MAX];
Student s[MAX*MAX];
vector<Student> student;

bool cmp(position A, position B){
    if(A.nearFriend >= B.nearFriend){
        if(A.nearFriend == B.nearFriend){
            if(A.empty >= B.empty){
                if(A.empty == B.empty){
                    if(A.x <= B.x){
                        if(A.x == B.x){
                            if(A.y < B.y){
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int cal(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 10;
    if(x == 3) return 100;
    if(x == 4) return 1000;
}

int main(){
    cin>> N;
    for(int i = 0; i < N*N; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        student.push_back({a,{b,c,d,e}});
        s[a].num = a;
        s[a].favorite[0] = b;
        s[a].favorite[1] = c;
        s[a].favorite[2] = d;
        s[a].favorite[3] = e;
    }

    for(int i = 0; i <student.size(); i++){
        vector<position> pos;
        int studentNum = student[i].num;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(a[x][y] != 0) continue;
                int nearlyFriend = 0;
                int nearlyEmpty = 0;
                for(int k = 0; k < 4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(a[nx][ny] == 0) nearlyEmpty++;
                    else{
                        for(int j = 0; j < 4; j++){
                            int friendNum = student[i].favorite[j];
                            if(a[nx][ny] == friendNum){
                                nearlyFriend++;
                                break;
                            }
                        }
                    }
                }
                pos.push_back({x,y,nearlyEmpty,nearlyFriend});
            }
        }
        sort(pos.begin(),pos.end(),cmp);
        int posX = pos[0].x;
        int posY = pos[0].y;
        a[posX][posY] = studentNum;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int studentNum = a[i][j];
            int Friend = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                for(int l = 0; l < 4; l++){
                    int friendNum = s[studentNum].favorite[l];
                    if(a[nx][ny] == friendNum){
                        Friend++;
                        break;
                    }
                }
            }
            answer += cal(Friend);
        }
    }
    cout<<answer<<"\n";


    return 0;
}