//SPFA
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define INF 1000000000
#define Maxn 100005
using namespace std;

struct ArcNode {
    int to;
    int weight;
    ArcNode *next;
};
struct ArcNode1 {
    int to;
    int weight;
    ArcNode1 *next;
};

int n,m;
ArcNode* List[Maxn];      //每个顶点的边链表表头指针
ArcNode1* List1[Maxn];
bool flag[Maxn];          //标记每个顶点是否在队列中的标记
bool flag1[Maxn];
int dist[Maxn];
int dist1[Maxn];
int path[Maxn];
int path1[Maxn];

void SPFA(int src){
    int i, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist[i] = INF;
        path[i] = src;
        flag[i] = false;
    }
    dist[src] = 0;
    path[src] = src;
    flag[src] = true;
    Q.push(src);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        flag[u] = false;
        temp = List[u];
        while(temp != NULL) {
            int v = temp -> to;
            if(dist[v] > dist[u]+temp->weight) {
                dist[v] = dist[u] + temp->weight;
                path[v] = u;
                if(!flag[v]) {
                    Q.push(v);
                    flag[v] = true;
                }
            }
            temp = temp->next;
        }
    }
}

void SPFA1(int src){
    int i, u;
    ArcNode1* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist1[i] = INF;
        path1[i] = src;
        flag1[i] = false;
    }
    dist1[src] = 0;
    path1[src] = src;
    flag1[src] = true;
    Q.push(src);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        flag1[u] = false;
        temp = List1[u];
        while(temp != NULL) {
            int v = temp -> to;
            if(dist1[v] > dist1[u]+temp->weight) {
                dist1[v] = dist1[u] + temp->weight;
                path1[v] = u;
                if(!flag1[v]) {
                    Q.push(v);
                    flag1[v] = true;
                }
            }
            temp = temp->next;
        }
    }
}


int main() {
    int i,j;
    int u,v,w;
    int x;
    while(~scanf("%d%d%d",&n,&m,&x)) {
        memset(flag,false,sizeof(flag));
        memset(List,0,sizeof(List));
        ArcNode* temp;
        ArcNode1* temp1;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            temp = new ArcNode;  //构造邻接表
            temp -> to = v;
            temp ->weight = w;
            temp -> next = NULL;
            if(List[u] == NULL)
                List[u] = temp;
            else{
                temp -> next = List[u];
                List[u] = temp;
            }
            //逆向邻接表
            temp1 = new ArcNode1;  //构造邻接表
            temp1 -> to = u;
            temp1 ->weight = w;
            temp1 -> next = NULL;
            if(List1[v] == NULL)
                List1[v] = temp1;
            else{
                temp1 -> next = List1[v];
                List1[v] = temp1;
            }
        }
        x--;
        SPFA(x);
        SPFA1(x);
        int Max = -1;
        for(i = 0; i < n; i++) {
            Max = max(Max,dist[i] + dist1[i]);
        }
        printf("%d\n",Max);
    }
    return 0;
}

