#include <bits/stdc++.h>

using namespace std;

int n, d;

#define money first
#define factor second

pair<int, int> friends[100001];

int main () {

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &friends[i].money, &friends[i].factor);

	sort(friends, friends + n);

	long long res = 0ll;

	int l = 0;
	long long cur_factor = 0ll;
	for (int i = 0; i < n; i++) {
		int r = i;
		cur_factor += friends[i].factor + 0ll;
		while (l <= r && friends[r].money - friends[l].money >= d) {
			cur_factor -= friends[l].factor + 0ll;
			l++;
		}
		res = max(res, cur_factor);
	}

	cout << res;

	return 0;
}




