#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;


int main()
{
   int n,m;
   cin>> n>>m;

   set<string> s;
   for(int i = 0; i < n; i++){
       string dname;
       cin>> dname;
       s.insert(dname);
   }

   vector<string> v;
   for(int i = 0; i < m; i++){
       string bname;
       cin>> bname;
       if(s.find(bname) != s.end()){
           v.push_back(bname);
       }
   }
   sort(v.begin(),v.end());
   cout<<v.size()<<"\n";
   for(int i =0; i <v.size();i++){
       cout<<v[i]<<"\n";
   }

    return 0;
}