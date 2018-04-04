#include<iostream>
#include<cstdio>
#include<algorithm>
const int N=110;
using namespace std;

struct Edge{
    int u,v,w;  //边的顶点、权值
    bool operator < (const Edge &p) const {
        return w<p.w;
    }
    int equal; //标记，1表示存在权值相同的边，0表示不存在
    int used;//在第一次求得的MST中，是否包含该边
    int del;  //1删除，0未删除
}edge[N*N];

int n,m;
bool first;
int parent[N];

//初始化
void UFset(){
    for(int i=0;i<n;i++){
        parent[i]=-1;
    }
}

int Find(int x){
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);
    //压缩路径，优化
    while(s!=x){
        int temp=parent[x];
        parent[x]=s;
        x=temp;
    }
    return s;
}

//合并
void Union(int R1,int R2){
    int r1=Find(R1);
    int r2=Find(R2);
    int temp=parent[r1]+parent[r2];
    if(parent[r1]>parent[r2]){
        parent[r1]=r2;
        parent[r2]=temp;
    }else {
        parent[r1]=temp;
        parent[r2]=r1;
    }
}

int kruskal(){
    int sumweight=0,num=0;
    int u,v;
    UFset();
    for(int i=0;i<m;i++){
        if(edge[i].del==1)continue;//忽略去掉的边
        u=edge[i].u,v=edge[i].v;
        if(Find(u)!=Find(v)){
            sumweight+=edge[i].w;
            num++;
            Union(u,v);
            if(first)edge[i].used=1;
        }
        if(num>=n-1)break;
    }
    return sumweight;
}

int main(){
    int u,v,w,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge[i].u=u-1,edge[i].v=v-1,edge[i].w=w;
            edge[i].equal=0,edge[i].used=0,edge[i].del=0;
        }
        // 标记权值相同的边
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                if(edge[j].w==edge[i].w){
                    edge[i].equal=1;
                }
            }
        }
        sort(edge,edge+m);
        first=true;
        int weight1=kruskal(),weight2;//第一次求MST
        first=false;
        int tag=1;
        for(int i=0;i<m;i++){
            if(edge[i].used&&edge[i].equal){
                edge[i].del=1;
                weight2=kruskal();
                if(weight1==weight2){
                    printf("Not Unique!\n");
                    tag=0;
                    break;
                }
                edge[i].del=0;
            }
        }
        if(tag)
            printf("%d\n",weight1);
    }
    return 0;
}
