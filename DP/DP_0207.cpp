#include <iostream>
#include <algorithm>

using  namespace  std;

const int MAX = 100001;

int minDp[2][3];
int maxDp[2][3];
int a[MAX][3];

int main(){

    int n;
    cin>> n;


    for(int i = 0; i <n; i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    minDp[0][0] = a[0][0]; minDp[0][1] = a[0][1]; minDp[0][2] = a[0][2];
    maxDp[0][0] = a[0][0]; maxDp[0][1] = a[0][1]; maxDp[0][2] = a[0][2];
    for(int i = 1; i <n; i++){
        minDp[1][0] = a[i][0] + min(minDp[0][0],minDp[0][1]);
        minDp[1][1] = a[i][1] + min(minDp[0][0],min(minDp[0][1],minDp[0][2]));
        minDp[1][2] = a[i][2] + min(minDp[0][1],minDp[0][2]);

        minDp[0][0] = minDp[1][0]; minDp[0][1] = minDp[1][1]; minDp[0][2] = minDp[1][2];

        maxDp[1][0] = a[i][0] +max(maxDp[0][0],maxDp[0][1]);
        maxDp[1][1] = a[i][1] +max(maxDp[0][0],max(maxDp[0][1],maxDp[0][2]));
        maxDp[1][2] = a[i][2] +max(maxDp[0][1],maxDp[0][2]);

        maxDp[0][0] = maxDp[1][0]; maxDp[0][1] = maxDp[1][1]; maxDp[0][2] = maxDp[1][2];
    }

    int min_ans = min(minDp[0][0],min(minDp[0][1],minDp[0][2]));
    int max_ans = max(maxDp[0][0],max(maxDp[0][1],maxDp[0][2]));

    cout<<max_ans<<" "<<min_ans;

}