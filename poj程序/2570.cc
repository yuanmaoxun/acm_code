//kengkeng
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#define INF 0x3f3f3f
#define Maxn 1005
using namespace std;

int n,m;
int Edge[Maxn][Maxn];
int dist[Maxn][Maxn];
int path[Maxn][Maxn];

void Floyd() {
    int i,j,k;
    for(i = 0; i < n; i++) {   //初始化
        for(j = 0; j < n; j++) {
            dist[i][j] = Edge[i][j];
            if(i != j && dist[i][j] < INF)
                path[i][j] = i;  //i到j有直接路径
            else                 //i到j没有直接路径
                path[i][j] = -1;
        }
    }
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(k == i || k == j)
                    continue;
                dist[i][j] |= (dist[i][k] & dist[k][j]);
            }
        }
    }
}

int main(){
    int i,j;
    int u,v,w;
    int T;
    int a,b;
    char str[Maxn];
    char ch;
    while(~scanf("%d",&n) && n) {
            memset(Edge,0,sizeof(Edge));
            while(~scanf("%d %d",&a,&b)) {
                if(a==0&&b==0)
                    break;
                a--;b--;
                scanf("%s",str);
                for(i = 0; str[i];i++) {
                    Edge[a][b] |= 1 << (str[i]-'a');

                }//cout << Edge[a][b] <<endl;
            }
            Floyd();
            while(~scanf("%d %d",&a,&b)) {

                if(a == 0&&b==0)
                    break;
                a--;b--;
                for(ch = 'a';ch<='z';ch++) {
                    if(dist[a][b] & (1<<(ch-'a')) )
                        putchar(ch);
                }
                //cout << dist[a][b] <<endl;
                if(!dist[a][b])
                    putchar('-');
                cout <<endl;
            }
            cout <<endl;
    }
    return 0;
}
