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
int Count[Maxn];

int SPFA(int src){
    int i, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist[i] = INF;
        path[i] = src;
        flag[i] = false;
        Count[i] = 0;
    }
    dist[src] = 0;
    path[src] = src;
    flag[src] = true;
    Q.push(src);
    Count[src]++;
    while(!Q.empty()) {
        u = Q.front();
        //cout << u <<" " <<Count[u] <<endl;
        Q.pop();
        flag[u] = false;
        if(Count[u]>n) {
            return 0;
        }
        temp = List[u];
        while(temp != NULL) {
            int v = temp -> to;
            if(dist[v] > dist[u]+temp->weight) {
                dist[v] = dist[u] + temp->weight;
                path[v] = u;
                if(!flag[v]) {
                    Q.push(v);
                    Count[v]++;
                    flag[v] = true;
                }
            }
            temp = temp->next;
        }
    }
    return 1;
}

int main() {
    int i,j;
    int u,v,w,W;
    int T;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d%d",&n,&m,&W);
            memset(List,0,sizeof(List));
            memset(Count,0,sizeof(Count));
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
            for(i = 0; i < W; i++) {
                scanf("%d%d%d",&u,&v,&w);
                u--;v--;w = -w;
                temp = new ArcNode;
                temp -> to = v;
                temp ->weight = w;
                temp -> next = NULL;
                if(List[u] == NULL)
                    List[u] = temp;
                else{
                    temp -> next = List[u];
                    List[u] = temp;
                }

            }

            if(SPFA(0)) {
                printf("NO\n");
            }
            else
                printf("YES\n");
            for(j = 0; j < n; j++) {
                temp = List[j];
                while(temp != NULL) {
                    List[j] = temp->next;
                    delete temp;
                    temp = List[j];
                }
            }
        }
    }
    return 0;
}

