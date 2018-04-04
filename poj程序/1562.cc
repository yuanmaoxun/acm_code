//
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 105
#define Maxm 500
#define Mod 1000000007
#define Clear(name, num) memset(name, num, sizeof(name));
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int dir[8][2] = { {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };
bool vis[Maxn][Maxn];
char str[Maxn][Maxn];
int ans, i, m, n ;

void dfs(int x, int y ) {
    str[x][y] = '*';
    for(int i = 0; i < 8; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx < 0 || yy < 0 || xx >= m || yy >= n )
            continue;
        if(str[xx][yy] == '@')
            dfs(xx, yy);
    }
}

int main(){
    int t, j, k;
    int res, sum, key, len;
    int year, mon, day;
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin >> m >> n) {
        ans = 0;
        if(m == 0) break;
        for(i = 0; i < m; i++)
            scanf("%s", str[i]);
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(str[i][j] == '@') {
                    dfs(i, j);
                    ans++;
                }
        cout << ans  << endl;
    }
return 0;
}




