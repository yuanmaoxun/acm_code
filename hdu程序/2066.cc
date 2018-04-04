//SPFA
//ע��dist����ĳ�ʼֵ��u��v�ĳ�ʼ��ţ����ĸ�������
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
ArcNode* List[Maxn];      //ÿ������ı������ͷָ��
bool flag[Maxn];          //���ÿ�������Ƿ��ڶ����еı��
int dist[Maxn];
int path[Maxn];

void SPFA(int src){
    int i, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //��ʼ��
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
    int i,j;
    int u,v,w;
    int T,S,D;
    while(~scanf("%d%d%d",&T,&S,&D)) {
        memset(List,0,sizeof(List));
        ArcNode* temp;
        n = 1005;
        for(i = 0; i < T; i++) {
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            temp = new ArcNode;  //�����ڽӱ�
            temp -> to = v;
            temp ->weight = w;
            temp -> next = NULL;
            if(List[u] == NULL)
                List[u] = temp;
            else{
                temp -> next = List[u];
                List[u] = temp;
            }
            temp = new ArcNode;  //�����ڽӱ�
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
        int U[1005],V[1005];
        int Min = INF;
        int area;
        for(i = 0; i < S; i++) {
            scanf("%d",&u);
            u--;
            U[i] = u;
        }
        for(i = 0; i < D; i++) {
            scanf("%d",&v);
            v--;
            V[i] = v;
        }
        for(i = 0; i < S; i++) {
            SPFA(U[i]);
            for(j = 0; j < D; j++) {
                Min = min(Min,dist[V[j]]);
            }
        }
            //printf("%d\n",area+1);
        printf("%d\n",Min);

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

