#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
#define Maxn 100005

using namespace std;

struct ArcNode {
    int to;
    struct ArcNode* next;
};

int n,m;//顶点和边的个数
int flag;  //判断有向环的标志
int pos;  //写入output[]的下标
ArcNode* List[Maxn];
int Count[Maxn];    //各顶点的入度
int Copy[Maxn];  //复制Count
int output[Maxn];  //输出内容

int TopSort(int num) {
    ArcNode* temp;
    stack<int> S;
    flag = 0;
    pos = 0;
    for(int i = 0; i < n; i++)
        Copy[i] = Count[i];
    for(int i = 0; i < n; i++) {
        if(Copy[i] == 0){
            S.push(i);
        }
    }
    while(!S.empty()) {
        if(S.size() > 1)
            flag = 1;
        int Top = S.top();
        S.pop();
        output[pos++] = Top;
        temp = List[Top];
        while(temp != NULL) {
            int k = temp->to;
            if(--Copy[k] == 0) {
                S.push(k);
            }
            temp=temp->next;
        }
    }
    if(pos!=n)  //有环
        return 1;
    else if(flag == 1)  //多种排序方式，不能唯一确定
        return -1;
    else
        return 0;  //唯一确定
}

int main() {
    int u,v;
    char x,y;
    bool determined, inconsistency;
    int ans;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d%d",&n,&m)) {
        getchar();
        if(n==0 && m==0)
            break;
        memset(List,0,sizeof(List));
        memset(Count,0,sizeof(Count));
        memset(output,0,sizeof(output));
        determined=0;
        inconsistency=0;
        ArcNode* temp;
        for(int i = 0; i < m; i++) {
            scanf("%c<%c",&x,&y);
            getchar();
            if(!determined && !inconsistency) {
                u = x-'A';v = y-'A';
                Count[v]++;
                temp = new ArcNode;
                temp->to = v;
                temp->next = NULL;
                if(List[u] == NULL) {
                    List[u] = temp;
                }
                else {
                    temp->next = List[u];
                    List[u] = temp;
                }
                int res = TopSort(n);
                if(res == 0){
                    printf("Sorted sequence determined after %d relations: ",i+1);
                    for(int j = 0; j < pos; j++) {
                        printf("%c",output[j]+'A');
                    }
                    puts(".");
                    determined = 1;
                }
                else if(res == 1){
                    printf("Inconsistency found after %d relations.\n",i+1);
                    inconsistency = 1;
                }
            }
        }
        if(!determined && !inconsistency)
            printf("Sorted sequence cannot be determined.\n");
    }
return 0;
}
