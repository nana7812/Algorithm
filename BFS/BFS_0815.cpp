#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool BFS(int a, int b, vector<string> MAP)
{
    vector<vector<bool>> Visit(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{a,b}, 0});
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (Cnt == 2) continue;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == 'O')
                    {
                        Visit[nx][ny] = true;
                        Q.push({{nx,ny},Cnt+1});
 
                    }
                    else if (MAP[nx][ny] == 'P')
                    {
                        return false;
                    }
                }
                
            }
        }
    }
    return true;
}
 
int sol(vector<string> MAP)
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == 'P')
            {
                if (BFS(i, j, MAP) == false)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
 

 
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
     for (int i = 0; i < places.size(); i++)
    {
        answer.push_back(sol(places[i]));
    }
    return answer;
}