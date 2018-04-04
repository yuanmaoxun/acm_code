// #709B.cpp
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
const int MAXN = (int)1e5 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n,a;
    int num[MAXN];
	while(~scanf("%d%d",&n,&a)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d",&num[i]);
		}
		if (n == 1) {
			printf("0\n");
			continue;
		}
		sort(num,num+n);
		int ans1 = abs(num[n-1]-a)+abs(num[n-1]-num[1]);
		int ans2 = abs(num[n-2]-a) + abs(num[n-2]-num[0]);
		int ans3 = abs(a-num[0]) + abs(num[0]-num[n-2]);
		int ans4 = abs(a-num[1]) + abs(num[1]-num[n-1]);
		// cout << ans1 <<" "<<ans2 <<" "<<ans3<<" "<<ans4<<endl;
		LL sum = min(min(min(ans1,ans2),ans3),ans4);
		printf("%lld\n",sum);
	}
	return 0;
}