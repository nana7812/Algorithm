#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;


int main()
{
   int n;
   cin>> n;

   set<string> s;
   for(int i = 0; i < n; i++){
       string name,state;
       cin>> name>> state;
       if(state == "enter"){
           s.insert(name);
       }else{
           s.erase(name);
       }
   }

   for(auto iter = s.rbegin(); iter != s.rend(); iter++){
       cout<<*iter<<"\n";

   }

    return 0;
}