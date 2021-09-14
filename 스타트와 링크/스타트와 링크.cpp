#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int power[22][22];

int cal_synerg(int t, vector<int> team) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (team[i] == t && team[j] == t) {
				sum += power[i][j] + power[j][i];
			}
		}
	}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> power[i][j];
		}
	}
	vector<int>team(n, 0);
	for (int i = 0; i < n / 2; i++) {
		team[i] = 1;
	}
	int gap = 2000000;
	int start_team = 0;
	int link_team = 0;
	do {
		start_team = cal_synerg(0, team);
		link_team = cal_synerg(1, team);
		gap = (gap < abs(start_team - link_team) ? gap : abs(start_team - link_team));
	} while (prev_permutation(team.begin(), team.end()));
	cout << gap << endl;
	return 0;
}