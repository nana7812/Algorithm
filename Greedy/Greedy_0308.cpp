#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end());
    int e = routes[0][1];
    int answer = 1;
    for(int i = 1; i < routes.size(); i++){
       int ne = routes[i][1];
       int ns = routes[i][0];
       if(e < ns){
           answer++;
           e = ne;
       }
        if(ne <= e){
            e = ne;
        }
    }
    return answer;
}