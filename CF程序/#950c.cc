
// #950c.cpp
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
vector<int> ans[200005];
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[200005];
	while(~scanf("%s",str)) {
		int len = strlen(str);
		int index = 0;
		int Max = 0;
		for (int i = 0; i < len; ++i) {
			if(str[i] == '0') {
				ans[++index].push_back(i+1);
			}
			else {
				if(index == 0) {
					printf("-1\n");
					return 0;
				}
				ans[index--].push_back(i+1);
			}
			Max = max(Max,index);
		}
		if(Max != index){
			printf("-1\n");
			return 0;
		}
		printf("%d\n",Max);
		for (int i = 1; i <= Max; ++i) {
			printf("%d",ans[i].size());
			for (int j = 0; j < ans[i].size(); ++j) {
				printf(" %d",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}