#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r,c,k;
int N, M;
vector<vector<int>> arr(101,vector<int>(101,0));
vector<vector<int>> temp;

bool compare(pair<int,int> a, pair<int,int> b){ //first - 숫자 ,second - 등장횟수
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int sortArr(vector<int> v,bool garo, int idx){
   // cout<<"-----"<<idx<<"--------"<<"\n";
//    for(int i = 0; i < v.size(); i++){
//        cout<<v[i]<<" ";
//    }
  //  cout<<"\n";

    map<int,int> m;
    for(int i = 0; i < v.size(); i++){
        m[v[i]]++;
    }
    vector<pair<int,int>> vv;
    for(auto itr = m.begin(); itr != m.end(); itr++){
        vv.push_back({itr->first,itr->second});
    }
    sort(vv.begin(),vv.end(),compare);


    for(int i = 0; i < vv.size(); i++){
        if(i == 50) break;
        if(garo){
           temp[idx][i*2+0] = vv[i].first;
           temp[idx][i*2+1] = vv[i].second;
        }else{
            temp[i*2+0][idx] = vv[i].first;
            temp[i*2+1][idx] = vv[i].second;
        }
        //cout<<vv[i].first<<" "<<vv[i].second<<" ";
    }

    //cout<<"\n";


    return vv.size() * 2;
}

int main() {
    int answer = -1;

    cin>> r>> c>> k;
    r--; c--;
    N = 3; M = 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>arr[i][j];
        }
    }

    if(arr[r][c] == k){
        cout<<0<<"\n";
        return 0;
    }

    int T = 0;
    while(true){
        T++;
        if(T > 100) break;
        temp = vector<vector<int>>(101,vector<int>(101,0));
//        for(int i = 0; i < N; i++){
//            for(int j = 0; j < M; j++){
//                cout<<temp[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
        if(N >= M){
            //cout<<"행이 큼 "<<"\n";
            int MM = 0;
            for(int i = 0; i < N; i++){
                vector<int> t;
                for(int j = 0; j < M; j++){
                    if(arr[i][j] == 0) continue;
                    t.push_back(arr[i][j]);
                }
                int tempM = sortArr(t,true,i);
                if(MM <tempM){
                    MM = tempM;
                }
            }

            M = MM;
        }else{
           // cout<<"열 이 큼 "<<"\n";
            int NN = 0;
            for(int i = 0; i < M; i++){
                vector<int> t;
                for(int j = 0; j < N; j++){
                    if(arr[j][i] == 0) continue;
                    t.push_back(arr[j][i]);
                }
                int tempN = sortArr(t,false,i);
                if(NN <tempN){
                    NN = tempN;
                }

            }
            N = NN;
        }

        if(temp[r][c] == k){
            answer = T;
            break;
        }

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                arr[i][j] = temp[i][j];
            }
        }

//        cout<<"하번 클리어"<<"\n";
//        for(int i = 0; i < N; i++){
//            for(int j = 0; j < M; j++){
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<"\n";
//        }

    }

    cout<<answer <<"\n";

    return 0;
}