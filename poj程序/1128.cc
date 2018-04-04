#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stack>
#define Maxn 35
#define Clear(name, num); memset(name, num, sizeof(name));
using namespace std;

struct ArcNode {
    int to;
    struct ArcNode *next;
};
ArcNode *List[Maxn];
int Count[Maxn];
int Copy[Maxn];
int output[Maxn];

int TopSort(int num) {
    ArcNode* temp;
    stack<int> S;
    int flag = 0;
    int pos = 0;
    for(int i = 0; i < 26; i++)
        Copy[i] = Count[i];
    for(int i = 0; i < 26; i++) {
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
    else if(flag == 1)  //多种排序方式，不能唯一确定
        return -1;
    else
        return 0;  //唯一确定
}

int main(){
    int h,w;
    int u,v;
    int cnt;
    char str[Maxn][Maxn];
    bool visit[Maxn];
    bool flag;
    while(~scanf("%d%d",&h,&w)) {
        Clear(List,0);
        Clear(Count,-1);
        Clear(output,0);
        ArcNode*temp;
        cnt = 26;
        for(int i = 0; i < h; i++)
            scanf("%s",str[i]);
        for(char k = 'A';k<='Z';k++) {
            Clear(visit,false);
            flag = false;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(str[i][j] == k) {
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) {
                cnt--;
                continue;
            }
            int Mini = Maxn; int Minj = Maxn;
            int Maxi = -1; int Maxj = -1;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(str[i][j] == k) {
                        Mini = min(i,Mini);
                        Minj = min(j,Minj);
                        Maxi = max(i,Maxi);
                        Maxj = max(j,Maxj);
                    }
                }
            }
            u = k-'A';
            visit[u] = true;
            for(int i = Mini; i<=Maxi;i++) {
                if(str[i][Minj]!=k && !visit[str[i][Minj]-'A']){
                    visit[str[i][Minj]-'A'] = true;
                    v = str[i][Minj] - 'A';
                    if(Count[v] == -1)
                        Count[v] = 0;
                    if(Count[u]==-1)
                        Count[u] = 0;
                    Count[v]++;
                    temp = new ArcNode;
                    temp->to = v;
                    temp->next = NULL;
                    if(List[u] == NULL){
                        List[u] =temp;
                    }
                    else {
                        temp->next = List[u];
                        List[u] = temp;
                    }
                }
                if(str[i][Maxj]!=k && !visit[str[i][Maxj]-'A']) {
                    visit[str[i][Maxj]-'A'] = true;
                    v = str[i][Maxj] - 'A';
                    if(Count[u]==-1)
                        Count[u] = 0;
                    if(Count[v] == -1)
                        Count[v] = 0;
                    Count[v]++;
                    temp = new ArcNode;
                    temp->to = v;
                    temp->next = NULL;
                    if(List[u] == NULL){
                        List[u] =temp;
                    }
                    else {
                        temp->next = List[u];
                        List[u] = temp;
                    }
                }
            }
            for(int j = Minj; j<=Maxj;j++) {
                if(str[Mini][j]!=k && !visit[str[Mini][j]-'A']) {
                    visit[str[Mini][j]-'A'] = true;
                    v = str[Mini][j] - 'A';
                    if(Count[u]==-1)
                        Count[u] = 0;
                    if(Count[v] == -1)
                        Count[v] = 0;
                    Count[v]++;
                    temp = new ArcNode;
                    temp->to = v;
                    temp->next = NULL;
                    if(List[u] == NULL){
                        List[u] =temp;
                    }
                    else {
                        temp->next = List[u];
                        List[u] = temp;
                    }
                }
                if(str[Maxi][j]!=k && !visit[str[Maxi][j]-'A']) {
                    visit[str[Maxi][j]-'A'] = true;
                    v = str[Maxi][j] - 'A';
                    if(Count[v] == -1)
                        Count[v] = 0;
                    if(Count[u]==-1)
                        Count[u] = 0;
                    Count[v]++;
                    temp = new ArcNode;
                    temp->to = v;
                    temp->next = NULL;
                    if(List[u] == NULL){
                        List[u] =temp;
                    }
                    else {
                        temp->next = List[u];
                        List[u] = temp;
                    }
                }
            }
        }
        int res = TopSort(cnt);
        for(int i = 0; i < cnt; i++){
            printf("%c",output[i]+'A');
        }
        puts("");
    }

return 0;
}
