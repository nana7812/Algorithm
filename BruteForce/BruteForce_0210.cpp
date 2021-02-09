#include <iostream>
#include <vector>
#include <algorithm>

using  namespace  std;



int main()
{
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i <n; i++){
        cin>> a[i];
    }

    vector<int> d;
    for(int i = 0; i < 4; i++){
        int a;
        cin>>a;
        for(int j = 0; j <a; j++){
            d.push_back(i);
        }
    }

    vector<int> ans;
    do{
        int current = 0; int sum = a[current];
        for(int i = 0; i < n-1; i++){
            current++;
            if(d[i] == 0){
                sum += a[current];
            }else if(d[i] == 1){
                sum -= a[current];
            }else if(d[i] == 2){
                sum *= a[current];
            }else{
                sum /= a[current];
            }
        }
        ans.push_back(sum);
    }while(next_permutation(d.begin(),d.end()));

    int max_ans = *max_element(ans.begin(),ans.end());
    int min_ans = *min_element(ans.begin(),ans.end());

    cout<<max_ans<<"\n";
    cout<<min_ans<<"\n";

    return 0;
}