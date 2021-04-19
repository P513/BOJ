#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;
    // n은 차량 수
    int n = routes.size();
    sort(routes.begin(), routes.end());
    // 카메라 설치 마지노선
    int dist = routes[0][1];
    for (int i = 0; i < n; i++)
    {
        if (routes[i][1] < dist)
        {
            dist = routes[i][1];
        }
        else if (routes[i][0] > dist)
        {
            answer++;
            dist = routes[i][1];
        }
    }
    return answer;
}