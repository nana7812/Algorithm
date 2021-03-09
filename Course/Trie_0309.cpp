#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>

using  namespace  std;

//트라이 노드를 map으로 설정하고 트라이를 배열로 만들면 문자/레이어/자식 관리가 한번에 된다.
//배열의 인덱스는 트리의 레이어의미 map의 key는 주어진 단어 value 는 트리에서 얘가 몇번째 등장하는지
map<string, int> trie[1500];
int n,k,total,cnt;
string t;

void insert(vector<string>& str){
    int n = 0;
    for(int i = 0; i <str.size(); i++){
        if(trie[n].find(str[i]) == trie[n].end()){
            trie[n].insert({str[i],++total});
            n = total;
        }else{
            n = trie[n][str[i]];
        }
    }
}

void print(int start){
    for(auto it = trie[start].begin(); it != trie[start].end(); it++){
        for(int i = 0; i < cnt*2; i++) cout<<"-";
        cout<<it->first<<"\n";
        if(!trie[it->second].empty()){
            cnt++;
            print(it->second);
            cnt--;
        }
    }
}

int main() {
    cin>> n;
    while(n--){
         cin >> k;
         vector<string> ss;
         while(k--){
             cin>> t;
             ss.push_back(t);
         }
         insert(ss);
    }
    print(0);

    return 0;
}
