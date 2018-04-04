// #549A.cpp
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
    string name = "acef";
    char str[55][55];
    int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 0; i < n; i++) {
			scanf("%s",str[i]);
		}
		char tmp[4];
		int ans = 0;
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < m-1; j++) {
				tmp[0] = str[i][j];
				tmp[1] = str[i][j+1];
				tmp[2] = str[i+1][j];
				tmp[3] = str[i+1][j+1];
				sort(tmp,tmp+4);
				if(tmp[0] =='a' && tmp[1] == 'c' && tmp[2] == 'e' && tmp[3] == 'f')
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}