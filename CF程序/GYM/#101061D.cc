// #101061D.cpp
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
const int MAXN = 10 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int num[MAXN];
	while(~scanf("%d",&T)) {
		while(T--) {
			for (int i = 0; i < 5; ++i) {
				scanf("%d",&num[i]);
			}
			sort(num,num+5);
			LL ans = num[4] * num[3];
			printf("%lld\n", ans);
		}
	}
	return 0;
}