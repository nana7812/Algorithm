#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int N,L;
int a[105][105];

bool road(vector<int> a){
    vector<bool> c(N,false); //설치 확인
    for(int i = 0; i < N-1;){
        if(abs(a[i]- a[i+1]) > 1){
           // cout<<"1이상"<<i<<"\n";
            return false;
        }
        if(a[i] == a[i+1]){
            i++;
        }else if(a[i] == a[i+1]+1){ //높 -> 낮
            //설치가능한지 미리 확인
            if(i+L >= N) return false;
            for(int j = 1; j <= L; j++){
                if(a[i]-1 != a[i+j] || c[i+j]){
                    //cout<<"높->낮"<<"\n";
                    return false;
                }
            }
            //설치가능하다
            for(int j = 1; j <= L; j++){
                c[i+j] = true;
            }
            i +=L;
        }else if(a[i] == a[i+1]-1){ //낮 -> 높
            //설치가능한지
            if(i-(L-1) < 0) return false;
            for(int j = 0; j <L; j++){
                if(a[i-j] != a[i] || c[i-j]){
                   // cout<<"낮->높"<<"\n";
                    return false;
                }
            }
            //설치가능하다
            for(int j = 0; j < L; j++){
                c[i-j] = true;
            }
            i++;
        }
    }
   //cout<<"통과"<<"\n";
    return true;
}

int main(){
    int T;
    cin>> T;
    while(T--){
        cin >> N>> L;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>>a[i][j];
            }
        }
        int answer = 0;
        vector<int> v(N);
        //가로
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[j] = a[i][j];
            }
            if(road(v)){
               // cout<<"가로"<<i<<"\n";
                answer++;
            }
        }
        //세로
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[j] = a[j][i];
            }
            if(road(v)){
               // cout<<"새로"<<i<<"\n";
                answer++;
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}