// #721B.cpp
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
    int n;
    char str[105];
	while(~scanf("%d",&n)) {
		scanf("%s",str);
		int ans[10005];
		int k =0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'B') {
				sum++;
			}
			else {
				if(sum == 0)
					continue;
				ans[k++] = sum;
				sum = 0;			
			}
		}
		if(sum) {
			ans[k++] = sum;
		}
		printf("%d\n",k);
		for (int i = 0; i < k; ++i) {
			if (i == k-1) {
				printf("%d\n",ans[i]);
			}
			else
				printf("%d ",ans[i]);
		}
	}
	return 0;
}