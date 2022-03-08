#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> Info;
int answer = 1;

void dfs(int cur, int w, int s,vector<int> next){
    if(Info[cur] == 0) s++;
    else w++;
    
    answer = max(answer, s);
    if(w >= s) return;
    
    for(int i = 0; i < next.size(); i++){
        vector<int> n = next;
        n.erase(n.begin()+i); //간 곳은 빼고 
        for(int j = 0; j < tree[next[i]].size(); j++){
            n.push_back(tree[next[i]][j]);
        }
        dfs(next[i],w,s,n);
    }
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    Info = info;
    for(int i = 0; i < info.size(); i++){
        vector<int> temp;
        tree.push_back(temp);
    }
    //바로 여기로 넘어갈 수 있나 생각
    for(int i = 0; i < edges.size(); i++){
        int n1 = edges[i][0];
        int n2 = edges[i][1];
        tree[n1].push_back(n2);
    }

    dfs(0,0,0,tree[0]);
    return answer;
}