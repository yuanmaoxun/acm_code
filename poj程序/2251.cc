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

#define Maxn 100005
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

int L,R,C;
int shortesttime;
struct Map{
    int l,r,c;
    int step;
}S,E;

int dir[6][3] = { 0,1,0, 0,-1,0, 0,0,1, 0,0,-1, 1,0,0, -1,0,0};
char str[35][35][35];
bool visit[35][35][35];

bool bfs(int x,int y,int z) {
    Map Front, next;
    Map Start;
    queue<Map> Q;
    Start.l = x;Start.r = y;Start.c = z;
    Start.step = 0;
    visit[x][y][z] = true;
    Q.push(Start);
    while(!Q.empty()) {
        Front = Q.front();
        if(Front.l == E.l && Front.r == E.r && Front.c == E.c) {
            shortesttime = Front.step;
            return true;
        }
        Q.pop();
        for(int i = 0; i < 6; i++) {
            int xx = Front.l + dir[i][0];
            int yy = Front.r + dir[i][1];
            int zz = Front.c + dir[i][2];
            if(xx>=L || yy>=R || zz>=C || xx<0 || yy<0 || zz<0 || visit[xx][yy][zz] || str[xx][yy][zz] == '#'){
                continue;
            }
            next.l = xx; next.r = yy; next.c = zz;next.step = Front.step+1;
            if(next.l == E.l && next.r == E.r && next.c == E.c) {
                shortesttime = next.step;
                return true;
            }
            Q.push(next);
            visit[xx][yy][zz] = true;
        }
    }
    return false;
}

int main(){
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE

    while(~scanf("%d%d%d",&L,&R,&C)) {
        if(L==0 && R==0 && C==0)
            break;
        shortesttime = 0;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                scanf("%s",str[i][j]);
            }
        }
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++){
                    if(str[i][j][k] == 'S'){
                        S.l = i;S.r = j;S.c = k;
                    }
                    if(str[i][j][k] == 'E') {
                        E.l = i;E.r = j;E.c = k;
                    }
                }
            }
        }
        Clear(visit,false);
        if(bfs(S.l,S.r,S.c)) {
            printf("Escaped in %d minute(s).\n",shortesttime);
        }
        else{
            printf("Trapped!\n");
        }
    }
return 0;
}





