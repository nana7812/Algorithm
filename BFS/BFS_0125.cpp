#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 201;
bool check[MAX];

void  bfs(int s,int n, vector<vector<int>>computers){
    queue<int> q;
    check[s] = true; q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i<n; i++){
            if(i == x) continue;
            if(computers[x][i] == 1 && check[i] == false){
                q.push(i);
                check[i] = true;
            }
        }
        
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
       if(check[i] == false){
           bfs(i,n,computers);
           answer++;
       }
    }
    return answer;
}