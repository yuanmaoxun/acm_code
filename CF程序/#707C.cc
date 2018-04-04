// #707C.cpp
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
LL n;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    LL ans,res;
	while(~scanf("%lld",&n)) {
		if (n == 1 || n == 2) {
			printf("-1\n");
			continue;
		}
		if(n & 1){
			LL x = n/2;
			ans = 2*x*x+2*x;
			res = 2*x*x + 2*x+1;
		}
			
		if (!(n&1)) {
			LL x = n/2;
			ans = x*x-1;
			res = x*x+1;
		}
		printf("%lld %lld\n",ans,res );
	}
	return 0;
}