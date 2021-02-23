#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int INF = 1000000001;
vector<pair<int, int>> v;

//이어지거라 겹치는 구간은 동일한 구간으로 (즉, 이어붙일 수 있을때 까지 붙이기)
//**cin cout 사용하면 시간초과 나옴 

int main() {

    int n;
    scanf("%d", &n);
    int a,b;
    for(int i = 0; i < n; i++){
         scanf("%d %d", &a, &b);
        v.push_back(make_pair(a,b));
    }

    //왼쪽 끝 좌표 순으로 정렬 _ 왼쪽 좌표를 기준으로 시
    sort(v.begin(),v.end());

   // [from ,to]:현재 합치고 있는 구
    int result = 0, from = -INF, to = -INF;
    for(int i = 0; i < n; i++){
        //현재 구간과 i선분이 합쳐질 수 없는경우
        if(to < v[i].first){
            result += to - from;
            //합치고 있는 구간 reset
            from = v[i].first;
            to = v[i].second;
        }else{
            to = max(to, v[i].second);
        }
    }
    //마지막 구간은 따로 결과에 더해줌
    result += to - from;
    printf("%d\n", result);


    return 0;
}