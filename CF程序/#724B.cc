// #724B.cpp
#include <bits/stdc++.h>
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int MAXN = (int)1e9 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
	int num[25][25];
	int sum[25];
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		CLEAR(sum,0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d",&num[i][j]);
				if (num[i][j] != j+1) {
					sum[i]++;
				}
			}
		}
		
		int i;
		for (i = 0; i < n; ++i) {
			if (sum[i] > 2) {
				break;
			}
		}
		if (i == n) {
			puts("YES");
			continue;
		}
		CLEAR(sum,0);
		bool flag = false;
		for (int i = 0; i < m; ++i) {
			for (int j = i+1; j < m; ++j) {
				CLEAR(sum,0);
				for (int a = 0; a < n; ++a) {
					swap(num[a][i],num[a][j]);
					for (int b = 0; b < m; ++b) {
						if (num[a][b] != b+1) {
							sum[a]++;
						}
					}
					swap(num[a][i],num[a][j]);
				}
				int a;
				for (a = 0; a < n; ++a) {
					if (sum[a] > 2) {
						break;
					}
				}
				if (a == n) {
					flag = true;
				}
			}
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}
	return 0;
}