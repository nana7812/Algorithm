#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;

int N;
ll answer;

ll getMax(vector<vector<ll>> v){
    ll res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res =max(res,v[i][j]);
        }
    }
    return res;
}

vector<vector<ll>> up(vector<vector<ll>> vv){
    vector<vector<bool>> c(N,(vector<bool>(N,false)));

    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(vv[j][i] == 0) continue;
            for(int k = j-1; k >= 0; k--){
                if(vv[k][i] == vv[k+1][i] && !c[k][i]){
                    vv[k][i] *= 2;
                    vv[k+1][i] = 0;
                    c[k][i] = true;
                    break;
                }else if(vv[k][i] == 0){
                    vv[k][i] = vv[k+1][i];
                    vv[k+1][i] = 0;
                }else{
                    break;
                }
            }
        }
    }
    return vv;
}
vector<vector<ll>> down(vector<vector<ll>> vv){
    vector<vector<bool>> c(N,(vector<bool>(N,false)));
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >=0; j--){
            if(vv[j][i] == 0) continue;
            for(int k = j+1; k < N; k++){
                if(vv[k][i] == vv[k-1][i] && !c[k][i]){
                    vv[k][i] *= 2;
                    vv[k-1][i] = 0;
                    c[k][i] = true;
                    break;
                }else if(vv[k][i] == 0){
                    vv[k][i] = vv[k-1][i];
                    vv[k-1][i] = 0;
                }else{
                    break;
                }
            }
        }
    }
    return vv;
}
vector<vector<ll>> left(vector<vector<ll>> vv){
    vector<vector<bool>> c(N,(vector<bool>(N,false)));
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(vv[i][j] == 0) continue;
            for(int k = j-1; k >= 0; k--){
                if(vv[i][k] == vv[i][k+1] && !c[i][k]){
                    vv[i][k] *= 2;
                    vv[i][k+1] = 0;
                    c[i][k] = true;
                    break;
                }else if(vv[i][k] == 0){
                    vv[i][k] = vv[i][k+1];
                    vv[i][k+1] = 0;
                }else{
                    break;
                }
            }
        }
    }
    return vv;
}
vector<vector<ll>> right(vector<vector<ll>> vv){
    vector<vector<bool>> c(N,(vector<bool>(N,false)));
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >= 0; j--){
            if(vv[i][j] == 0) continue;
            for(int k = j+1; k < N; k++){
                if(vv[i][k] == vv[i][k-1] && !c[i][k]){
                    vv[i][k] *= 2;
                    vv[i][k-1] = 0;
                    c[i][k] = true;
                    break;
                }else if(vv[i][k] == 0){
                    vv[i][k] = vv[i][k-1];
                    vv[i][k-1] = 0;
                }else{
                    break;
                }
            }
        }
    }
    return vv;
}
void dfs(vector<vector<ll>> v,int cnt){
    //중단시점
    answer = max(answer,getMax(v));
    if(cnt >= 5){
        return;
    }
    //4가지 방향으로 이동
    dfs(up(v),cnt+1);
    dfs(down(v),cnt+1);
    dfs(left(v),cnt+1);
    dfs(right(v),cnt+1);
}



int main(){

        cin >>N;
        vector<vector<ll>> a(N,vector<ll>(N));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>>a[i][j];
            }
        }

        dfs(a,0);
        cout<<answer<<"\n";

    return 0;
}