//kengkeng
#include <ios>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdio>
#include <cwchar>
#include <iosfwd>
#include <limits>
#include <locale>
#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <istream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <valarray>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <streambuf>
#include <functional>

#define Maxn 105
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
    char str;
    int step;
};

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

            if(xx > 8 || yy > 8 || xx <= 0 || yy <= 0||visit[xx][yy])
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
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%c%d %c%d",&Start.str,&Start.y,&End.str,&End.y)) {
        getchar();
        Start.x = Start.str - 'a' +1;
        End.x = End.str - 'a' +1;
        Start.step = 0;
        Clear(visit,false);
        res = bfs(Start);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",Start.str,Start.y,End.str,End.y,res);
    }
return 0;
}





