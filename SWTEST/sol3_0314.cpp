#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;



int main(){
    int ans = 987654321;
    int N;
    cin>> N;
    vector<vector<int>> a(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    vector<int> v(N);
    for(int i = 0; i < N/2; i++){
        v[i] = 1;
    }

    sort(v.begin(),v.end());
    do{
        vector<int> A;
        vector<int> B;
        for(int i = 0; i < N; i++){
            if(v[i] == 0){
                A.push_back(i);
            }else{
                B.push_back(i);
            }
        }

        int totalA = 0; int totalB = 0;
        for(int i = 0; i < N/2; i++){
          for(int j = 0; j < N/2; j++){
              if(i == j) continue;
              totalA += a[A[i]][A[j]]; //12 21 i에 따라 j값
              totalB += a[B[i]][B[j]];
          }
        }

        ans = min(ans,abs(totalA-totalB));

    }while(next_permutation(v.begin(),v.end()));

    cout<<ans<<" ";

    return 0;
}