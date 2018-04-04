// #101061C.cpp
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
#define INF 0xffffff
const double eps = 1e-8;
const int MAXN = 100 + 5;
using namespace std;

pair<int,int> edges[MAXN][MAXN];

pair<int,int> operator + (pair<int,int> a,pair<int,int>b) {
	return pair <int ,int>(a.first+b.first,a.second+b.second); 
}

int n,m;
void Floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(k == i || k == j)
                    continue;
                  edges[i][j] = min(edges[i][j],edges[i][k]+edges[k][j]);
                /*if(edges[i][k].first + edges[k][j].first < edges[i][j].first) {
                    edges[i][j].first = edges[i][k].first + edges[k][j].first;
                    edges[i][j].second = edges[i][k].second+edges[k][j].second;
                }*/
            }
        }
    }
}


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int T;
    int u,v,w,k;
    int x,y;
	while(~scanf("%d",&T)) {
			while(T--) {
				scanf("%d%d",&n,&m);
				for(int i = 1; i <= n; i++){
		            for(int j = 1; j <= n; j++){
		                if(i == j){
		                    edges[i][j].first = edges[i][j].second = 0;
		                }
		                else {
		                    edges[i][j].first = edges[i][j].second = INF;
		                }
		            }
		        }
				for (int i = 0; i < m; ++i) {
					scanf("%d%d%d%d",&u,&v,&w,&k);
					if (k == 1) {
						if (edges[u][v].first > w) {
							edges[u][v].first = min(edges[u][v].first,w);
							edges[v][u].first = min(edges[v][u].first,w);
							edges[u][v].second = min(edges[u][v].second,w);
							edges[v][u].second = min(edges[v][u].second,w);
						}
					}
					if(k ==2) {
						if (edges[u][v].first == 0) {
							edges[u][v].second = min(edges[u][v].second,w);
							edges[v][u].second = min(edges[v][u].second,w);
						}
						else {
							edges[u][v].first = edges[v][u].first = 0;
							edges[u][v].second = edges[v][u].second = w;
						}
					}
				}
				Floyd();
				scanf("%d%d",&x,&y);
				if (edges[x][y].second == INF) {
					printf("-1\n");
				}
				else {
					printf("%d %d\n", edges[x][y].first,edges[x][y].second);
				}
			}
	}
	return 0;
}