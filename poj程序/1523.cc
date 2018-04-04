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

int Edge[Maxn][Maxn];    //�ڽӾ���
int vis[Maxn];           //��ʾ�������״̬
int nodes;              //������Ŀ
int tmpdfn;              //��dfs�����м�¼��ǰ�����������������
int dfn[Maxn];           //ÿ�������dfnֵ
int low[Maxn];           //ÿ�������lowֵ�����ݸ�ֵ�ж��Ƿ�Ϊ�ؽڵ�
int son;                 //��������Ů���ĸ������������2���������ǹؽڵ㣩
int subnets[Maxn];       //��¼ÿ���ڵ㣨ȥ���ýڵ�󣩵���ͨ�����ĸ���

//���������������¼ÿ���ڵ��lowֵ������lowֵ���ж��Ƿ���ؽڵ㣩

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
        //v��ulinjie�����������о���2�����
        //1 v��u�����Ƚ�㣬����(v,u)����һ���رߣ�2  v��u�Ķ��ӽڵ�
        if(Edge[u][v]) {
            if(!vis[v]) {  //v��δ���ʣ�v��u�Ķ��ӽ�㣬����2
                vis[v] = 1;
                tmpdfn++;
                dfn[v] = low[v] = tmpdfn;
                dfs(v);    //dfs(v)ִ����Ϻ�low[v]ֵ�����

                low[u] = min(low[u],low[v]);   //���˵�ʱ�򣬼��㶥��u��lowֵ
                if(low[v] >= dfn[u]){
                    if(u!=1)
                        subnets[u]++;
                    else
                        son++;
                }
            }
            //��ǰv�Ѿ����ʹ���,v��u�����Ƚ�㣨(v,u)����һ���ߣ������� 1
            else
                low[u] = min(low[u],dfn[v]);
        }
    }
}

int main() {
    int u,v;
    int Find;   //�ҵ��ؽڵ�ı�־
    int number = 1;   //�������ݵ���Ŀ
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





