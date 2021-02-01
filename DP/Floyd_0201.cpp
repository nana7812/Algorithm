#include <iostream>
#include <algorithm>
using  namespace  std;

const int  INF = 987654321;
const int MAX =101;
int n, m;
int d[MAX][MAX];



int main(){
    cin>>n>> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           d[i][j] = INF;
        }
    }

    int a, b,c;
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        d[a][b] = min(d[a][b],c);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j ) continue;
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            if(d[i][j] != INF){
                cout<<d[i][j]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<"\n";
    }
}