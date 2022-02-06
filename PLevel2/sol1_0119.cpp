#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int a[1005][1005];
    int left = 0, right = 0, state = 0, num = 1;
    for(int i = 0; i < n; i++){
        switch(state){
            case 0:
                for(int j = i; j < n; j++){
                    a[left++][right] = num++;
                }
                left--;
                right++;
                state = 1;
                break;
            case 1:
                for(int j = i; j < n; j++){
                    a[left][right++] = num++;
                }
                left--;
                right -=2;
                state = 2;
                break;
            case 2:
                for(int j = i; j < n; j++){
                    a[left--][right--] = num++;
                }
                left += 2;
                right++;
                state = 0;
                break;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <i+1; j++){
            answer.push_back(a[i][j]);
        }
    }
    return answer;
}