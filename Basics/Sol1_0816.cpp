#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

long long d[1000001];
long long a[1000001];

int main() {

    int N;
    cin>> N;
    int max = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] > max) max = a[i];
    }
    int B,C;
    cin>>B>>C;
    for(int i = 0; i <= B; i++){
        d[i] = 1;
    }
    for(int i = B+1; i <= max; i++){
        if(i-C < 0){
            d[i] = d[0]+1;
            continue;
        }
        d[i] = d[i-C] + 1;
    }
    long long ans = 0;
    for(int i = 0; i < N; i++){
       ans += d[a[i]];
    }
    cout<<ans;


    return 0;
}