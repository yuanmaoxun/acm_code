//zhaoruifeng
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

#define PI acos(-1.0);
#define INF 0x3f3f3f3f
#define MAX 100000007
#define MOD 1000000007
#define EPS 1e-6
#define N 11234
#define M 1123456
#define root 1 , n , 1
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;

int n,m;
int flag,sum,ave,ans,res,len,ans1,ans2;
int a[N],b[N],c[N],ff[N],tt[N];
struct node
{
    int x,y;
    node(int a=0,int b=0)
    {
        x=a;y=b;
    }
}tn;
vector<int>g[N];
stack<node>st;
int dfn[N],low[N];
int index;

void init()
{
    for(int i=0;i<N;i++)
        g[i].clear();
    while(!st.empty())st.pop();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(c,0,sizeof(c));
    sum=0;
    index = 1;
}

bool dye(int u)
{
    int v;
    for(int i=0;i<g[u].size();i++)
    {
        v = g[u][i];
        if(!b[v])
            continue;
        if(ff[v]==ff[u])
            return false;
        if(ff[v]!=-1)
            continue;
        ff[v] = ff[u]^1;
        if(!dye(v))
            return false;
    }
    return true;
}

void judge(int u,int v)
{
    memset(b,0,sizeof(b));
    res=0;
    int x,y;
    int now=0;
    while(!st.empty())
    {
        tn = st.top();
        st.pop();
        x=tn.x;y=tn.y;
        now++;
        if(!b[y])a[res++]=y,b[y]=1;
        if(x==u)
            break;
        if(!b[x])a[res++]=x,b[x]=1;
    }
    memset(ff,-1,sizeof(ff));
    ff[a[0]] = 0;
    if(res&1&&res>2)
        for(int i=0;i<res;i++)
            c[a[i]] = 1;
}

void tarjan(int x,int fa)
{
    low[x] = dfn[x] = index++;
    int len = g[x].size();
    for(int i=0;i<len;i++)
    {
        int t=g[x][i];
        if(t==fa)
            continue;
        if(!dfn[t] && dfn[t]<dfn[x])
        {
            st.push(node(x,t));
            tarjan(t,x);
            low[x] = min(low[x], low[t]);
            if(dfn[x]<=low[t])
                judge(x,t);
        }
        else if(dfn[t] < dfn[x])
        {
            st.push(node(x,t));
            low[x] = min(low[x], dfn[t]);
        }
    }
}

void solve()
{
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i,i);
}

int main()
{
    int i,j,k,kk,t,x,y,z;
    scanf("%d",&k);
//    kk=0;
    while(k--)
//    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        scanf("%d%d",&n,&m);
        init();
        for(i=1;i<=n;i++)
            scanf("%d",&tt[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        solve();
        long long sum=0;
        for(i=1;i<=n;i++)
            if(c[i])
                sum+=tt[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
