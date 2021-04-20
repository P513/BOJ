#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems)
{
    map<string, int>::iterator iter;
    vector<int> answer;
    vector<string> kinds;
    // map<보석 종류, 보석 개수>
    map<string, int> m;
    // kinds는 gem의 종류 분류용
    kinds = gems;
    sort(kinds.begin(), kinds.end());
    kinds.erase(unique(kinds.begin(), kinds.end()), kinds.end());
    for (auto i : kinds)
    {
        m.insert(make_pair(i.c_str(), 0));
    }
    // n은 진열대 길이
    int n = gems.size();
    // o은 종류 개수
    int o = kinds.size();
    // start index
    int s_idx = 0;
    // window size
    int window = o;
    // end index
    int e_idx = o + window - 1;
    for (int i = 0; i < window; i++)
    {
        m[gems[i + s_idx]]++;
    }
    // sliding window size
    while (e_idx < n)
    {
        bool ans = 1;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->second < 1)
            {
                ans = 0;
                break;
            }
        }
        if (ans)
        {
            answer.push_back(s_idx);
            answer.push_back(e_idx);
            break;
        }
        m[gems[e_idx + 1]]++;
        m[gems[s_idx - 1]]--;
    }
    return answer;
}