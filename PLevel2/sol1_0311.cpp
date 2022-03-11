#include <string>
#include <vector>
#include <queue>

using namespace std;

bool connect[101][101];
vector<bool> v;
int bfs(int x, int n){
    int cnt = 1;
    v[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int qx = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(!v[i] && connect[qx][i]){
                q.push(i);
                v[i] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0; i < wires.size(); i++){
        int n1 = wires[i][0];
        int n2 = wires[i][1];
        n1--; n2--;
        connect[n1][n2] = connect[n2][n1] = true;
    }
                     
    for(int i = 0; i < wires.size(); i++){
        int n1 = wires[i][0];
        int n2 = wires[i][1];
        n1--; n2--;
        connect[n1][n2] = connect[n2][n1] = false;
        vector<int> ans; 
        v = vector<bool>(n,false);
        for(int j = 0; j < n; j++){
            if(!v[j]){
                ans.push_back(bfs(j,n));
            }
        }
        answer = min(abs(ans[1]-ans[0]),answer);
        connect[n1][n2] = connect[n2][n1] = true;
    }
                  
    return answer;
}