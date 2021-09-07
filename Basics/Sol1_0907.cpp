#include <string>
#include <vector>
#include <map>

using namespace std;

map<int,pair<int,int>> m;
pair<int,int> L; pair<int,int> R;

char sol(int num,char hand){
    if(hand == 'L'){
         L.first = m[num].first;
         L.second = m[num].second;
         return 'L';
    }else{
        R.first = m[num].first;
        R.second = m[num].second;
        return 'R';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    m[0] = make_pair(3,1);
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            m[i*3+j+1] = make_pair(i,j);
        }
    }
    L.first = 3; L.second = 0; R.first = 3; R.second = 2;
    
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += sol(numbers[i],'L');
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += sol(numbers[i],'R');
        }else{
            int Ldiff = abs(L.first - m[numbers[i]].first) + abs(L.second - m[numbers[i]].second);
            int Rdiff = abs(R.first - m[numbers[i]].first) + abs(R.second - m[numbers[i]].second);
            if(Ldiff > Rdiff){
                answer += sol(numbers[i],'R');
            }else if(Ldiff < Rdiff){
                answer += sol(numbers[i],'L');
            }else if(Ldiff == Rdiff){
                if(hand == "left"){
                    answer += sol(numbers[i],'L');
                }else{
                    answer += sol(numbers[i],'R');
                }
            }
        }    
    }
    return answer;
}