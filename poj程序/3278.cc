#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#define Maxn 100005

using namespace std;
int Step[Maxn];
bool visit[Maxn];
int n,k;
int next, head;

void bfs() {
    queue<int> Q;
    Q.push(n);
    Step[n] = 0;
    visit[n] = true;
    while(!Q.empty()) {
        head = Q.front();
        Q.pop();
        for(int i = 1; i <= 3; i++) {
            if(i == 1) {
                next = head - 1;
            }
            else if(i == 2) {
                next = head+1;
            }
            else
                next = head*2;
            if(next > Maxn || next < 0)
                continue;
            if(!visit[next]) {
                Q.push(next);
                Step[next] = Step[head]+1;
                visit[next] = true;
            }
            if(next == k)
                return ;
        }
    }
    return ;
}



int main() {
    while(~scanf("%d%d",&n,&k)) {
        memset(visit,false,sizeof(visit));
        memset(Step,0,sizeof(Step));
        if(n > k) {
            printf("%d\n",n-k);
        }
        else{
            bfs();
            printf("%d\n",Step[next]);
        }

    }

return 0;
}
