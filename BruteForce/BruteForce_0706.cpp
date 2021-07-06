#include <string>
#include <vector>


using namespace std;

vector<int> solution(int brown, int yellow) {
    //높이 최소 3이상_테두리 갈색,중앙 노란색
    //y+b 더해서 최소 3이상의 h 임의로 구하고(반복문)
    //구해진 h에서 (h-2)*(w-2) == y 중단
    vector<int> answer;
    int sum = brown + yellow;
    for(int i = 3;;i++){
        if(sum%i== 0){
            int h = i;
            int w = sum/h;
            if((h-2)*(w-2) == yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}