// #699B.cpp
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
const int MAXN = 1005;
using namespace std;
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    
    
    int n,m;
	while(~scanf("%d%d",&n,&m)) {
		char str[MAXN][MAXN];
		vector<pair< int,int> > v;
		for (int i = 0; i < n; ++i) {
			scanf("%s",str[i]);
		}
		for(int i = 0; i < n; i++) {
			for (int j = 0; j < m; ++j) {
				if (str[i][j] == '*') {
					v.push_back(make_pair(i,j));
				}
			}
		}
		
		int k;
		bool flag = false;
		for (int i = 0; i < n&&!flag; ++i) {
			for (int j = 0; j < m&&!flag; ++j) {
				for (k = 0; k < v.size(); ++k) {
					if(v[k].first!=i&&v[k].second!=j) {
						break;
					}
				}
				if (k == v.size()) {
					printf("YES\n");
					printf("%d %d\n",i+1, j+1);
					flag = true;
				}
			}
		}
		if (!flag) {
			printf("NO\n");
		}
	}
	return 0;
}