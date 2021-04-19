#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int n = board.size();
    int m = moves.size();
    stack<int> box;
    box.push(101);
    for (auto i : moves)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[j][i - 1])
            {
                if (box.top() == board[j][i - 1] && !box.empty())
                {
                    box.pop();
                    answer += 2;
                }
                else
                {
                    box.push(board[j][i - 1]);
                }
                board[j][i - 1] = 0;
                break;
            }
        }
    }
    return answer;
}