// 이전 제출 코드 (SET 활용)
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
string words[20020];
char word[51];
set<string> ans;

bool cmp(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word);
		words[i] = word;
	}

	sort(words, words + n, cmp);
	unique(word, word + n);

	for (int i = 0; i < n; i++) {
		if (ans.count(words[i])) { continue; }
		else { printf("%s\n", words[i].c_str()); ans.insert(words[i]); }

	}
	return 0;
}

// string vector 활용 코드 (속도 더 빠름)
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> words;
char word[51];

bool cmp(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word);
		words.push_back(word);
	}

	sort(words.begin(), words.end(), cmp);
	words.erase(unique(words.begin(), words.end()), words.end());

	for (auto i : words) {
		printf("%s\n", i.c_str());
	}
	return 0;
}