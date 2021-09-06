#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    //1단계
    for(int i = 0; i < new_id.size(); i++){
        if('A' <= new_id[i] && new_id[i] <= 'Z'){
            new_id[i] = tolower(new_id[i]);
        }
    }
    //2단계
    for(int i = 0; i < new_id.size();){
        char a = new_id[i];
        if(('a'<= a && a <= 'z') || ('0' <= a && a <= '9') || 
           (a == '-') || (a == '_') || (a == '.')){
            i++;
            continue; 
        }
        new_id.erase(new_id.begin()+i);

    }
    
    //3단계
    int cnt = 0; 
    for(int i = 0; i < new_id.size()-1;){
        if(new_id[i] == '.' && new_id[i+1] == '.'){
            new_id.erase(new_id.begin()+i+1);
            continue;
        }
        i++;
    }
    //4단계
    if(new_id[0] == '.'){ // new_id.front()
        new_id.erase(new_id.begin());
    }
    if(new_id[new_id.size()-1] == '.'){ // new_id.back()
        new_id.erase(new_id.end()-1);
    }
    //5단계
    if(new_id.size() == 0){
        new_id = 'a';
    }
    //6단계
    if(new_id.size() >= 16){
        while(new_id.size() != 15){
            new_id.erase(new_id.begin() + 15);
        }
    }
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.end()-1);
    //7단계
    while(new_id.size() < 3){
        new_id += new_id[new_id.size()-1];  //+= new_id.back()
    }
    return new_id;
}