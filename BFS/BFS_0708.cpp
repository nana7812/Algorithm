#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int dx[] = {-1,1,0,0};
int dy[] ={0,0,-1,1};

int h,w,answer;
char a[103][103];
bool key[26];
bool check[103][103];
string inputKey;

void BFS(int x, int y)
{
    queue<pair<int, int>> Q;
    queue<pair<int, int>> Door[26];
    Q.push(make_pair(x, y));
    check[x][y] = true;

    while (!Q.empty())
    {
        int qx = Q.front().first;
        int qy = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx >= 0 && ny >= 0 && nx <= h + 1 && ny <= w + 1)
            {
                if (a[nx][ny] == '*' || check[nx][ny] == true) continue;
                check[nx][ny] = true;

                if ('A' <= a[nx][ny] && a[nx][ny] <= 'Z')
                {
                    if (key[a[nx][ny] - 'A'] == true)
                    {
                        Q.push(make_pair(nx, ny));
                    }
                    else
                    {
                        Door[a[nx][ny] - 'A'].push(make_pair(nx, ny));
                    }
                }
                else if ('a' <= a[nx][ny] && a[nx][ny] <= 'z')
                {
                    Q.push(make_pair(nx, ny));
                    if (key[a[nx][ny] - 'a'] == false)
                    {
                        key[a[nx][ny] - 'a'] = true;

                        while (!Door[a[nx][ny] - 'a'].empty())
                        {
                            Q.push(Door[a[nx][ny] - 'a'].front());
                            Door[a[nx][ny] - 'a'].pop();
                        }
                    }
                }
                else
                {
                    Q.push(make_pair(nx, ny));
                    if (a[nx][ny] == '$') answer++;
                }
            }
        }
    }
}


int main() {

    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(check,false,sizeof(check));
        memset(key,false,sizeof(key) );
        cin>> h>>w;
        for(int i = 1; i <=h; i++){
            for(int j = 1; j <= w; j++){
                cin>>a[i][j];
            }
        }
        cin>> inputKey;
        for(int i = 0; i <inputKey.length();i++){
            if(inputKey[i] == '0') continue;
            key[inputKey[i]- 'a'] = true;
        }
        answer = 0;
        BFS(0,0);
        cout<<answer<<"\n";

    }
    return 0;
}

