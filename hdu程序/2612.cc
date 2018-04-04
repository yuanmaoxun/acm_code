#include <bits/stdc++.h>

using namespace std;

char str[205][205];
int sumY[206][206],sumM[206][206];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int vis[205][205];

struct Point {
	int x;int y;
	int step;
};

Point Y,M;
int n,m;

int bfs(int x,int y,bool flag) {
	int ans = 0;
	queue<Point> Q;
	Point S,Next;
	S.x = x;S.y = y;S.step = 0;
	Q.push(S);
	while(!Q.empty()) {
		Point Front = Q.front();
		vis[Front.x][Front.y] = 1;
		Q.pop();
		if (flag == 1) {
			if (str[Front.x][Front.y] == '@') {
				ans = Front.step;
				sumY[Front.x][Front.y] = ans;;
			}
		}
		else {
			if (str[Front.x][Front.y] == '@') {
				ans = Front.step;
				sumM[Front.x][Front.y] = ans;
			}
		}
		
		for (int i = 0; i < 4; ++i) {
			int xx = Front.x+dir[i][0];
			int yy = Front.y+dir[i][1];
			if (xx < 0 || yy < 0|| xx >= n || yy >= m || vis[xx][yy] || str[xx][yy] == '#') {
				continue;
			}
			Next.x = xx;
			Next.y = yy;
			Next.step = Front.step+1;
			Q.push(Next);
			vis[xx][yy] =1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vis[i][j] = 0;
		}
	}
}

int main(){

	while(~scanf("%d%d",&n,&m)) {
		for(int i = 0; i < n; i++) {
			scanf("%s",str[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sumM[i][j] = sumY[i][j] = -1;
			}
		}
		int ans = 0xFFFF;
		int ans1,ans2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (str[i][j] == 'Y') {
					bfs(i,j,1);
				}
				if (str[i][j] == 'M') {
					bfs(i,j,0);
				}
			}
		}
		int sum = 0xFFFF;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (str[i][j] == '@' && sumY[i][j] != -1 && sumM[i][j] != -1) {
					sum = min(sum,sumM[i][j]+sumY[i][j]);
				}
			}
		}
		printf("%d\n",sum*11);
	}
	return 0;
}