#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define Maxn 10005

using namespace std;

struct Number {
    int first,sec,thd,fouth;
    int sum;
    int step;
}A,B;
int Min;
bool visit[Maxn];

bool judge(int n) {
    for(int i = 2; i*i<=n;i++) {
        if(n%i==0)
            return false;
    }
return true;
}

bool bfs(Number S) {
    queue<Number> Q;
    Number Front,next;
    Q.push(S);
    visit[S.sum] = true;
    while(!Q.empty()) {
        Front = Q.front();
        //cout << Front.sum<<endl;
        Q.pop();
        if(Front.sum == B.sum){
            Min = Front.step;
            return true;
        }
        for(int i = 0; i <= 9; i++) {
            next = Front;
            next.first = i;
            next.sum = next.first+next.sec*10+next.thd*100+next.fouth*1000;
            if(visit[next.sum] || !judge(next.sum)){
                continue;
            }
            next.step = Front.step+1;
            visit[next.sum] = true;
            Q.push(next);
        }
        for(int i = 0; i <= 9; i++) {
            next = Front;
            next.sec = i;
            next.sum = next.first+next.sec*10+next.thd*100+next.fouth*1000;
            if(visit[next.sum] || !judge(next.sum)){
                continue;
            }
            next.step = Front.step+1;
            visit[next.sum] = true;
            Q.push(next);
        }
        for(int i = 0; i <= 9; i++) {
            next = Front;
            next.thd = i;
            next.sum = next.first+next.sec*10+next.thd*100+next.fouth*1000;
            if(visit[next.sum] || !judge(next.sum)){
                continue;
            }
            next.step = Front.step+1;
            visit[next.sum] = true;
            Q.push(next);
        }
        for(int i = 1; i <= 9; i++) {
            next = Front;
            next.fouth = i;
            next.sum = next.first+next.sec*10+next.thd*100+next.fouth*1000;
            if(visit[next.sum] || !judge(next.sum)){
                continue;
            }
            next.step = Front.step+1;
            visit[next.sum] = true;
            Q.push(next);
        }
    }
    return false;
}

int main() {
    int T;
    while(~scanf("%d",&T)) {
        int a, b;
        while(T--) {
            scanf("%d%d",&a,&b);
            A.first = a%10;
            A.sec = a/10%10;
            A.thd = a/100%10;
            A.fouth = a/1000;
            A.sum = a;
            A.step = 0;
            B.first = b%10;
            B.sec = b/10%10;
            B.thd = b/100%10;
            B.fouth = b/1000;
            B.sum = b;
            Min = 0;
            memset(visit,false,sizeof(visit));
            if(bfs(A)) {
                printf("%d\n",Min);
            }
            else
                printf("Impossible\n");
        }

    }

return 0;
}
