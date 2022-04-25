#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin>> a[i];
    }

    vector<int> v;
    for(int i = 0; i < 4; i++){
        int c;
        cin>> c;
        while(c--){
            v.push_back(i);
        }
    }

    int minV = 987654321, maxV = -987654321;
    do{
        int temp = a[0];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                temp += a[i+1];
            }else if(v[i] == 1){
                temp -= a[i+1];
            }else if (v[i] == 2){
                temp *= a[i+1];
            }else if(v[i] == 3){
                temp /= a[i+1];
            }
        }

        if(temp < minV) minV = temp;
        if(temp > maxV) maxV = temp;

    }while(next_permutation(v.begin(),v.end()));

    cout<<maxV<<"\n";
    cout<<minV<<"\n";
    return 0;
}
