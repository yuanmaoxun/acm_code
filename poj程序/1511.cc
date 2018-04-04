//SPFA
//注意dist数组的初始值，u和v的初始编号，从哪个点找起
//注意有向图还是无向图
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define INF 0x7fffffff
#define Maxn 1000005
using namespace std;

struct ArcNode {
    int to;
    int weight;
    ArcNode *next;
};

int n,m;
ArcNode* List[Maxn];      //每个顶点的边链表表头指针
ArcNode* List1[Maxn];      //每个顶点的边链表表头指针
bool flag[Maxn];          //标记每个顶点是否在队列中的标记
bool flag1[Maxn];          //标记每个顶点是否在队列中的标记
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
    ArcNode* temp;
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
    int T;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d",&n,&m);
            memset(List,0,sizeof(List));
            memset(List1,0,sizeof(List1));
            ArcNode* temp,*temp1;
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
                temp1 = new ArcNode;  //构造邻接表
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
            SPFA(0);
            long long sum = 0;
            for(int i = 0; i < n; i++) {
                sum += dist[i];
            }
            SPFA1(0);
            for(int i = 0; i < n; i++) {
                sum += dist1[i];

            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}

