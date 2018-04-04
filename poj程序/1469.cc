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
#define Maxn 1005
#define Maxm 5005
#define INF 0x7fffffff
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

int n,p;
int Graph[Maxn][Maxn];  //所构造的二部图
int ans;  //最大匹配数
int sx[Maxn],sy[Maxn];  //path函数所表示的DFS算法中用来标明顶点访问状态的数组
int cx[Maxn],cy[Maxn];  //求得的匹配情况，X集合中的顶点i匹配给Y集合中的顶点cx[i]
/*
从X集合中的顶点出发用深度优先搜索策略寻找增广路
但这种增广路只能使当前的匹配数加1
*/

int path(int u) {
    sx[u] = 1;
    for(int v = 1; v <= n; v++) {
        if( (Graph[u][v] > 0) && (!sy[v]) ) {   //v跟u邻接v未访问过
            sy[v] = 1;
            //如果v没有匹配或者如果v已经匹配了，但从y[v]出发可以找到一条增广路
            if(!cy[v] ||path(cy[v])) {
                //在回退时修改增广路上的匹配，从而是匹配数加1；
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {   //匈牙利算法
    ans = 0;
    memset(cx,0,sizeof(cx));
    memset(cy,0,sizeof(cy));
    //机器A和B最初工作在模式0，所以完成可以工作在模式0的作业不需要重启机器
    for(int i = 1; i <= p; i++) {
        if( !cx[i] ) {
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
            ans += path(i);
        }
    }
    //cout << "ans:" << ans <<endl;
    return 0;
}

int main(){
    int i,j,k,m;
    int u,v;
    int T;

    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d",&p,&n);
            memset(Graph,0,sizeof(Graph));
            for(int i = 1; i <= p; i++) {
                scanf("%d",&m);
                for(int j = 1; j <= m; j++) {
                    scanf("%d",&v);
                    Graph[i][v] = 1;
                }
            }
            MaxMatch();
            //cout << "ans:" << ans <<endl;
            if(ans == p)
                puts("YES");
            else
                puts("NO");
        }
    }
return 0;
}



