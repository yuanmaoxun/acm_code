// #100792A.cpp
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
const int MAXN = (int)1e7 + 5;
#define Mod 10000000007
using namespace std;

LL quick_mod(LL a, LL b, LL m) {
    LL ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans * a) % m;
            b--;
        }
        b /= 2;
        a = a * a % m;
    }
return ans;
}
    LL num[MAXN];
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif

    LL i,n;
	while(~scanf("%lld",&n)) {
		int k = 0;
		n = n-1;
		for (int i = 1; i*i <= n; ++i) {
			if (n % i) {
				continue;
			}
			num[k++] = i;
			if (n/i!=i) {
				num[k++] = n/i;
			}
		}
		sort(num,num+k);
		for (int i = 0; i < k; ++i) {
			if (i == k-1) {
				printf("%lld\n", num[i]);
			}
			else {
				printf("%d ",num[i] );
			}
		}
	}
	return 0;
}