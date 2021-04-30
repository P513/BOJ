# 문제

"KO-RE-A, KO-RE-A" shout 54.000 happy football fans after their team has reached the semifinals of the FIFA World Cup in their home country. 

But although their excitement is real, the Korean people are still very organized by nature. 

For example, they have organized huge trumpets (that sound like blowing a ship's horn) to support their team playing on the field. 

The fans want to keep the level of noise constant throughout the match. 

The trumpets are operated by compressed gas. 

However, if you blow the trumpet for 2 seconds without stopping it will break. 

So when the trumpet makes noise, everything is okay, but in a pause of the trumpet,the fans must chant "KO-RE-A"! 

Before the match, a group of fans gathers and decides on a chanting pattern. 

The pattern is a sequence of 0's and 1's which is interpreted in the following way: If the pattern shows a 1, the trumpet is blown. 

If it shows a 0, the fans chant "KO-RE-A". To ensure that the trumpet will not break, the pattern is not allowed to have two consecutive 1's in it. 

Given a positive integer n, determine the number of different chanting patterns of this length, i.e., determine the number of n-bit sequences that contain no adjacent 1's. For example, for n = 3 the answer is 5 (sequences 000, 001, 010, 100, 101 are acceptable while 011, 110, 111 are not).

https://www.acmicpc.net/problem/6170

## 문제 분류

다이나믹 프로그래밍

## 입출력 예시

<table>
  <tr>
    <th>입력</th>
    <th>출력</th>
  </tr>
  <tr>
    <td>2<br>3<br>1</td>
    <td><br>Scenario #1: 5<br>Scenario #2:2</td>
  </tr>
</table>

# 풀이

저번에 푼 문제인 'BABBA'와 비슷한 문제다.

1이 연속적으로 2번 이상 나오지 않는 문자열의 개수를 구하는 문제다.

먼저 dp[i]는 길이가 i인 문자열을 만들 때 위의 1이 연속적으로 2번 이상 나오지 않는다는 조건을 만족하는 문자열 개수다.

dp[i]는 dp[i-1]에 0을 붙이거나 dp[i-2]에 01을 붙이는 경우와 같으므로 둘의 합과 같다.

## 나는 ..

유형에 익숙해지자.