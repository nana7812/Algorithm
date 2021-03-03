#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;



int main() {
    vector<int> v;
   int h,w;
   cin>>h>>w;
   int a;
   for(int i = 0; i < w; i++){
       cin>>a;
       v.push_back(a);
   }
   int sum = 0;
   for(int i = 1; i < w-1; i++){
       int left = 0; int right = 0;
       for(int j = i-1; j >= 0; j--){
           left = max(left,v[j]);
       }
       for(int j =i+1; j<w; j++){
           right = max(right,v[j]);
       }
       int temp = min(left,right) - v[i];
       sum += max(0,temp);
   }

   cout<<sum;
    return 0;
}