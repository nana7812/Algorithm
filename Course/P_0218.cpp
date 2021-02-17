#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;

int sizeA[1000001],sizeB[100001];

int main() {
    int order;
    cin>> order;
    int M, N;
    cin>> M>> N;
    vector<int> A(M),B(N);
    for(int i = 0; i < M; i++){
        cin>>A[i];
    }
    for(int i = 0; i < N; i++){
        cin>> B[i];
    }

    sizeA[0] = 1,sizeB[0] = 1;
    int sum = 0;
    for(int i = 0; i <M; i++){
        sum += A[i];
    }
    sizeA[sum]++;
    sum = 0;
    for(int i = 0; i <N; i++){
        sum += B[i];
    }
    sizeB[sum]++;

    //동그라미  연속합
    for(int i = 0; i <M; i++){
        int sum = 0;
        for(int j = 0; j < M-1;j++){
            sum+= A[(i+j) % M];
            sizeA[sum]++;
        }
    }

    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N-1; j++){
            sum+= B[(i+j) % N];
            sizeB[sum]++;
        }
    }
    int ans = 0;
    for(int i = 0; i <= order; i++){
        ans += (sizeA[i] * sizeB[order-i]);
    }

    cout<<ans;

}