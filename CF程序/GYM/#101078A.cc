// #101078A.cpp
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

    int T;
    int num1[100005],num2[100005];
    int n;
    while(~scanf("%d",&T)) {
    	while(T--) {
    		scanf("%d",&n);
    		for (int i = 0; i < n; ++i) {
    			scanf("%d",&num1[i]);
    		}
    		for (int i = 0; i < n; ++i) {
    			scanf("%d",&num2[i]);
    		}
    		int sum1 = 0;
    		int sum2 = 0;
    		int ans1 = 0;
    		int ans2 = 0;
    		int res1 = 1;
    		int res2 = 1;
    		int index = 0;
    		for (int i = 0; i < n; ++i) {
    			sum1 += num1[i];sum2 += num2[i];
    			ans1 ^= num1[i];ans2 ^= num2[i];
    			res1 *= num1[i] + (233^n)+666;
    			res2 *= num2[i] + (233^n)+666;
    			if (sum1 != sum2 || ans1 != ans2 || res1 != res2) ;
    			else {
    				printf("%d-%d ",index+1,i+1);
    				index = i+1;
    				sum1 = sum2 = ans1 = ans2 = 0;
    				res1 = res2 = 1;
    			}
    		}
    		puts("");
    	}
    }
	
	return 0;
}