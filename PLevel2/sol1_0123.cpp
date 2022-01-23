#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(long long s){
    if(s == 1) return false;
    
    for(long long i = 2; i <= sqrt(s); i++){
        if(s % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
     int answer = 0;
    string num = "";
    while(n != 0){
        char res = (n % k) + '0';
        num = res + num;
        n /= k;
    }
    long long i = 0, z = 0; string temp = "";
    bool flag = false;
    while(true){
        if(num.find('0') == -1){
            break;
        }else{
            flag = true;
            z = num.find('0');
            num[z] = 'X';
            if(z <= i){
                i++;
                continue;
            }
            temp = num.substr(i,z-i);
            i = z+1;
            if(isPrime(stoll(temp))) answer++;
        }
    }
    if(!flag || z != num.size()-1){
       temp = num.substr(i);
       if(isPrime(stoll(temp))) answer++; 
    }
  
    return answer;
}