#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
int column;
vector<string> combination;

//후보키 개수 적은걸로 일단 정렬 같다면 사전수
bool compare(string & a, string & b){
    if(a.length() != b.length()) return a.length()< b.length();
    return a < b;
}

//컬럼수에 따른 조합 만들기
void Combination(int k = 0, string temp = ""){
    for(int i = k; i < column; i++){
        temp += to_string(i);
        combination.push_back(temp);
        Combination(i+1,temp);
        temp = temp.substr(0,temp.length()-1);
    }
}

//후보키 확인
bool subset(vector<vector<string>> &relation, string com){
    map<string, int> check;
    for(int i = 0; i < relation.size(); i++){
        string temp = "";
        for(int j = 0; j < com.length(); j++){
            int n = com[j] - '0';
            temp += relation[i][n];      
        }
        if(check[temp]) return false;
        check[temp]++;
    }
    //다 문제 없이 통과하면 true
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    column = relation[0].size();
    Combination();
    //조합수 1개,2개 .. 이런식으로 정렬
    sort(combination.begin(),combination.end(),compare);
    //이제 조합수 만큼 확인해보기
    for(int i = 0; i < combination.size(); i++){
        //후보키인지 확인
        if(subset(relation,combination[i])){
            string temp = combination[i];
            //com에서 조합 들어간건 확인 후 삭제 i까지만 확인!!
            for(int j = combination.size() -1; j >= i; j—){
                bool check = true;
                for(auto t : temp){
                    if(combination[j].find(t) == -1){ //(1,3이면 1,3 둘다 있어야함)
                        check = false;
                        break;
                    }
                }
                //만약 포함 되어 있으면 삭제
                if(check) combination.erase(combination.begin() + j);
            }
            //나는 후보키였으니까 무조건 제거-> 했으므로 i줄이기  
           // cout<<temp<<"\n";
            i—; answer++;
        }
    }
    return answer;
}