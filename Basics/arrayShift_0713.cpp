#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;





int main() {

    int a[3][3];
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            k++;
            a[i][j] = k;
        }
    }
    
    
  //  왼쪽으로 1만
    for (int i = 0; i < 3; i++) {
    reverse(a[i], a[i] + 1);
    reverse(a[i] + 1, a[i] + 3);
    reverse(a[i], a[i] + 3);
    }
    //오른쪽으로 1만큼
    for(int i = 0; i <3; i++){
        reverse(a[i]+2,a[i]+3);
        reverse(a[i],a[i]+2);
        reverse(a[i],a[i]+3);
    }
    //위로 1만큼 이동
    reverse(a,a+1);
    reverse(a+1,a+3);
    reverse(a,a+3);

   // 아래로 1만큼 이동
      reverse(a+2,a+3);
      reverse(a,a+2);
      reverse(a,a+3);

      
    for(int i = 0; i <3; i++){
        for(int j = 0; j <3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    return 0;
}