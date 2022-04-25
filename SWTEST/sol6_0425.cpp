#include <iostream>

using namespace std;

int N;
int T[20];
int P[20];
int answer;


void dfs(int day, int sum){
    if(day >= N+1){
        if(day == N+1 && sum > answer){
            answer = sum;
        }
        return;
    }
    dfs(day+1,sum);
    dfs(day + T[day], sum + P[day]);


}

int main() {
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin>>T[i]>> P[i];
    }
    
    answer = 0;
    dfs(1,0);
    cout<<answer<<"\n";

    return 0;
}