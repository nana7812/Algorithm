#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> db[3][2][2][2];

//info
vector<int> infoSplit(string s){
    vector<int> ret;
    string temp;
    int n;
    for(char c: s){
        if(c == ' '){
            if(temp == "cpp" || temp == "backend" || temp  == "junior" || temp == "chicken") n = 0;
            else if(temp == "python") n = 2;
            else n = 1;
            ret.push_back(n);
            temp = "";
        }else{
            temp += c;
        }
    }
    //점수
    ret.push_back(stoi(temp));
    return ret;
}
//query
vector<string> querySplit(string s){
    vector<string> ret;
    string temp = "";
    for(char c :s){
        if(c == ' '){
            ret.push_back(temp);
            temp = "";
        }else{
            temp += c;
        }
    }
    ret.push_back(temp);
    return ret;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    //info
    for(string s : info){
        vector<int> v = infoSplit(s);
        db[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }
    //모든 조건에 대해서 점수 점수 정렬
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    sort(db[i][j][k][l].begin(),db[i][j][k][l].end());
                }
            }
        }
    }
    for(string s : query){
        vector<string> v = querySplit(s);
        int ai,bi,aj,bj,ak,bk,al,bl;
        
        if(v[0] == "cpp") ai = bi = 0;
        else if(v[0] == "java") ai = bi = 1;
        else if(v[0] == "python") ai = bi = 2;
        else{ ai = 0; bi = 2;}
        
        if(v[2] == "backend") aj = bj = 0;
        else if(v[2] == "frontend") aj = bj = 1;
        else {aj = 0; bj = 1;}
        
        if(v[4] == "junior") ak= bk = 0;
        else if(v[4] == "senior") ak = bk = 1;
        else {ak = 0; bk = 1;}
        
        if(v[6] == "chicken") al= bl = 0;
        else if(v[6] == "pizza") al = bl = 1;
        else {al = 0; bl = 1;}
        
        int score = stoi(v[7]);
        
        int ans = 0;
        for(int i = ai; i <= bi; i++){
            for(int j = aj; j <= bj; j++){
                for(int k = ak; k <= bk; k++){
                    for(int l = al; l <= bl; l++){
                        int n = db[i][j][k][l].size();
                        if(n == 0) continue;
                        
                        auto iter = lower_bound(db[i][j][k][l].begin(),db[i][j][k][l].end(),score);
                        if(iter == db[i][j][k][l].end()) continue;
                        ans += n - (iter-db[i][j][k][l].begin());
                    }
                }
            } 
        }
        answer.push_back(ans);
    }
    return answer;
}