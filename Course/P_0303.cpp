#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;



int main() {
  int N;
  cin>> N;
  vector<pair<int,int>> v;
  int L,H;
  for(int i = 0; i < N; i++){
      cin>> L>>H;
      v.push_back(make_pair(L,H));
  }
  sort(v.begin(),v.end());

  int sum = 0;

  int left_f = v[0].first;
  int left_h = v[0].second;
  for(int i = 0; i < v.size(); i++){
      //=가장 높은거 2개이상일 경우 생각!!
      if(left_h <= v[i].second){
        // cout<<(v[i].first-left_f)*left_h<<" ";
          sum += (v[i].first-left_f)*left_h;
          left_f = v[i].first;
          left_h = v[i].second;
      }
  }


  int right_f = v.back().first;
  int right_h = v.back().second;
  for(int i = v.size()-1; i >=0; i--){
      if(right_h < v[i].second){
          //cout<<(right_f -v[i].first )*right_h<<" ";
          sum += (right_f -v[i].first ) *right_h;
          right_f = v[i].first;
          right_h = v[i].second;
      }
  }

  cout<<sum+ left_h;

  return 0;
}