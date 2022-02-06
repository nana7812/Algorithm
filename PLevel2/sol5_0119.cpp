#include <string>
#include <vector>
#define MAX 10000000001
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long,long>> star;
    long long maxX = -MAX, maxY = -MAX, minX = MAX, minY = MAX;
    for(int i = 0; i <line.size(); i++){
        long long A = line[i][0], B = line[i][1], E = line[i][2];
        for(int j = i+1; j < line.size(); j++){
            long long C = line[j][0], D = line[j][1], F= line[j][2];
            long long bunmo = A*D - B*C;
            if(bunmo == 0) continue;
            if(((B*F - E*D) % bunmo  == 0) && ((E*C - A*F) % bunmo == 0)){
                 long long X = (B*F - E*D) / bunmo;
                 long long Y = (E*C - A*F) / bunmo;
                 star.push_back({Y,X});
                 maxX = max(maxX,X);
                 maxY = max(maxY,Y);
                 minX = min(minX,X);
                 minY = min(minY,Y);
            }
        }
    }
    long long r = maxY - minY +1;
    long long c = maxX - minX +1;
    string temp(c,'.');
    answer.assign(r,temp);
    for(int i = 0; i < star.size(); i++){
        answer[maxY - star[i].first][star[i].second-minX] = '*';
    }
    
    return answer;
}