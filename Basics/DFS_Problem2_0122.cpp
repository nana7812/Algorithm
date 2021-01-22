
#include <iostream>
#include <string>

using  namespace  std;
const int MAX = 10000000;
bool check[MAX];
bool index_check[MAX];
bool two[MAX];

//소수 판별
bool isPrime(int num){
    if (num<=1) return false;
    for (int i = 2; i < num; i++) {
        if (num % i ==0){
            return false;
        }
    }
    return true;
}

int dfs(string numbers,string sum, int s,int e){
    int total=0;
    //자릿수 만큼 오면  그 수가 소수인지 판별 여기서 s는 현재 자릿수 e는 내가 만들어야하는 자릿
    if(s==e){
        //11=11 같으까 숫자 중복체크 배열 two 사용
        if(isPrime(stoi(sum)) == true && two[stoi(sum)]== false ){
            two[stoi(sum)] = true;
            cout<<"소수"<<sum<<"\n";
            return 1;
        }
        return 0;
    }

        for(int i = 0; i < numbers.size(); i++){
       if(index_check[i] == false){
            index_check[i] = true;
            total+=dfs(numbers,sum+numbers[i],s+1,e);
            index_check[i] = false;
       }
    }
    return total;
}



int solution(string numbers) {

    int prime = 0;
    //조합으로 자릿수 어려개 되니까 일단 이거 만들었고
    for(int i = 1; i <= numbers.size(); i++) {
        prime += dfs(numbers, "", 0, i);
    }

    return prime;
}