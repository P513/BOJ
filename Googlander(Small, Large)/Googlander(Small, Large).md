# 문제

Eric Googlander is a fashion model who performs by walking around on a stage made of squares that form a grid with R rows and C columns. He begins at the leftmost bottom square, facing toward the top edge of the stage, and he will perform by making a series of moves. Googlander knows only the following two moves:

1. Take one step forward in the direction he is currently facing

2. Make a single 90 degree turn to the right, then take one step forward in the new direction he is facing following the turn

(Note that Googlander does not know how to make a 90 degree left turn.)

If a move would take Googlander off of the stage or onto a square he has already visited, that move is unfashionable. Whenever Googlander is in a position for which neither of the two possible moves is unfashionable, he is free to choose either move (independently of any other choices he has made in the past), but he must choose one of them. Whenever one of the possible moves he can make is unfashionable, he must make the other move. If at any point both of the possible moves are unfashionable, the show immediately ends without Googlander making another move. Note that Googlander cannot stop the show early -- he must keep moving until both possible moves become unfashionable.

How many different paths is it possible for Googlander to walk? (Two paths are the same if and only if they visit the same squares in the same order.)

https://www.acmicpc.net/problem/12180

https://www.acmicpc.net/problem/12181

## 문제 분류

다이나믹 프로그래밍

## 입출력 예시

<table>
  <tr>
    <th>입력</th>
    <th>출력</th>
  </tr>
  <tr>
    <td>3<br>1 1<br>1 3<br>3 3</td>
    <td>Case #1: 1<br>Case #2: 1<br>Case #3: 6</td>
  </tr>
</table>

# 풀이

이 문제는 Eric Googlander가 R행 C열의 stage에서 패션쇼를 할 수 있는 경우의 수를 구하는 것이다.

Googlander는 한 방향으로 쭉 가거나 90도 오른쪽으로 회전을 할 수 있다.

만약 배열의 밖으로 나가거나 이미 밟았던 stage라면 더 갈 수 없다.

만약 DP라는 것을 인지하지 않고 풀었다면 dfs나 bfs, 그리고 visited 배열을 만들어서 풀었을 거 같다.

다만 복잡할 뿐더러 시간 복잡도는 O(V^2), 이 때 V는 각 배열의 항이므로 V = R*C 일 것이다.

따라서 DP를 이용해서 R*C만에 푸는 것이 더 효율적이다.

## 나는 ..

이번 DP 문제는 배열을 만들고 각 배열 간 관계를 생각해보았다.

2차원 배열이라 감이 쉽게 잡히지 않았다.

우선, dp[i][j]는 i행 j열인 stage에서 Eric Googlander가 갈 수 있는 path의 개수로 정했다.

그리고 dp[i][1]이나 dp[1][j]는 어떤 i와 j가 오든 1일 것이다.

쭉 가는 path 외의 path는 존재하지 않기 때문에.

i행 j열 stage에서 갈 수 있는 path의 개수는 i-1행 j열 stage에서 갈 수 있는 path + i행 j-1열에서 갈 수 있는 path의 합과 같다.