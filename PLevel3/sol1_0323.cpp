#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

struct Page{
    int basicScore;
    vector<string> outlink;
    double linkScore;
    double matchScore;
};
map<string,int> m;

string lower(string str){
    transform(str.begin(),str.end(),str.begin(), ::tolower);
    return str;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    word = lower(word);
    
    vector<Page> info;
    for(int i = 0; i < pages.size(); i++){
        string str = lower(pages[i]);
        //주소찾기
        string target = "<meta property=\"og:url\" content=\"https://";
        int idx = str.find(target); idx += target.size();
        string url = "";
        for(int j = idx; j < str.length(); j++){
            if(str[j] == '\"'){
                str = str.substr(j);
                break;
            }
            url += str[j];
        }
        m[url] = i+1;
        
        //기본점수
        string target1 = "<body>"; string target2 = "</body>";
        int s = str.find(target1); s += target1.size();
        int e = str.find(target2);
        string temp = ""; int cnt = 0;
        for(int j = s; j < e; j++){
            if('a' <= str[j] && str[j] <= 'z'){
                temp += str[j];
            }else{
                if(temp == word) cnt++;
                temp = "";
            }
        }
        if(temp == word) cnt++;
       
        vector<string> link;
        string target3 = "<a href=\"https://";
        int idx1 = str.find(target3); 
        while(idx1 != -1){
            idx1 += target3.size();
            string outUrl = "";
            for(int j = idx1; j < str.length(); j++){
                if(str[j] == '\"'){
                   str = str.substr(j);
                   break; 
                }
                outUrl += str[j];
            }
            link.push_back(outUrl);
            idx1 = str.find(target3);
        }
        
        info.push_back({cnt,link,0,0});
    }
    
    for(int i = 0; i <info.size(); i++){
        vector<string> out = info[i].outlink;
        for(int j = 0; j < out.size(); j++){
            if(m[out[j]] == 0) continue;
            info[m[out[j]]-1].linkScore += ((double)info[i].basicScore/(double)out.size());
           
        }
    }
    
    double maxV = 0;
    for(int i = 0; i < info.size(); i++){
        info[i].matchScore = (double)info[i].basicScore + (double)info[i].linkScore;
        if(maxV < info[i].matchScore){
            maxV = info[i].matchScore;
            answer = i;
        }
    }
    
    return answer;
}