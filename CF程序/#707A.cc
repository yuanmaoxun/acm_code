// #707A.cpp
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
const int MAXN = 10000 + 5;
using namespace std;
    char str[MAXN][MAXN];
    char vis[MAXN][MAXN];
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n,m;

	while(~scanf("%d%d",&n,&m)) {
		getchar();
		for(int i = 0; i< n; i++) {
            gets(str[i]);
		}
		int k;
		for (int i = 0; i < n; ++i) {
			k = 0;
			for(int j = 0; str[i][j] != '\0';j++){
				if(str[i][j] == ' ' || str[i][j] == '\n')
                    continue;
				if(str[i][j] == 'W' || str[i][j] == 'B' || str[i][j] == 'G')
					vis[i][k++] = 1;
				else {
					vis[i][k++] = 0;
				}
			}
		}
		
		bool flag =false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if(vis[i][j] == 0){
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			puts("#Color");
		}
		else
			puts("#Black&White");
	}
	return 0;
}
