#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>

using  namespace  std;

const int ALPABATS = 26;

class Tri_Node{
private:  Tri_Node * child[ALPABATS];

public:
    Tri_Node(){
        for(int i = 0; i < ALPABATS; i++){
            child[i] = NULL;
        }
    }
    
    ~Tri_Node(){
        for(int i = 0; i < ALPABATS; i++){
            if(child[i] != NULL){
                delete child[i];
            }
        }
    }
    //문자를 숫자로 변환
    int tonum(char c){
        return tolower(c) - 'a';
    }
    
    void insert(const char * words){
        if(*words == '\0') // 입력받은 단어가 문자열의 끝일 경우 
            return;
        int next = tonum(*words);
        
        if(child[next] == NULL){ //아직 해당 문자 입력이 안된경우 
            child[next] = new Tri_Node();
        }
        child[next]->insert(words+1); //주소값 증가시키기:다음값을 가르킨다. 
    }
    
    bool find(const char* words){
        int next = tonum(*words);
        
        if(*words == '\0')
            return true;
        
        if(child[next] == NULL)
            return false;
        return child[next] ->find(words+1);
    }
    
};

int main() {
  Tri_Node tri;
}