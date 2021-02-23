#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;
const int MAX = 6;

int n, m;
int a[MAX][MAX];
bool check[MAX][MAX];

int max_sum = 0;
void solve(int i, int j , int sum) {

    if(j  >= m){
        i++;
        j = 0;
    }
    if(i >= n){
        if(sum > max_sum){
            max_sum = sum;
        }
        return;
    }
    if (check[i][j] == false) {
        if (i + 1 < n && j - 1 >= 0) {
            if(check[i][j-1] == false && check[i+1][j]== false) {
                int temp = a[i][j - 1] + (2 * a[i][j]) + a[i + 1][j];
                check[i+1][j] = true;
                check[i][j-1] = true;
                check[i][j] = true;
                solve(i,j+1,sum+temp);
                check[i+1][j] = false;
                check[i][j-1] = false;
                check[i][j] = false;
            }
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            if(check[i][j-1] == false && check[i-1][j] == false){
                int temp = a[i][j-1] + (2 * a[i][j]) + a[i-1][j];
                check[i][j] = true;
                check[i][j-1] = true;
                check[i-1][j] = true;
                solve(i,j+1,sum+temp);
                check[i][j] = false;
                check[i][j-1] = false;
                check[i-1][j] = false;
            }
        }
        if (i - 1 >= 0 && j + 1 < m) {
            if(check[i-1][j] == false && check[i][j+1] == false){
                int temp = a[i-1][j] + (2 * a[i][j]) + a[i][j+1];
                check[i][j] = true;
                check[i-1][j] = true;
                check[i][j+1] = true;
                solve(i,j+1,sum+temp);
                check[i-1][j] = false;
                check[i][j+1] = false;
                check[i][j] = false;
            }
        }
        if (i + 1 < n && j + 1 < m) {
            if(check[i][j+1] == false && check[i+1][j] == false){
                int temp  = a[i][j+1] + (2* a[i][j]) + a[i+1][j];
                check[i+1][j] = true;
                check[i][j+1] = true;
                check[i][j] = true;
                solve(i,j+1,sum+temp);
                check[i+1][j] = false;
                check[i][j+1] = false;
                check[i][j] = false;
            }
        }
    }

    solve(i,j+1,sum);

}


int main() {
    cin>> n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    solve(0,0,0);

    cout<<max_sum<<"\n";


    return 0;
}