#include <iostream>
using namespace std;

int N,M;
int a[500][500];

int main(){
    cin >> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
        }
    }
    int answer = 0;
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(j+3 < M){
                temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
                if(temp > answer) answer = temp; 
            }
            if(i + 3 < N){
                temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j+1 < M){
                temp = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
                if(temp > answer) answer = temp;
            }
            if(i + 2 < N && j + 1 < M){
                temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1];
                if(temp > answer) answer = temp;
            }
            if(0<= j-1 && i+2 < N){
                temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j+2 < M){
                temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j-2 >= 0){
                temp = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+1][j-2];
                if(temp > answer) answer = temp;
            }
            if(i + 2 < N && j +1 < M){
                temp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
                if(temp > answer) answer = temp;
            }
            if(i + 1 < N  && j+2 < M){
                temp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
                if(temp > answer) answer = temp;
            }
            if(i + 2  < N && j+1 < M){
                temp = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
                if(temp > answer) answer = temp;
            }
            if(i + 1 < N && j-2 >= 0){
                temp = a[i][j] + a[i+1][j] + a[i][j-1] + a[i][j-2];
                if(temp > answer) answer = temp;
            }
            if(i + 2 < N && j + 1 < M){
                temp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j-1 >= 0 && j+1 < M){
                temp = a[i][j] + a[i][j+1] + a[i+1][j-1] + a[i+1][j];
                if(temp > answer) answer = temp;
            }
            if(i+ 2 < N && j-1 >= 0){
                temp = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+2][j-1];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j+2 < M){
                temp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
                if(temp > answer) answer = temp;
            }
            if(i+1 < N && j +2 < M){
                temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1];
                if(temp > answer) answer = temp;
            }
            if(i+2 < N && j -1 >= 0){
                temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+1][j-1];
                if(temp > answer) answer = temp;
            }
            if(i-1 >= 0 && j +2 < M){
                temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i-1][j+1];
                if(temp > answer) answer = temp;
            }
            if(i + 2 < N && j+1 < M ){
                temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+1][j+1];
                if(temp > answer) answer = temp;
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}