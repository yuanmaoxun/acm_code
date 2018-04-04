// #723C.cpp
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
    int n,m;
    int num[2005];
    int vis[2005];
    int add[2005];
	while(~scanf("%d%d",&n,&m)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&num[i]);
			vis[i] = false;
		}
		int ans = n/m;
		int res = 0;
		for (int i = 1; i <= m; ++i) {
			int temp = 0;
			for (int j = 1; j <= n; ++j) {
				if (num[j] == i) {
					temp++;
					vis[j] = true;
				}
				if (temp == ans) {
					break;
				}
			}
			if (temp < ans) {
				add[i] = (ans-temp);
				res += add[i];
			}
		}
		int index = 1;
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < add[i]; ++j) {
				while(vis[index])index++;
				num[index++] = i;
			}
		}
		printf("%d %d\n", ans,res);
		for (int i = 1; i <= n; ++i) {
			if (i == n) {
				printf("%d\n",num[i]);
			}
			else {
				printf("%d ",num[i]);
			}
		}
	}
	return 0;
}