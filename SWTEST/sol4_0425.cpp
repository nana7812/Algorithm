#include <iostream>

using namespace std;

int N,B,C;
int a[1000001];


int main() {

    cin >> N;
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }
    cin>> B >> C;

    long long answer = N;
    for(int i = 0; i < N; i++){
        a[i] -= B;
        if(a[i] > 0){
            int cc = a[i] / C;
            answer += cc;
            if(a[i] % C != 0){
                answer += 1;
            }
        }
    }

    cout<<answer<<"\n";

    return 0;

}
