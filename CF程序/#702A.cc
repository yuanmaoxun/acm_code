// #702A.cpp
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
    int arr[MAXN];
    int n;
	while(~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		int count = 1;
		int temp = arr[0];
		int Max = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i] > temp) {
				count++;
				temp = arr[i];
			}
			else {
				Max = max(Max,count);
				count=1;
				temp = arr[i];
			}
		}
		Max = max(Max,count);
		printf("%d\n", Max);
	}
	return 0;
}