#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

//**물건담기 최대 구할때**//
//물건을 나누어 담을 수 있을 때 :그리디//
//물건을 나누어 담을 수 없을 때 :dp(담는경우/담지 않는 경우)//


int w[101];
int v[101];
int d[101][100001];
//d[i][j] = i번째 물건 가방무게j

int main() {
    int N, K;
    cin>> N>> K;
    for(int i = 1; i <= N; i++){
        cin>> w[i]>>v[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(j >= w[i]){
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout<<d[N][K];
}

