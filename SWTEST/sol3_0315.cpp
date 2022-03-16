#include <vector>
#include <iostream>
#include <map>
using namespace std;

int N,L;
int a[101][101];

bool check(bool garo,int n){
    vector<int> c(N,false);
    if(garo == true){
        int i = 0;
        while(i < N-1){
            if(a[n][i] - a[n][i+1] == 1){
                int j = i+1;
                int v = a[n][i+1];
                for(int k = 0; k < L; k++){
                    if(j >= N || c[j] || a[n][j] != v){
                       // cout<<n<<"은"<<j<<"에서걸림"<<"\n";
                        return false;
                    }
                    j++;
                }
                j = i+1;
                for(int k = 0; k < L; k++){
                    c[j] = true;
                    j++;
                }
                i += L;
            }else if(a[n][i] - a[n][i+1] == -1){
                int j = i;
                int v = a[n][i];
                for(int k = 0; k < L; k++){
                    if(j < 0 || c[j] || a[n][j] != v){
                       // cout<<n<<"은"<<j<<"에서걸림"<<"\n";
                        return false;
                    }
                    j--;
                }
                j = i;
                for(int k = 0; k < L; k++){
                    c[j] = true;
                    j--;
                }
                i++;
            }else if(a[n][i] - a[n][i+1] == 0){
                i++;
            }else if(abs(a[n][i]-a[n][i+1]) > 1){
               // cout<<n<<"은"<<i<<"에서걸림"<<"\n";
                return false;
            }
        }
    }else{
        int i = 0;
        while(i < N-1){
            if(a[i][n] - a[i+1][n] == 1){
                int j = i+1;
                int v = a[i+1][n];
                for(int k = 0; k < L; k++){
                    if(j >= N || c[j] || a[j][n] != v){
                       // cout<<n<<"은"<<j<<"에서걸림"<<"\n";
                        return false;
                    }
                    j++;
                }
                j = i+1;
                for(int k = 0; k < L; k++){
                    c[j] = true;
                    j++;
                }
                i += L;
            }else if(a[i][n] - a[i+1][n] == -1){
                int j = i;
                int v = a[i][n];
                for(int k = 0; k < L; k++){
                    if(j < 0 || c[j] || a[j][n] != v){
                       // cout<<n<<"은"<<j<<"에서걸림"<<"\n";
                        return false;
                    }
                    j--;
                }
                j = i;
                for(int k = 0; k < L; k++){
                    c[j] = true;
                    j--;
                }
                i++;
            }else if(a[i][n] - a[i+1][n] == 0){
                i++;
            }else if(abs(a[i][n]-a[i+1][n]) > 1){
              //  cout<<n<<"은"<<i<<"에서걸림"<<"\n";
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin>> N>>L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    int answer = 0;

    for(int i = 0; i < N; i++){
        if(check(true,i)){
            answer++;
            //cout<<i <<" "<<"통과"<<" \n";
        }
    }
    for(int i = 0; i < N; i++){
        if(check(false,i)){
            answer++;
            //cout<<i <<" "<<"통과"<<" \n";
        }
    }

    cout<<answer<<" ";
    return 0;
}