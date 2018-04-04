// D.cpp
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

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
struct Map {
	int t;
	int x,y;
	int l;
	int r;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
	int n,m,t;
	int r,c,a,b;
	while(~scanf("%d%d%d",&n,&m,&t)) {
		Map M[105][105];
		bool vis[105][105] = {false};

		for (int i = 0; i < t; ++i) {
			scanf("%d%d%d%d",&r,&c,&a,&b);
			M[r][c].l = a;
			M[r][c].r = b;
		}
		Map Start,Front;
		Start.t = 0;Start.x = 1;Start.y = 1;

		queue<Map> Q;
		Q.push(Start);
		while(!Q.empty()) {
			Front = Q.front();
			Q.pop();
			if(Front.x == n && Front.y == m) {
				break;
			}
			Map temp ;
			temp.t = Front.t+1;
			for (int i = 0; i < 4; ++i) {
				int xx = Front.x+dir[i][0];
				int yy = Front.y+dir[i][1];
				if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (temp.t < M[xx][yy].l || temp.t > M[xx][yy].r) && !vis[xx][yy]) {
					vis[xx][yy] = true;
					temp.x = xx;
					temp.y = yy;
					Q.push(temp);
					// cout << xx <<" "<< yy <<" "<< temp.t <<endl;
				}
			}
		}
		printf("%d\n",Front.t);
	}
	return 0;
}