#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void DFS(int Idx, int Cnt, int Target_Cnt, int &Max_Cnt, vector<bool> &Select, vector<char> &Select_Type, vector<char> Cnd, vector<string> orders, vector<string> &Res)
{
    if (Cnt == Target_Cnt)
    {
        int Result_Cnt = 0;
        string Result_Type = "";
        for (int i = 0; i < Select_Type.size(); i++) Result_Type += Select_Type[i];
        for (int i = 0; i < orders.size(); i++)
        {
            bool Flag = true;
            for (int j = 0; j < Select_Type.size(); j++)
            {
                if (orders[i].find(Select_Type[j]) == -1)
                {
                    Flag = false;
                    break;
                }
            }
            if (Flag == true) Result_Cnt++;
        }

        if (Result_Cnt < 2 || Result_Cnt < Max_Cnt) return;
        if (Result_Cnt == Max_Cnt) Res.push_back(Result_Type);
        else if (Result_Cnt > Max_Cnt)
        {
            Max_Cnt = Result_Cnt;
            Res.clear();
            Res.push_back(Result_Type);
        }
        return;
    }

    for (int i = Idx; i < Cnd.size(); i++)
    {
        if (Select[Cnd[i] - 'A'] == true) continue;
        Select[Cnd[i] - 'A'] = true;
        Select_Type.push_back(Cnd[i]);
        DFS(i, Cnt + 1, Target_Cnt, Max_Cnt, Select, Select_Type, Cnd, orders, Res);
        Select_Type.pop_back();
        Select[Cnd[i] - 'A'] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    vector<char> Candidate;
    map<char, int> Visit;
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].length(); j++)
        {
            char C = orders[i][j];
            if (Visit[C] == 0) Visit[C]++;
            else if (Visit[C] == 1)
            {
                Visit[C]++;
                Candidate.push_back(C);
            }
        }
    }
    sort(Candidate.begin(), Candidate.end());

    for (int i = 0; i < course.size(); i++)
    {
        int Max_Cnt = 0;
        vector<bool> Select(27, false);
        vector<char> Select_Type;
        vector<string> Result;
        DFS(0, 0, course[i], Max_Cnt, Select, Select_Type, Candidate, orders, Result);
        for (int j = 0; j < Result.size(); j++) answer.push_back(Result[j]);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
