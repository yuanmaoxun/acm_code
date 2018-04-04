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

int n,m;
ArcNode* List[Maxn];      //每个顶点的边链表表头指针
bool flag[Maxn];          //标记每个顶点是否在队列中的标记
int dist[Maxn];
int path[Maxn];

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

int main() {
    int i,j,T;
    int u,v,w;
    while(~scanf("%d%d",&m,&n)) {
        memset(List,0,sizeof(List));
        ArcNode* temp;
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
            temp = new ArcNode;  //构造邻接表
            temp -> to = u;
            temp ->weight = w;
            temp -> next = NULL;
            if(List[v] == NULL)
                List[v] = temp;
            else{
                temp -> next = List[v];
                List[v] = temp;
            }
        }
        SPFA(n-1);
        printf("%d\n",dist[0]);
        for(j = 0; j < n; j++) {
            temp = List[j];
            while(temp != NULL) {
                List[j] = temp->next;
                delete temp;
                temp = List[j];
            }
        }

    }
    return 0;
}

