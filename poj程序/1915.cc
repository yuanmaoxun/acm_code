
//kengkeng
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#define Maxn 1005
#define Maxm 5005
#define INF 0xffff;
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;

struct Point {
    int x,y;
    int step;
};
int l;
int dir[8][2]= {-1,2, -2,1, 1,2, 2,1, 2,-1, 1,-2, -1,-2, -2,-1};
bool visit[Maxn][Maxn];

Point Start,End;

int bfs(Point point) {
    queue<Point> Q;
    Point next,first;
    visit[point.x][point.y] = true;
    //cout <<point.x <<" "<<point.y<<endl;
    Q.push(point);
    while(!Q.empty()) {
        first = Q.front();
        Q.pop();
        if(first.x == End.x && first.y == End.y) {
            return first.step;
        }

        for(int i = 0; i < 8; i++) {
            int xx = first.x + dir[i][0];
            int yy = first.y + dir[i][1];

            if(xx >= l || yy >= l || xx < 0 || yy < 0||visit[xx][yy])
                continue;
            visit[xx][yy] = true;
            next.x = xx;
            next.y = yy;
            next.step = first.step+1;
            Q.push(next);

        }

    }
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
//    char str[Maxn];
//    int num[Maxn];
    int T;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&l);
            scanf("%d%d%d%d",&Start.x,&Start.y,&End.x,&End.y);
            Start.step = 0;
            Clear(visit,false);
            res = bfs(Start);
            printf("%d\n",res);
        }
    }
return 0;
}





