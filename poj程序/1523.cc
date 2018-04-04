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

int Edge[Maxn][Maxn];    //邻接矩阵
int vis[Maxn];           //表示顶点访问状态
int nodes;              //顶点数目
int tmpdfn;              //在dfs过程中记录当前的深度优先搜索序列
int dfn[Maxn];           //每个顶点的dfn值
int low[Maxn];           //每个顶点的low值，根据该值判断是否为关节点
int son;                 //根结点的子女结点的个数（如果大于2，则跟结点是关节点）
int subnets[Maxn];       //记录每个节点（去掉该节点后）的连通分量的个数

//深度优先搜索，记录每个节点的low值（根据low值来判断是否求关节点）

void init() {
    low[1] = dfn[1] = 1;
    tmpdfn = 1;
    son = 0;
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    memset(subnets,0,sizeof(subnets));
}

void dfs(int u) {
    for(int v = 1; v<= nodes; v++) {
        //v跟ulinjie。在生成树中就是2种情况
        //1 v是u的祖先结点，这样(v,u)就是一条回边；2  v是u的儿子节点
        if(Edge[u][v]) {
            if(!vis[v]) {  //v还未访问，v是u的儿子结点，情形2
                vis[v] = 1;
                tmpdfn++;
                dfn[v] = low[v] = tmpdfn;
                dfs(v);    //dfs(v)执行完毕后，low[v]值以求出

                low[u] = min(low[u],low[v]);   //回退的时候，计算顶点u的low值
                if(low[v] >= dfn[u]){
                    if(u!=1)
                        subnets[u]++;
                    else
                        son++;
                }
            }
            //此前v已经访问过了,v是u的祖先结点（(v,u)就是一条边）：情形 1
            else
                low[u] = min(low[u],dfn[v]);
        }
    }
}

int main() {
    int u,v;
    int Find;   //找到关节点的标志
    int number = 1;   //测试数据的数目
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//ACM//input.txt","r",stdin);
#endif
    while(1) {
        scanf("%d",&u);
        if(u == 0)
            break;
        memset(Edge,0,sizeof(Edge));
        nodes = 0;
        scanf("%d",&v);
        if(u > nodes)
            nodes = u;
        if(v > nodes)
            nodes = v;
        Edge[u][v] = Edge[v][u] = 1;
        while(1) {
            scanf("%d",&u);
            if(u == 0)
                break;
            nodes = 0;
            scanf("%d",&v);
            if(u > nodes)
                nodes = u;
            if(v > nodes)
                nodes = v;
            Edge[u][v] = Edge[v][u] = 1;
        }
        if(number > 1)
            printf("\n");
        printf("Network #%d\n",number);
        number++;
        init();
        dfs(1);
        if(son > 1)
            subnets[1] = son-1;
        Find = 0;
        for(int i = 1; i <= nodes; i++) {
            if(subnets[i]) {
                Find = 1;
                printf("  SPF node %d leaves %d subnets\n",i,subnets[i]+1);
            }
        }
        if(!Find)
            printf("  No SPF nodes\n");
    }
return 0;
}





