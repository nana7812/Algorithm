#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string changeMelody(string s){
    string m = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            m[m.size()-1] = m[m.size()-1] - 'A' + 'a';
        }else{
            m += s[i];
        }
    }
    return m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int startH = 0, startM = 0, endH = 0, endM = 0, playT = 0,prevPlayT = 0;
    string title = "",melody ="";
    melody = changeMelody(m);
    for(int i = 0; i < musicinfos.size(); i++){
        string temp = "", music = "";
        startH = stoi(musicinfos[i].substr(0,2)) * 60;
        startM = stoi(musicinfos[i].substr(3,2));
        endH = stoi(musicinfos[i].substr(6,2)) * 60;
        endM = stoi(musicinfos[i].substr(9,2));
        playT = (endH+ endM) - (startH+ startM);
        
        for(int j = 12; j < musicinfos[i].size(); j++){
            if(musicinfos[i][j] == ','){
                title = musicinfos[i].substr(12,j-12);
                temp = musicinfos[i].substr(j+1);
                break;
            }
        }
        
        music = changeMelody(temp);
        if(music.size() < playT){ //재생시간이 악보보다 길다
            temp = music;
            for(int j = 1; j < playT /temp.size(); j++)
                music += temp;
            for(int j = 0; j < playT %temp.size(); j++)
                music += temp[j];
        }else{ //재생시간이 악보보다 짧으면 처음부터 듣다가 잘림
            music = music.substr(0,playT);
        }
        if(music.find(melody) != -1){
            if(prevPlayT < playT){
                answer = title;
                prevPlayT = playT; 
            }
        }
    }
  
    return answer;
}