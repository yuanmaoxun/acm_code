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
    double R,C;
    double weight;
    ArcNode *next;
};

int n,m;
double V;
ArcNode* List[Maxn];      //每个顶点的边链表表头指针
bool flag[Maxn];          //标记每个顶点是否在队列中的标记
double dist[Maxn];
int path[Maxn];
int Count[Maxn];

int SPFA(int src){
    int i, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist[i] = 0;
        flag[i] = false;
        Count[i] = 0;
    }
    dist[src] = V;
    flag[src] = true;
    Q.push(src);
    Count[src]++;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        if(Count[u] > n)
            return 0;
        flag[u] = false;
        temp = List[u];
        while(temp != NULL) {
            int v = temp -> to;
            temp->weight = (dist[u]-(temp->C) ) * (temp->R) - dist[u];
            if(dist[v] < dist[u]+temp->weight) {
                dist[v] = dist[u] + temp->weight;
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
    int u,v,w;
    int S;

    double Ruv,Cuv,Rvu,Cvu;
    while(~scanf("%d%d%d%lf",&n,&m,&S,&V)) {
        S--;
        memset(List,0,sizeof(List));
        ArcNode* temp;
        for(i = 0; i < m; i++) {
            scanf("%d%d%lf%lf%lf%lf",&u,&v,&Ruv,&Cuv,&Rvu,&Cvu);
            u--;v--;
            //正向
            temp = new ArcNode;  //构造邻接表
            temp -> to = v;
            temp -> R = Ruv;
            temp -> C = Cuv;
            temp -> weight = 0;
            temp -> next = NULL;
            if(List[u] == NULL)
                List[u] = temp;
            else{
                temp -> next = List[u];
                List[u] = temp;
            }
            //反向
            temp = new ArcNode;  //构造邻接表
            temp -> to = u;
            temp -> R = Rvu;
            temp -> C = Cvu;
            temp -> weight = 0;
            temp -> next = NULL;
            if(List[v] == NULL)
                List[v] = temp;
            else{
                temp -> next = List[v];
                List[v] = temp;
            }
        }

        if(SPFA(S)==0)
            printf("YES\n");
        else
            printf("NO\n");
//        for(i = 0; i < n; i++)
//            cout <<Count[i] <<" ";
//        cout <<endl;
//        for(i = 0; i < n; i++)
//            cout <<dist[i] <<" ";
//        cout <<endl;


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

