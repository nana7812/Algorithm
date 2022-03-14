#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int a[101];
vector<int> v;

int main(){

    cin>> N;
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }
    for(int i = 0; i < 4; i++){
        int cnt;
        cin>>cnt;
        while(cnt--){
            v.push_back(i);
        }
    }

    vector<int> ans;

    sort(v.begin(),v.end());
    do{
        int sum = a[0];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                sum += a[i+1];
            }else if(v[i] == 1){
                sum -= a[i+1];
            }else if(v[i] == 2){
                sum *= a[i+1];
            }else{
                sum /= a[i+1];
            }
        }

        ans.push_back(sum);

    }while(next_permutation(v.begin(),v.end()));

    int maxV = *max_element(ans.begin(),ans.end());
    int minV = *min_element(ans.begin(),ans.end());

    cout<<maxV<<"\n"<<minV<<"\n";

    return 0;
}