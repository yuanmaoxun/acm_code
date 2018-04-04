// #716B.cpp
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
	int n,c;
	int num[100005];
	while(~scanf("%d%d",&n,&c)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d",&num[i]);
		}

		int sum = 1;
		for (int i = 1; i < n; ++i) {
			if(num[i] - num[i-1] > c) {
				sum = 1;
			}else {
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}