// #520A.cpp
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
const int MAXN = 105;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    char str[MAXN];
    int n;
	while(~scanf("%d",&n)) {
		scanf("%s",str);
		bool vis[26] = {false};
		for (int i = 0; i < n; ++i) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				vis[str[i]-'a'] =true;
			}
			else {
				vis[str[i]-'A'] = true;
			}
		}
		int i;
		for (i = 0; i < 26; ++i) {
			if(vis[i] == false) {
				break;
			}
		}
		if(i == 26) {
			cout << "YES" <<endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}