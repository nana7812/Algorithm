//유니온 파인드(합집합 찾기 _여러개의 노드가 존재할 때 두개의 노드를 선택해서, 현재 두 노드가 서로 같은 그래프에 속하는지 판별)_크루스칼에 사용 됨
//배열에 부모노드 저장

//부모노드를 찾는 함수
int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent,parent[x]);
}

//두 부모 노드를 합치는 합수
int unionParent(int parent[],int a, int b){
    a = getParent(parent,a);
    b= getParent(parent,b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

//같은 부모를 가지는지 호가인
int findParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a==b) return 1;
    else return 0;
}

int main() {

    return 0;
}ch