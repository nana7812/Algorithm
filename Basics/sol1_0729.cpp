#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> combination;
int columnSize;
bool compare(string a,string b){
    return a.length()< b.length();
}

//조합만들
void COM(int num,int cnt, int level,string com){
    if(cnt >= level){
        combination.push_back(com);
        return;
    }
    for(int i = num; i < columnSize; i++){
        char t = i + '0';
        COM(i+1,cnt+1,level,com+t);
    }
}
//후보키
bool subset(vector<vector<string>>& relation, string com){
    map<string,int> m;
    for(int i = 0; i <relation.size(); i++){
        string temp = "";
        for(int k = 0; k <com.length(); k++){
            int idx = com[k]- '0';
            temp+= relation[i][idx];
        }
        if(m[temp]) return false;
        m[temp]++;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    columnSize = relation[0].size();
    for(int i = 1; i <= columnSize; i++){
        COM(0,0,i,"");
    }
    sort(combination.begin(),combination.end(),compare);

    for(int i = 0; i < combination.size(); i++){
        if(subset(relation,combination[i])){
            answer++;
            string temp = combination[i];
           for (int j = combination.size() - 1; j > i; j--) {
                bool check = true;
                for (auto t:temp) {
                    if (combination[j].find(t) == string::npos) {
                        check = false;
                        break;
                    }
                }
                if (check) combination.erase(combination.begin() + j);
            }
               
        
        }
    }
   return answer;
}