#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using  namespace  std;

long long solve(long long a, long long b){
    while(b != 0){
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    
    //입력 부분
    int N, M;
    long long A=1,B =1;
    cin>> N;
    long long a;
    for(int i = 0; i < N; i++){
        cin>>a;
        A *= a;
    }
    cin>> M;
    long long b;
    for(int i = 0; i < M; i++){
        cin>>b;
        B *= b;
    }

	// 자릿수 확인 _ 문자열로 바꿔서 길이 확인 후 출력
    if(to_string(solve(A,B)).size() > 9){
        string s = to_string(solve(A,B));
        for(int  i = s.size() - 9; i < s.size(); i++){
           cout<<s[i];
        }
    }else{
        cout<<solve(A,B);
    }


}