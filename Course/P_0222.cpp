#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;


vector<pair<int,int>> v;

int cal(int a, int b){
    return abs(a-b);
}

int main() {
    int n;
    cin>> n;
    int total = 0;
    int x,y;
    int preX,preY;
    for(int i = 0; i <n; i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
        if(i >0){
         total += (cal(preX,x)+cal(preY,y));
        }
        preX = x; preY = y;
    }
   // cout<<total;

   int pass = 0;
   for(int i = 1; i < n-1; i++){
    int unChange = (cal(v[i-1].first,v[i].first) +cal(v[i-1].second,v[i].second)) +
            (cal(v[i].first,v[i+1].first) +cal(v[i].second,v[i+1].second));
    int change = cal(v[i-1].first,v[i+1].first) + cal(v[i-1].second,v[i+1].second);
   // cout<<unChange-change<<"\n";
    pass = max(pass,unChange-change);
   }
   int ans = total - pass;
   cout<<ans;

    return 0;
}