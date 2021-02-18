#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

bool compare(pair<int, int> a,pair<int, int> b){
    return a.first < b.first;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        int test1, test2;
        for (int i = 0; i < n; i++) {
            cin >> test1 >> test2;
            v.push_back(make_pair(test1, test2));
        }
        sort(v.begin(), v.end(), compare);// 서류 기준으로 정렬
        int ans = 1;
        int t_test2 = v[0].second;//(1 4)
        for (int i = 1; i < n; i++) {
            // (2 5) <- x ,(3 6) <- x ,(4 2) <- 면접 등수가 높아서 +1 하고 면접 기준 점수 갱신   
                if (t_test2 > v[i].second) {
                    ans++;
                    t_test2 = v[i].second;
                }

        }
        cout << ans<<"\n";
    }
}