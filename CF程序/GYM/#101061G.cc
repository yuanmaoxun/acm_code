// #101061G.cpp
#include <bits/stdc++.h>
#define Mod 1000000007
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

void Extend_gcd(long long a,long long b,long long &x,long long &y) { //a是除数 b为Mod x为答案 注意 减法可能为负的所以x需要+Mod再去模
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    Extend_gcd(b,a%b,y,x);
    y-=x*(a/b);
    return;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    LL n,m;
	while(~scanf("%d",&T)) {
		while(T--) {
			scanf("%lld%lld",&m,&n);
			LL ans = 0;
			LL len = 0;
			LL k = n;
			while(k) {
				k/=10;
				len++;
			}
			if (n == 0) {
				len = 1;
			}
			// cout << len <<endl;
			LL temp = quick_mod(10,len,Mod)-1;
			LL res = (quick_mod(10,len*m,Mod)-1)*n;
			LL x,y;
			Extend_gcd(temp,Mod,x,y);
			x = (x+Mod)%Mod;
			ans = ((res%Mod)*x)%Mod;
			printf("%lld\n", ans);
			}
	}
	return 0;
}