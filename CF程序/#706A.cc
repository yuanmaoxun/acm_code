
// #706A.cpp
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
const int MAXN = 1000 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int a,b;
    int n;
    int x,y,v;

	while(~scanf("%d%d",&a,&b)) {
		double ans[MAXN];
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d",&x,&y,&v);
			ans[i] = sqrt((x-a)*(x-a) + (y-b)*(y-b))*1.0/v;
		}
		sort(ans,ans+n);
		printf("%.20lf\n",ans[0]);
	}
	return 0;
}