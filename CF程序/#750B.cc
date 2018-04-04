// #750B.cpp
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
    int n;
    int d[55];
    string st[55];
	while(~scanf("%d",&n)) {
		LL sum1 = 0;
		LL sum3 = 0;
		LL sum4 = 0;
		LL sum2 = 0;
		bool flag = 1;
		for (int i = 0; i < n; ++i) {
			cin >> d[i] >> st[i];
		}
		for (int i = 0; i < n; ++i) {
			int dis = d[i];
			string str = st[i];
			if (sum1 == 0 && str != "South") {
				flag = 0;
				printf("NO\n");
				break;
			}
			if (sum2 == 20000 && str != "North") {
				flag = 0;
				printf("NO\n");
				break;
			}
			if (str == "South") {
				sum1 += dis%40000;
				if (sum1 > 20000) {
					sum1 = -(sum1-20000);
				}
			}
			if (str == "North") {
				sum2 += dis%40000;
				if (sum2 > 20000) {
					sum2 = -(sum2-20000);
				}
			}
			if (str == "West") {
				sum3 += dis%40000;
				if (sum3 > 20000) {
					sum3 = -(sum3-20000);
				}
			}
			if (str == "East") {
				sum4 += dis%40000;
				if (sum4 > 20000) {
					sum4 = -(sum4-20000);
				}
			}
		}
		printf("%d %d %d %d\n",sum1,sum2,sum3,sum4);
		if (sum1 == sum2 ) {
			printf("YES\n");
		}
		else{
			if(!flag){
				printf("NO\n");
			}
		}
	}
	return 0;
}