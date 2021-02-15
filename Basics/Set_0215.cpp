#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;

map<string,int> m;

int main()
{
   int n;
   cin>> n;
   while(n--){
       string book;
       cin>> book;
       m[book]++;
   }

   int result_idx =0;
   for(auto i = m.begin(); i != m.end(); i++){
       result_idx = max(result_idx,i->second);
   }


   for(auto i = m.begin(); i !=m.end();i++){
       if(result_idx == i->second){
           cout<<i->first;
           return 0;
       }
   }

    return 0;
}