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
    int n,k;
    int num[105];
    char str[105];
    char correct[105];
    int len;
	while(~scanf("%d%d",&n,&k)) {
		for (int i = 0; i < n; ++i) {
			scanf("%s",str);
			num[i] = strlen(str);
		}
		scanf("%s",correct);
		len = strlen(correct);
		sort(num,num+n);
		int l = 1005;
		int r = -1;
		for (int i = 0; i < n; ++i) {
			if (num[i] == len) {
				l = min(l,i+1);
				r = max(r,i+1);
			}
		}
		int Min = (l-1)/k*5+l;
		int Max = (r-1)/k*5+r;
		printf("%d %d\n",Min,Max);
	}
	return 0;
}