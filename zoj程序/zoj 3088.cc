#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define INF 0x3f3f3f3f
#define Maxn 1005
using namespace std;

struct ArcNode {
    int to;
    int weight;
    ArcNode *next;
};

int n,m;
ArcNode* List1[Maxn];
ArcNode* List2[Maxn];      //每个顶点的边链表表头指针
bool flag[Maxn];          //标记每个顶点是否在队列中的标记
int dist2[Maxn][Maxn];
int path2[Maxn][Maxn];
int dist1[Maxn][Maxn];
int path1[Maxn][Maxn];

void SPFA1(int src){
    int i,j, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist1[src][i] = 0;
        path1[src][i] = src;
        flag[i] = false;
    }
    dist1[src][src] = 0;
    path1[src][src] = src;
    flag[src] = true;
    Q.push(src);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        flag[u] = false;
        temp = List1[u];
        while(temp != NULL) {
            int v = temp -> to;
            if(dist1[src][v] < dist1[src][u]+temp->weight) {
                dist1[src][v] = dist1[src][u] + temp->weight;
                path1[src][v] = u;
                if(!flag[v]) {
                    Q.push(v);
                    flag[v] = true;
                }
            }
            temp = temp->next;
        }
    }
}

void SPFA2(int src){
    int i,j, u;
    ArcNode* temp;
    queue <int> Q;
    for(i = 0; i < n; i++) {  //初始化
        dist2[src][i] = INF;
        path2[src][i] = src;
        flag[i] = false;
    }
    dist2[src][src] = 0;
    path2[src][src] = src;
    flag[src] = true;
    Q.push(src);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        flag[u] = false;
        temp = List2[u];
        while(temp != NULL) {
            int v = temp -> to;
            if(dist2[src][v] > dist2[src][u]+temp->weight) {
                dist2[src][v] = dist2[src][u] + temp->weight;
                path2[src][v] = u;
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
    int T,k,sx,sy;
    //cout << INF<<endl;
    scanf("%d",&T) ;
        while(T--) {
            scanf("%d%d%d",&n,&m,&k);
            memset(List1,0,sizeof(List1));
            memset(List2,0,sizeof(List2));
            ArcNode* temp;
            for(i = 0; i < m; i++) {
                scanf("%d%d%d",&u,&v,&w);
                u--;v--;
                temp = new ArcNode;  //构造邻接表
                temp -> to = v;
                temp ->weight = w;
                temp -> next = NULL;
                if(List1[u] == NULL)
                    List1[u] = temp;
                else{
                    temp -> next = List1[u];
                    List1[u] = temp;
                }
            }
            for(i = 0; i < n; i++)
                SPFA1(i);

            for(i = 0; i < k; i++) {
                scanf("%d%d%d",&u,&v,&w);
                u--;v--;
                temp = new ArcNode;  //构造邻接表
                temp -> to = v;
                temp ->weight = w;
                temp -> next = NULL;
                if(List2[u] == NULL)
                    List2[u] = temp;
                else{
                    temp -> next = List2[u];
                    List2[u] = temp;
                }
            }
            for(i = 0; i < n; i++)
                SPFA2(i);

            double ans = 0;
            double Sx,Sy;
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++) {
                    if(ans < dist1[i][j] * 1.0 / dist2[j][i]) {
                        ans = dist1[i][j] * 1.0 / dist2[j][i];
                        sx = i;sy = j;
                    }
                }

            int shortest[Maxn];       //路径输出
                memset(shortest,0,sizeof(shortest));
                k = 0;
                shortest[k] = sx;

                while(path2[sy][shortest[k]] != sy) {
                    k++;
                    shortest[k] = path2[sy][shortest[k-1]];
                }
                k++;
                shortest[k] = sy;
                for(j = k; j >= 0; j--)
                    printf("%d ",shortest[j]+1);
                memset(shortest,0,sizeof(shortest));
                k = 0;
                shortest[k] = sy;
                while(path1[sx][shortest[k]] != sx) {
                    k++;
                    shortest[k] = path1[sx][shortest[k-1]];
                }
                k++;
                shortest[k] = sx;
                for(j = k-1; j > 0; j--)
                    printf("%d ",shortest[j]+1);
                printf("%d\n",shortest[0]+1);
                printf("%.3f\n",ans);

                for(j = 0; j < n; j++) {
                    temp = List1[j];
                    while(temp != NULL) {
                        List1[j] = temp->next;
                        delete temp;
                        temp = List1[j];
                    }
                }
                for(j = 0; j < n; j++) {
                    temp = List2[j];
                    while(temp != NULL) {
                        List2[j] = temp->next;
                        delete temp;
                        temp = List2[j];
                    }
                }
        }
    return 0;
}
