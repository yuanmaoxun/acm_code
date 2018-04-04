// #707B.cpp
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
const int MAXN = 100000 + 5;
using namespace std;

struct Edge {
	int u;
	int v;
	int cost;
}edges[MAXN];

bool cmp (Edge a, Edge b) {
	return a.cost < b.cost;
}

int num[MAXN];

int main(int argc, char const *argv[]) {
	int u,v,l;
	int n,m,k;
	int x;
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
	while(~scanf("%d%d%d",&n,&m,&k)) {
		CLEAR(num,0);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d",&u,&v,&l);
			edges[i].u = u;
			edges[i].v = v;
			edges[i].cost = l;
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d",&x);
			num[x] = 1;
		}
		if (k == 0) {
			printf("-1\n");
			continue;
		}
		sort(edges,edges+m,cmp);
		bool flag = false;
		int Min;
		for (int i = 0; i < m; ++i) {
			// cout << edges[i].u <<" " << edges[i].v <<endl;
			// cout << num[edges[i].u] <<" " << num[edges[i].v] <<endl;
			if(num[edges[i].u] && num[edges[i].v]==0 || (num[edges[i].v] && num[edges[i].u] == 0)){
				flag = true;
				Min = edges[i].cost;
				break;
			}
		}
		if (flag) {
			printf("%d\n", Min);
		}
		else
			printf("-1\n");
	}
	return 0;
}