// 3605.cpp
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
#define Maxm 15
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

int nx;  //x的数目
int ny;  //y的数目  //需要对下面的nx，ny进行修改
int Graph[Maxn][Maxm];  //所构造的二部图
int ans;  //最大匹配数
int sx[Maxn],sy[Maxm];  //path函数所表示的DFS算法中用来标明顶点访问状态的数组
int cx[Maxn],cy[Maxm];  //求得的匹配情况，X集合中的顶点i匹配给Y集合中的顶点cx[i]
int vis[Maxn];   //用于标记染色判断是否为二分图  或者是记录每个ny中的点的匹配个数
int capacity[Maxn];
/*
从X集合中的顶点出发用深度优先搜索策略寻找增广路
但这种增广路只能使当前的匹配数加1
*/
//判断是否为二分图
bool judge(int num) {  //num为点的个数
    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    while(!Q.empty()) {
        int Front = Q.front();
        Q.pop();
        int cnext = 1-vis[Front];
        for (int i = 1; i <= num; ++i) {
            if(Graph[Front][i] == 1) {
                if (vis[i] == -1) {
                    Q.push(i);
                    vis[i] = cnext;
                }
                else {
                    if (vis[i] != cnext) {
                        return  1;
                    }
                }
            }
        }
    }
    return 0;
}

bool path(int u) {
    sx[u] = 1;
    for(int v = 0; v < ny; v++) {
        if( (Graph[u][v] > 0) && (!sy[v]) ) {   //v跟u邻接v未访问过
            sy[v] = 1;
            if (vis[v] >= capacity[v]) {
            //如果v没有匹配或者如果v已经匹配了，但从y[v]出发可以找到一条增广路
	            if(cy[v] == -1 || path(cy[v])) {
	                //在回退时修改增广路上的匹配，从而是匹配数加1;
	                cx[u] = v;
	               	cy[v] = u;
	               	vis[v]++;
	               	return true;
	            }
            }
            else {
            	vis[v]++;
            	cx[u] = v;
	            cy[v] = u;
            	return true;
        	}
        }
    }
    return false;
}

bool solve() {   //匈牙利算法
    ans = 0;                //求最大匹配数
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    //从0匹配开始增广，将cx和cy个元素初始化为-1
    for(int i = 0; i < nx; i++) {
        if( cx[i] == -1) {  //从每个未盖点出发寻找增广路
            memset(sy,0,sizeof(sy));
            bool res = path(i);   //每找到一条增广路，可以使匹配数+1
        }
    }
    for (int i = 0; i < nx; ++i) {
    	if (cx[i] == -1) {
    		return false;
    	}
    }
    return true;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int a;
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
    	CLEAR(Graph,0)
    	CLEAR(vis,0)
    	nx = n;
    	ny = m;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			scanf("%d",&a);
    			if (a == 1) {
    				Graph[i][j] =1;
    			}
    		}
    	}
    	for (int i = 0; i < m; ++i) {
    		scanf("%d",&capacity[i]);
    	}
    	bool flag = solve();
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
    }
    return 0;
}