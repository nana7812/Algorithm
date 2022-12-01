#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long fac(int n) // n! 
{
    if (n == 0) return 1;
    return n * fac(n - 1);
}

void func(vector<int>& v, vector<int>& answer, long long& k)
{
    if (v.size() == 1) {
        answer.push_back(v[0]);
        return;
    }

    long long p = fac(v.size() - 1); 
    for (int i = 1; i <= v.size(); ++i) {
        if (i * p >= k) {
            answer.push_back(v[i - 1]); // i번째기 때문에 인덱스론 i-1
            v.erase(v.begin() + i - 1);
            k = k - (i - 1) * p;
            func(v, answer, k);
        }
    }
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1; 

    func(v, answer, k);

    return answer;
}

/*
vector<int> solution(int n, long long k) {
    vector<int> answer;
    for(int i = 0; i < n; i++){
        answer.push_back(i+1);
    }
    
   int cnt = 0;
   do{
       cnt++;
       if(cnt == k) return answer;
   }while(next_permutation(answer.begin(),answer.end()));
    
    return answer;
}
*/