# 문제

Ursula is a big fan of constructing artificial languages. Today, she is starting to work on a language inspired by real Polynesian languages. The only rules she has established are:

All words consist of letters. Letters are either consonants or vowels.
Any consonant in a word must be immediately followed by a vowel.
For example, in a language in which a is the only vowel and h is the only consonant, a, aa, aha, aaha, and haha are valid words, whereas h, ahh, ahah, and ahha are not. Note that the rule about consonants disallows ending a word in a consonant as well as following a consonant with another consonant.

If Ursula's new language has C different consonants and V different vowels available to use, then how many different valid words of length L are there in her language? Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109+7 (1000000007).

https://www.acmicpc.net/problem/12037

https://www.acmicpc.net/problem/12038

https://www.acmicpc.net/problem/12039

## 문제 분류

다이나믹 프로그래밍

## 입출력 예시

<table>
  <tr>
    <th>입력</th>
    <th>출력</th>
  </tr>
  <tr>
    <td>2<br>1 1 4<br> 1 2 2</td>
    <td>Case #1: 5<br>Case #2: 6</td>
  </tr>
</table>

# 풀이

DP로 푸는 문제다. 역시 중요한 것은 점화식을 세우는 것이다.

## 나는 ..

세 문제 모두 한 문제에서 조건만 다른데 DP로 푼다면 세 문제 다 정답을 얻을 수 있다.

먼저 문제는 길이가 L인 문자열을 만들고자 할 때, 자음 다음에 무조건 모음이 와야 한다.

자음 자음도 불가능하다.

점화 식을 세울 때 뒤에 모음을 붙이는 것을 생각했는데, 자음을 어떻게 할 지 난감했다.

하지만 생각하다보니 2 번째 전 문자열 만드는 곳에서 자음 모음을 붙이는 게 떠올랐다.

str[i]는 길이가 i이고 위의 조건을 만족하는 문자열 개수다.

str[i]=str[i-1]*모음+str[i-2]*자음*모음 의 식이 나온다.