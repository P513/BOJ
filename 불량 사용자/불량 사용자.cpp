#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// 노드에 방문했는지
int visited[9];
int n;

set<set<string>> sets;

int same(string a, string b) {
    if (a.size() != b.size()) return 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i] || b[i] == '*') continue;
        else return 0;
    }
    return 1;
}

void dfs(vector<string> user_id, vector<string> banned_id, int cnt, set<string> set) {
    if (set.size() == n) {
        sets.insert(set);
        set.clear();
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        if (visited[i]) continue;
        else {
            visited[i] = 1;
            if (same(user_id[i], banned_id[cnt]) && !set.count(user_id[i])) {
                set.insert(user_id[i]);
                dfs(user_id, banned_id, cnt + 1, set);
                set.erase(set.find(user_id[i]));
            }
            visited[i] = 0;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n = banned_id.size();
    set<string> set;
    dfs(user_id, banned_id, 0, set);
    answer = sets.size();
    return answer;
}