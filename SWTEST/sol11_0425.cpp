#include <iostream>
#include <vector>
using namespace std;

int N,L;
int a[105][105];

bool check(vector<int> v){

    vector<bool> c(N, false);
    int h = v[0]; int idx = 1;
    while(true){
        if(abs(h - v[idx]) >= 2){
            return false;
        }
        if(h == v[idx]){ //else
            idx++;
        }else if(h - 1 == v[idx]){ //높 ->낮
            if(idx + L > N) return false;
            for(int j = idx; j < idx + L; j++){
                if(c[j]) return false;
                if(v[j] != v[idx])
                    return false;
            }
            for(int j = idx; j < idx + L; j++){
                c[j] = true;
            }
            h = v[idx];
            idx += L;
        }else if(h+1 == v[idx]){
            if(idx - L < 0) return false;
            for(int j = idx -1; j >= idx - L; j--){
                if(c[j]) return false;
                if(v[j] != h) return false;
            }
            for(int j = idx -1; j >= idx - L; j--){
                c[j] = true;
            }
            h = v[idx];
            idx++;
        }

        if(idx >= N) break;
    }
    return true;
}

int main() {

    cin>> N>> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> a[i][j];
        }
    }

    int answer = 0;
    //가로
    for(int i = 0; i < N; i++){
        vector<int> v;
        for(int j = 0; j < N; j++){
            v.push_back(a[i][j]);
        }
        if(check(v)) answer++;
    }

    //세로
    for(int i = 0; i < N; i++){
        vector<int> v;
        for(int j = 0; j < N; j++){
            v.push_back(a[j][i]);
        }
        if(check(v)) answer++;
    }

    cout<<answer<<"\n";

    return 0;
}
