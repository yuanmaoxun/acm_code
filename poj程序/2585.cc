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
    for(int i = 0; i < num; i++)
        Copy[i] = Count[i];

    for(int i = 0; i < num; i++) {
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
    if(pos!=num)  //有环
        return 1;
    else
        return 0;  //唯一确定
}

int main() {
    int u,v;
    int num[4][4];
    int dir[4][2] = {0,0, 0,1, 1,0, 1,1};
    bool visit[9];
    string str;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin >>str) {
        if(str == "ENDOFINPUT")
            break;
        memset(List,0,sizeof(List));
        memset(Count,0,sizeof(Count));
        memset(output,0,sizeof(output));
        ArcNode* temp;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                scanf("%d",&num[i][j]);
            }
        }
        for(int k = 1; k <= 9; k++) {
            memset(visit,0,sizeof(visit));
            int x = (k-1)/3;
            int y = (k-1)%3;
            u = k;
            u--;
            for(int i = 0; i < 4; i++ ) {
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                v = num[xx][yy];
                v--;

                if(v!=(k-1) && !visit[v]) {
                    //cout << u <<" "<<v<<endl;
                    visit[v] = true;
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
                }
            }
        }
        int res = TopSort(9);
        if(res) {
            printf("THESE WINDOWS ARE BROKEN\n");
        }
        else {
            printf("THESE WINDOWS ARE CLEAN\n");
        }
        cin >> str;
    }
return 0;
}

