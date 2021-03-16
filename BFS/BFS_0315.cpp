#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace  std;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
int n, m,k,t;
int pang[302][302];
int day[302][302];
queue<pair<int,int>> q;

void bfs(){
   while(t--) {
       int co = q.size();
       while (co--) {
           int qx = q.front().first;
           int qy = q.front().second;
           q.pop();
           pang[qx][qy] = -1;
           for (int i = 0; i < 8; i++) {
               int nx = qx + dx[i];
               int ny = qy + dy[i];
               if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
                   if (pang[nx][ny] == -1) {
                        cout<<nx<<" "<<ny<<"\n";
                        q.push(make_pair(nx,ny));
                        pang[nx][ny] = 1;
                   }
               }
           }
       }
   }
}

int main() {

    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            pang[i][j] = -1;
        }
    }
    cin>> m>>k>>t;

    int mx,my;
    for(int i = 0; i < m; i++){
        cin>>my>>my;
        q.push(make_pair(mx,my));
        pang[my][my] = 1;
    }

    vector<pair<int,int>> p;
    int kx,ky;
    for(int i = 0; i <k; i++){
        cin>>kx>>ky;
        p.push_back(make_pair(kx,ky));
    }


    bfs();

    bool flag = false;
    for(int i = 0; i < k; i++){
        int kx = p[i].first;
        int ky = p[i].second;
        if(pang[kx][ky] == 1){
            flag = true;
            break;
        }
    }

    if(flag == true){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    return 0;
}