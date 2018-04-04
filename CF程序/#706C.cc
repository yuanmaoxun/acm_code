// #704C.cpp
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
const LL MAXN = 0x7fffffffffffff;
using namespace std;

    int n;
    LL dp[2][100005];
    LL c[100005];
    char str[100005];


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif


    std::vector<string> str1;
    std::vector<string> str2;
    while(~scanf("%d",&n)) {
        str1.clear();
        str2.clear();
    	for (int i = 0; i < n; ++i) {
    		scanf("%lld",&c[i]);
    	}
    	for (int i = 0; i < n; ++i) {
    		scanf("%s",str);
    		str1.push_back(str);
    		int len = strlen(str);
    		reverse(str,str+len);
    		str2.push_back(str);
    	}
    	fill(dp[0],dp[0]+n,MAXN);
    	fill(dp[1],dp[1]+n,MAXN);
    	dp[0][0] = 0;
    	dp[1][0] = c[0];
    	for (int i = 1; i < n; ++i) {
    		if (str1[i-1] <= str1[i]) {
    			dp[0][i] = min(dp[0][i],dp[0][i-1]);
    		}
    		if (str1[i-1] <= str2[i]) {
    			dp[1][i] = min(dp[1][i],dp[0][i-1]+c[i]);
    		}
    		if (str2[i-1] <= str1[i]) {
    			dp[0][i] = min(dp[0][i],dp[1][i-1]);
    		}
    		if (str2[i-1] <= str2[i]) {
    			dp[1][i] = min(dp[1][i],dp[1][i-1]+c[i]);
    		}

    	}
    	LL ans = min(dp[0][n-1],dp[1][n-1]);
    	if (ans == MAXN) {
    		printf("-1\n");
    	}
    	else {
    		printf("%lld\n", ans);
    	}
    }
    
	return 0;
}