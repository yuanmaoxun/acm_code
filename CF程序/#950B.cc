// #950B.cpp
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
    int n,m;
    int num1[100005],num2[100005];
	while(~scanf("%d%d",&n,&m)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d",&num1[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d",&num2[i]);
		}
		int index1 = -1;
		int index2 = -1;
		int ans = -1;
		int sum1 = 0;
		int sum2 = 0;
		while(index1 < n && index2 < m) {
			if(sum1 == sum2) {
				ans ++;
				index1++;
				index2++;
				sum1 = num1[index1];
				sum2 = num2[index2];
				continue;
			}
			if(sum1 < sum2) {
				index1++;				
				sum1+=num1[index1];
				continue;
			}
			if(sum2 < sum1) {
				index2++;				
				sum2+=num2[index2];
				continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}