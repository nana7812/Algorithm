#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using  namespace  std;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main(){

    int n;
   cin>> n;
   vector<string> v;
   string input;
   for(int i = 0; i < n; i++){
       cin>>input;
       v.push_back(input);
   }
   sort(v.begin(),v.end(),compare);
   v.erase(unique(v.begin(),v.end()),v.end());


   for(int i = 0; i < v.size(); i++){
       cout<<v[i]<<"\n";
   }

}