#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> gems = { "A","B","C","D","D","E" };

vector<int> solution(vector<string> gems)
{
    // 보석 종류(중복 X)
    set<string> kinds(gems.begin(), gems.end());
    vector<int> answer(2);
    // map<보석 종류, 보석 개수>
    unordered_map<string, int> m;
    int s_idx = 0, e_idx = 0;
    int min = 0;
    // 복사가 아닌 참조자
    for (auto& i : gems) {
        m[i]++;
        if (m.size() == kinds.size()) break;
        e_idx++;
    }
    min = e_idx - s_idx;
    answer[0] = s_idx + 1;
    answer[1] = e_idx + 1;
    while (e_idx < gems.size()) {
        // 시작 idx의 jewely
        string jew = gems[s_idx];
        m[jew]--;
        s_idx++;
        if (m[jew] == 0) {
            e_idx++;
            for (; e_idx < gems.size(); e_idx++) {
                m[gems[e_idx]]++;
                if (jew == gems[e_idx])break;
            }
            if (e_idx == gems.size())break;
        }
        if (min > e_idx - s_idx) {
            answer[0] = s_idx + 1;
            answer[1] = e_idx + 1;
            min = e_idx - s_idx;
        }
    }
    return answer;
}

int main() {
    vector <int> ans;
    ans = solution(gems);
    return 0;
}