#include<iostream>
using namespace std;

long long  N,B,C;
long long a[1000005];

int main(){
    int T;
    cin>> T;
    while(T--){
        cin>> N;
        for(long long i = 0; i <N; i++){
            cin>>a[i];
        }
        cin>>B>>C;
        long long answer = N;
        for(long long i = 0; i < N; i++){
            a[i] -= B;
            if(a[i] <= 0) continue;
            if(a[i] % C == 0){
                answer += a[i]/C;
            }else{
                answer += a[i]/C +1;
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}