#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    //"길이만큼 A로만 구성된 문자열"
    string temp = "";
    for(int i = 0; i < name.size(); i++){
        temp += "A";
    }
    
    //시작점
    int idx = 0; 
    while(true){
        //한문자씩 바꾸기
        temp[idx] = name[idx];
        //바꾼만큼 값을 조작+해야하는데 더 적은 조작값 사용
        //좌표 그리고 생각해보기 'Z' 역순은 'A'에서 'Z'로 거리 1더해줌
        answer += min(name[idx] - 'A','Z'-name[idx]+1);
        
        //같으면 종료
        if(name == temp) break;
        
        //커서 오른쪽 이동과 왼쪽 이동 비교 
        for(int move = 1; move < name.size(); move++){
            //if문은 같지않은 부분을 누가 더 먼저 만나냐
            //오른쪽방향으로 같지 않을때까지 이동하는 거리 계산
            if(name[(idx + move)%name.length()] != temp[(idx + move)%name.length()]){
                idx = (idx + move)%name.length();
                answer+= move;
                break; //찾았으니까 이동 그만
            }else if(name[(idx+name.length()-move)%name.length()] != temp[(idx+name.length()-move)%name.length()]){
                idx = (idx+name.length()-move)%name.length();
                answer += move;
                break;
            }
        }
    }
    return answer;
}