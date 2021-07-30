#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0, ih, im, is;
    string h, m, s, ms;
    int process;
    vector<int> start_t, end_t;
    for(int i = 0 ; i < lines.size(); i++)
    {
      lines[i].pop_back();
      h = lines[i].substr(11,2);
      m = lines[i].substr(14,2);
      s = lines[i].substr(17,2);
      ms = lines[i].substr(20,3);
      process = stof(lines[i].substr(24,5)) * 1000;

      ih = stoi(h) * 3600 *1000;
      im = stoi(m) * 60 *1000;
      is = stoi(s) * 1000 + stoi(ms);

      start_t.push_back(ih+im+is-process+1);
      end_t.push_back(ih+im+is);
    }
    for(int i = 0 ; i < lines.size(); i++){
      int end_time = end_t[i] +1000;
      int cnt = 0;
      for(int j = i ;j<lines.size();j++ ){
        if(start_t[j] < end_time) cnt++;
      }
      if(answer<cnt) answer = cnt;
    }

    return answer;
}
