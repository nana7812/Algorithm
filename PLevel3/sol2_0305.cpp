#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Page{
    int idx;
    int basicP;
    vector<string> outLink;
    double linkP;
    double matchP;
};

map<string,int> pageIdx;
vector<Page> page;
string Word;

string toLower(string str){
    transform(str.begin(),str.end(),str.begin(), ::tolower);
    return str;
}

string findUrl(string str){
    string target = "<meta property=\"og:url\" content=\"https://";
    int idx = str.find(target);
    string url = "";
    for(int i = idx + target.length();str[i] != '\"';i++){
        url += str[i];
    }
    return url;
}

int findWord(string str){
    string target1 ="<body>"; string target2 = "</body>"; //?
    int idx1 = str.find(target1); int idx2 = str.find(target2);
    idx1 += target1.length();
    str = str.substr(idx1,idx2-idx1);
    int cnt = 0;
    string temp = "";
    for(int i = 0; i < str.length(); i++){
        if('a'<= str[i] && str[i] <= 'z'){ //알파벳이면 더해주다가 
            temp += str[i];
        }else{
            if(temp == Word) cnt++; // 공백이나 특수문자 발견시 같은지 확인
            temp = "";
        }
    }
    return cnt;
}

vector<string> findOutLink(string str){
    vector<string> link;
    string target = "<a href=\"https://";
    int idx = str.find(target);
    while(idx != -1){
        idx += target.length();
        string temp = "";
        while(str[idx] != '\"') temp += str[idx++];
        link.push_back(temp);
        str = str.substr(idx); //2개이상일 경우를 대비해 문자열을 재조정
        idx = str.find(target);
    }
    return link;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    Word = toLower(word);
    for(int i = 0; i < pages.size(); i++){
        string str = toLower(pages[i]); //소문자로 통일
        string url = findUrl(pages[i]);
        pageIdx[url] = i+1;
        int wordCnt = findWord(str);
        vector<string> outL = findOutLink(str);
        page.push_back({i,wordCnt,outL,0.0,0.0});
    }
    
    for(int i = 0; i < page.size(); i++){
        vector<string> v = page[i].outLink;
        int size = v.size();
        for(int j = 0; j < v.size(); j++){
            if(pageIdx[v[j]] == 0) continue;
            int idx = pageIdx[v[j]] - 1;
            page[idx].linkP += ((double)page[i].basicP / (double) size);
        }
    }
    double maxScore = 0;
    for(int i = 0; i < page.size(); i++){
        page[i].matchP =(double)page[i].basicP + (double)page[i].linkP;
        if(page[i].matchP > maxScore){
            maxScore = page[i].matchP;
            answer = i;
        }
    }
    
    return answer;
}