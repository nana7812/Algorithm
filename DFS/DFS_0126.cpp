#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using  namespace  std;
const int MAX = 16;
int l,c;
vector<char> alpha;

void dfs(int x, int idx, string ans){
    if(x>=l){
        int co = 0; int vo = 0;
        for(int i = 0; i <ans.size(); i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] =='i' || ans[i] =='o' || ans[i] == 'u'){
                vo++;
            }else{
                co++;
            }
        }
        if(co >= 2 && vo >= 1){
            cout<<ans<<"\n";
            return;
        }
        return;
    }

    for(int i = idx; i <alpha.size(); i++){
        dfs(x + 1, i + 1, ans + alpha[i]);
    }

}

int main(){
    cin>> l>> c;
    char input;
    for(int i = 0; i <c; i++){
        cin>>input;
        alpha.push_back(input);
    }
    sort(alpha.begin(),alpha.end());
    dfs(0,0,"");
}