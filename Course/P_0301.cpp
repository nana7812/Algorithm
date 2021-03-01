#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

//<크루스칼 알고리즘> 가장 적은 비용으로 모든 노드를 연결 _최소 비용 신장 트리 [간선 숫자 = 노드 숫자 -1]
//1)오름차순에 맞게 그래프에 포함 2)포함시키기 전에 **사이클 테이블 확인** 3)사이클을 형성하는 경우 간선에 포함하지 않음

const int MAX = 100001;
int n,m;
int set[MAX];
vector<pair<pair<int,int>,int >> e;

bool com(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second < b.second;
}

//부모 노드를 가져오기
int getParent(int x){
    if(set[x] == x) return x;
    return set[x] = getParent(set[x]);
}

//부모가 같은지 확인
int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return 1;
    else return 0;
}

//부모 노드를 병합
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b)  set[b] = a;
    else set[a] = b;
}

int main() {
    cin>> n>> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back(make_pair(make_pair(a,b),c));
    }
    sort(e.begin(),e.end(),com);

    //초기부모  설정
    for(int i = 1; i <= n; i++){
        set[i] = i;
    }

    int sum = 0;
    for(int i = 0; i < m; i++){
        //동일 부모를 가르키기 않는 경우, 즉 사이클 발생 안 함
        if(!find(e[i].first.first,e[i].first.second)){
            sum += e[i].second;
            unionParent(e[i].first.first,e[i].first.second);
        }
    }

    cout<<sum<<"\n";
    return 0;
}