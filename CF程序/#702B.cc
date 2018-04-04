// #702B.cpp
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
const int MAXN = 100005;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int array[MAXN];
    int power[MAXN];
    int n;
    power[0] = 1;
    for (int i = 1; power[i-1] <= 2000000000; ++i) {
    		power[i]=power[i-1]*2;
            cout << i <<endl;
    }
    while(~scanf("%d",&n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d",&array[i]);
        }
        sort(array,array+n);
        LL ans = 0;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j <= 31; ++j) {
                if(power[j] - array[i] >0) {
                    ans += upper_bound(array+i+1,array+n,power[j] - array[i] ) - lower_bound(array+i+1,array+n,power[j] - array[i] );
                }
            }
        }
        printf("%lld\n", ans);
    }
	
	return 0;
}