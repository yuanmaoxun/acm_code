#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#define Maxn 100005
#define Clear(name,val); memset(name,val,sizeof(name));
using namespace std;

int father[26];
bool visit[26];  //判断这个字母是否出现过
int Count;
vector<pair<int,int> > edges;

int find_set(int n) {
    return father[n] == n?n:father[n] = find_set(father[n]);
}

bool isConnected() {
    for(int i = 0; i < 26; i++) {
        if(visit[i] == true){
            father[i] = i;
        }
    }
    for(int i = 0; i < Count; i++) {
        int x = edges[i].first;
        int y = edges[i].second;
        x = find_set(x);
        y = find_set(y);
        if(x != y) {
            father[x] = y;
        }
    }
    int res = 0;
    bool root[26];
    Clear(root,false);
    for(int i = 0; i < 26; i++) {
        if(!visit[i])
            continue;
        int temp = find_set(i);
        if(!root[temp]) {
            res++;
            root[temp] = true;
        }
    }
    return res == 1;
}

int main(){
    int T,n;
    int u,v;
    int in[26],out[26];  //入度和出度
    char str[Maxn];
    bool flag; //判断是否存在欧拉通路
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&n);
            Clear(in,0);
            Clear(out,0);
            Clear(visit,false);
            Clear(father,-1);
            Count = 0;
            edges.clear();
            flag = true;
            int one = 0;//出度比入度多1的顶点个数
            int none = 0;//入度比出度少1的顶点个数
            for(int i = 0; i < n; i++) {
                scanf("%s",str);
                u = str[0]-'a';
                v = str[strlen(str)-1]-'a';
                out[u]++;in[v]++;
                visit[u] = true;
                visit[v] = true;
                edges.push_back(make_pair(u,v));
                Count++;
            }
            for(int i = 0; i < 26; i++) {
                if(visit[i] == 0)
                    continue;
                if(out[i] - in[i] >= 2 || in[i] - out[i] >= 2){
                    flag = false;
                    break;
                }
                if(out[i] == 0 && in[i] == 0){
                    flag = false;
                    break;
                }
                if(out[i]-in[i]==1){
                    one++;
                    if(one>1) {
                        flag = false;
                        break;
                    }
                }
                if(in[i]-out[i]==1){
                    none++;
                    if(none>1){
                        flag = false;
                        break;
                    }
                }
            }
            if(one != none)
                flag = false;
            if(!isConnected())
                flag = false;
            if(flag)
                printf("Ordering is possible.\n");
            else
                printf("The door cannot be opened.\n");
        }
    }
return 0;
}
