#include <iostream>
#include <vector>

using  namespace  std;


int main(){
    int n, m;
    cin>> n>> m;

    vector<int> p(n+1);
    for(int i = 0; i < n; i++){
        cin>> p[i];
    }
    int tempValue = 0; int end = 0; int count = 0;
    for(int start = 0; start < n; start++){
        while(tempValue < m && end < n){
            tempValue += p[end];
            end++;
        }
        if(tempValue == m){
            count++;
        }

        tempValue -= p[start];
    }

    cout<< count;

    return 0;
}