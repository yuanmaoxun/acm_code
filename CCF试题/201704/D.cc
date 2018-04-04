#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u;
	int v;
	int w;
}edges[200005];

int father[100005];

bool cmp(Edge a,Edge b) {
	return a.w <b.w;
}

int find_set(int x) {
	return father[x] == x?x:father[x]=find_set(father[x]);
}

int main(){
	int n,m;
	int a,b,c;
	while(~scanf("%d%d",&n,&m)) {
		
		for (int i = 1; i <= n; ++i) {
			father[i] = i;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d",&a,&b,&c);
			edges[i].u = a;
			edges[i].v = b;
			edges[i].w = c;
		}
		sort(edges,edges+m,cmp);
		for (int i = 0; i < m; ++i) {
			if(find_set(n) == find_set(1)) {
				printf("%d\n",edges[i-1].w);
				break;
			}
			int x = find_set(edges[i].u);
			int y = find_set(edges[i].v);
			father[x] = y;
		}
		//printf("%d\n",Max);
	}

	return 0;
}