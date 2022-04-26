#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int a[105][105];

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {

    int r,c,k;
    cin>>r>>c>>k;

    int N= 3; int M = 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>a[i][j];
        }
    }

    int time = 0;
    while(true){
        if(a[r-1][c-1] == k) break;
        int temp[105][105];
        memset(temp,0,sizeof(temp));
        if(N >= M){
            int mm = 0;
            for(int i = 0; i < N; i++){
                map<int,int> m;
                for(int j = 0; j < M; j++){
                    if(a[i][j] == 0) continue;
                    m[a[i][j]]++;
                }
                vector<pair<int,int>> v;
                for(auto itr = m.begin(); itr != m.end(); itr++){
                    v.push_back({itr->first,itr->second});
                }
                sort(v.begin(),v.end(),compare);
                for(int j = 0; j < v.size(); j++){
                    if(j == 50) break;
                    temp[i][2*j] = v[j].first;
                    temp[i][2*j+1] = v[j].second;
                }
                if(mm < v.size()*2){
                    mm = v.size() *2;
                    if(mm > 100){
                        mm = 100;
                    }
                }
            }
            M = mm;
        }else{
            int nn = 0;
            for(int i = 0; i < M; i++){
                map<int,int> m;
                for(int j = 0; j < N; j++){
                    if(a[j][i] == 0) continue;
                    m[a[j][i]]++;
                }
                vector<pair<int,int>> v;
                for(auto itr = m.begin(); itr != m.end(); itr++){
                    v.push_back({itr->first,itr->second});
                }
                sort(v.begin(),v.end(),compare);
                for(int j = 0; j < v.size(); j++){
                    if(j == 50) break;
                    temp[2*j][i] = v[j].first;
                    temp[2*j+1][i] = v[j].second;
                }

                if(nn < v.size()*2){
                    nn = v.size() *2;
                    if(nn > 100){
                        nn = 100;
                    }
                }
            }
            N = nn;
        }

        memcpy(a,temp,sizeof(temp));

        time++;
        if(time > 100){
            time = -1;
            break;
        }
    }

    cout<<time<<"\n";

    return 0;
}