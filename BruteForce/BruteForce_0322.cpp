#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace  std;

int N,M;
vector<char> v;

bool check(int a){
    string s = to_string(a);
    for(int i = 0; i <v.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(v[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}

int main() {

    cin>> N;
    cin>> M;
    for(int i = 0; i < M; i++){
        char t;
        cin>> t;
        v.push_back(t);
    }

    //100번에서 이동
    int ans = N-100;
    if (ans < 0) {
		ans = -ans;
	}
   // int temp;
    for(int i = 0; i <=1000000; i++){
        int num = i;
        if(check(num)){
            int count = to_string(num).size();
            count += abs(num-N);
            if(count < ans){
               // temp = num;
                ans = count;
            }
        }
    }
  //  cout<<temp<<"\n";
    cout<<ans;
    return 0;
}