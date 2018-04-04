// #722C.cpp
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

int father[100005];

int find_set(int n) {
    return father[n] == n?n:father[n] = find_set(father[n]);
}
    bool vis[100005];
    LL num[100005];
	LL que[100005];
	LL ans[100005];
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n;
    int x;

	while(~scanf("%d",&n)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lld",&num[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&que[i]);
		}
		for(int i = 1; i <= n; i++) {
        	father[i]=i;
    	}
    	CLEAR(vis,0);
    	LL Max = 0;
    	int k = 0;
    	for (int i = n; i >=1 ; --i) {
    		vis[que[i]] = 1;
    		if(vis[que[i]+1]) {
    			int x = find_set(que[i]+1);
    			int y = find_set(que[i]);
    			father[y] = x;
    			num[x] += num[y];
    		}
    		if(vis[que[i]-1]) {
    			int x = find_set(que[i]-1);
    			int y = find_set(que[i]);
    			father[y] = x;
    			num[x] += num[y];
    		}
    		ans[k++] = Max;
    		Max = max(Max,num[find_set(que[i])]);
    	}
    	for (int i = k-1; i >= 0; --i) {
    		printf("%lld\n",ans[i]);
    	}
	}
	return 0;
}