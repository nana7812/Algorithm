#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int boat = 0;
    int big = people.size()-1;
    int thin = 0;

    while(thin <= big){
        if(people[big]+people[thin] <=limit){
            big--;
            thin++;
            boat++;
        }else{
            big--;
            boat++;
        }
    }    

    return boat;
}