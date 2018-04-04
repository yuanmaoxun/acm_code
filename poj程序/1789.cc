#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#define INF 0xfffffff    //�����
#define Maxn 2005         //����������ֵ
using namespace std;

int n, m;               //�������������
int Edge[Maxn][Maxn];   //�ڽӾ���
int lowcost[Maxn];
int nearvex[Maxn];

void prim (int u0) {    //�Ӷ���u0����ִ������ķ�㷨
    int i,j;
    int sumweight = 0;    //��������Ȩֵ
    for(i = 1; i <= n; i++) {      //��ʼ��lowcost��nearvex����
        lowcost[i] = Edge[u0][i];
        nearvex[i] = u0;
    }
    nearvex[u0] = -1;
    for(i = 1; i < n; i++) {
        int Min = INF;
        int v = -1;       //��lowcost���飨��nearvex[]ֵΪ-1Ԫ���У����ҵ���Сֵ
        for(j = 1; j <= n; j++) {
            if(nearvex[j] != -1 && lowcost[j] < Min) {
                v = j;
                Min = lowcost[j];
            }
        }
        if(v != -1) {   //v==-1 ��ʾû�ҵ�Ȩֵ��С�ı�
            //printf("%d %d %d\n",nearvex[v],v,lowcost[v]);
            nearvex[v] = -1;
            sumweight+=lowcost[v];
            for(j = 1; j <= n; j++) {
                if(nearvex[j] != -1 && Edge[v][j] < lowcost[j]) {
                    lowcost[j] = Edge[v][j];
                    nearvex[j] = v;
                }
            }
        }
    }
    printf("The highest possible quality is 1/%d.\n",sumweight);
}



int main() {
    int i, j;
    int u, v, w;
    char str[Maxn][8];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d", &n) && n){

        for(i = 1; i <= n; i++ )
            scanf("%s",str[i]);

        memset( Edge, 0, sizeof(Edge) );

        for(i = 1; i <= n; i++)
            for(j = i+1; j <= n; j++) {
                int sum = 0;
                for(int k = 0; k < 7; k++) {
                    if(str[i][k] != str[j][k])
                        sum++;
                }
                Edge[i][j] = Edge[j][i] = sum;
            }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n ; j++) {
                if(i == j)
                    Edge[i][j] = 0;
                else if(Edge[i][j] == 0)
                    Edge[i][j] = INF;
            }
        }
        prim(1);       //�Ӷ���1����������С������
    }
return 0;
}

