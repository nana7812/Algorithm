#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int a[25][25];

int main() {

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> v;
    for(int i = 0; i < N; i++){
        if(i < N/2){
            v.push_back(0);
        }else{
            v.push_back(1);
        }
    }

    int answer = 987654321;
    do{

        vector<int> t1;
        vector<int> t2;
        for(int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                t1.push_back(i);
            } else {
                t2.push_back(i);
            }
        }

        int s1 = 0; int s2 = 0;
        for(int i = 0; i < t1.size()-1; i++){
            for(int j = i+1; j < t1.size(); j++){
                s1 += (a[t1[i]][t1[j]] + a[t1[j]][t1[i]]);
                s2 += (a[t2[i]][t2[j]] + a[t2[j]][t2[i]]);
            }
        }

        if(answer > abs(s1-s2)){
            answer = abs(s1 -s2);
        }



    }while(next_permutation(v.begin(),v.end()));


    cout<<answer<<"\n";

    return 0;
}