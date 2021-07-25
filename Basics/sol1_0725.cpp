#include <string>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int total = 0;
    int n = 0;
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    vector<string> s1; 
    vector<string> s2;
    
    for(int i = 0; i < str1.size()-1; i++){
        string temp = str1.substr(i,2);
        if('a' <= temp[0] && temp[0] <= 'z' &&'a' <= temp[1] && temp[1] <= 'z'){
            s1.push_back(temp);
        }
    }
    for(int i = 0; i <str2.size()-1; i++){
         string temp = str2.substr(i,2);
        if('a' <= temp[0] && temp[0] <= 'z' &&'a' <= temp[1] && temp[1] <= 'z'){
            s2.push_back(temp);
        }
    }
    if(s1.empty() && s2.empty()){
        return 65536;
    }
    total = s1.size()+ s2.size();
    
    if(s1.size() > s2.size()){
        for(int i = 0; i < s2.size(); i++){
            auto itr = find(s1.begin(),s1.end(),s2[i]);
            if(itr != s1.end()){
                n++;
                s1.erase(itr);
            }
        }
    }else{
        for(int i = 0; i < s1.size(); i++){
            auto itr = find(s2.begin(),s2.end(),s1[i]);
            if(itr != s2.end()){
                n++;
                s2.erase(itr);
            }
        }
    }
    total -= n;
    if(total == 0){
        return 65536;
    }
    
    double v = (double)n / (double)total;
    
    return v * 65536;
    
    
}