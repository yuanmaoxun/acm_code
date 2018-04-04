// #101061I.cpp
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
const int MAXN = (int)1e5 + 5;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    char str1[MAXN],str2[MAXN];
    int vis1[26],vis2[26];
	while(~scanf("%d",&T)) {
		while(T--) {
			CLEAR(vis1,0);
			CLEAR(vis2,0);
			scanf("%s",str1);
			scanf("%s",str2);
			int ans = 0;
			for (int i = 0; str1[i]; ++i) {
				vis1[str1[i]-'a']++;
			}
			for (int i = 0; str2[i]; ++i) {
				vis2[str2[i]-'a']++;
			}
			for (int i = 0; i < 26; ++i) {
				ans += abs(vis1[i] - vis2[i]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}