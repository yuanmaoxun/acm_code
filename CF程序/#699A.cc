// #699A.cpp
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
const int MAXN = 200005;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n;
    char str[MAXN];
    int x;
   
	while(~scanf("%d",&n)) {
		int Min = 1000000004;
		stack <int> S;
		scanf("%s",str);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&x);
			if (str[i] == 'R') {
				S.push(x);
			}
			else {
				if(!S.empty()) {
					int Top = S.top();
					S.pop();
					Min = min(Min,(x-Top)/2);
				}
			}
		}
		// cout << Min <<endl;
		if(Min == 1000000004) {
			printf("-1\n");
		}
		else {
			printf("%d\n", Min);
		}

	}
	return 0;
}