#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int solution(vector<vector<int> > land)
{
     int sum[MAX][4];
    for (int i = 0; i < land.size(); i++) {
        if (i == 0) {
            sum[i][0] = land[i][0];
            sum[i][1] = land[i][1];
            sum[i][2] = land[i][2];
            sum[i][3] = land[i][3];
        } else {
            sum[i][0] = max({land[i][0] + sum[i - 1][1], land[i][0] + sum[i - 1][2], land[i][0] + sum[i - 1][3]});
            sum[i][1] = max({land[i][1] + sum[i - 1][0], land[i][1] + sum[i - 1][2], land[i][1] + sum[i - 1][3]});
            sum[i][2] = max({land[i][2] + sum[i - 1][0], land[i][2] + sum[i - 1][1], land[i][2] + sum[i - 1][3]});
            sum[i][3] = max({land[i][3] + sum[i - 1][0], land[i][3] + sum[i - 1][1], land[i][3] + sum[i - 1][2]});

        }
    }

   int ans = max({sum[land.size()-1][0],sum[land.size()-1][1],sum[land.size()-1][2],sum[land.size()-1][3]});
    return ans;
}