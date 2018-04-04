//Floyd
//注意Edge的初始化
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<map>
#define INF 0x3f3f3f
#define Maxn 1005

using namespace std;

int n,m;
double Edge[Maxn][Maxn];
double dist[Maxn][Maxn];
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
                dist[i][j] = max(dist[i][j],dist[i][k] * dist[k][j]);
            }
        }
    }
}

int main(){
    int i,j;
    int u,v,w;
    double rate;
    int Count = 0;
    while(~scanf("%d",&n) && n) {
        Count++;
        map<string,int> ID;
        string str,str1,str2;
        for(i = 0; i < n; i++) {
            cin >> str;
            ID[str] = i;
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j)
                    Edge[i][j] = 1;
                else
                    Edge[i][j] = INF;
            }
        }
        scanf("%d",&m);
        for(i = 0; i < m; i++) {
            cin >> str1 >> rate >>str2;
            Edge[ID[str1]][ID[str2]] = rate;
        }
        Floyd();
        bool flag = false;
        for(i = 0; i < n; i++) {
            if(dist[i][i] > 1){
                flag = true;
                break;
            }
        }
        if(flag)
            printf("Case %d: Yes\n",Count);
        else
            printf("Case %d: No\n",Count);
    }
}
