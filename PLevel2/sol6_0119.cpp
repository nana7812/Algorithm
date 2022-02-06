#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool c[105][105];
vector<bool> v;

int dfs(int x, int N){
    if(v[x]) return 0;
    v[x] = true;
    
    int ans = 1;
    for(int i = 1; i <= N; i++){
        if(c[x][i]){
           ans += dfs(i,N); 
        }
    }
  
    return ans;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0; i < wires.size(); i++){
        int n1 = wires[i][0];
        int n2 = wires[i][1];
        c[n1][n2] = true;
        c[n2][n1] = true;
    }
    
    for(int i = 0; i < wires.size(); i++){
        int n1 = wires[i][0];
        int n2 = wires[i][1];
        c[n1][n2] = c[n2][n1] = false;
        
        vector<int> ans;
        v = vector<bool>(n+1,false);
        for(int j = 1; j <= n; j++){
            if(v[j]) continue;
            int cnt = dfs(j,n);
            ans.push_back(cnt);
        }
        answer = min(answer,abs(ans[0]-ans[1]));
        c[n1][n2] = c[n2][n1] = true;
    }
    return answer;
}