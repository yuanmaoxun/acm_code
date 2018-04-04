//kengkeng
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define Maxn 100005
#define Maxm 5005
#define INF 0xffff;
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));

using namespace std;

int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    int k,i;
    ll num[25];
    //int key[3][3];
    int visit[25];
    int flag;
    while(~scanf("%d",&T)) {
        while(T--) {
            flag = 1;
            Clear(visit,0);
            scanf("%d",&k);
            for(int i = 1; i <= k; i++) {
                scanf("%lld",&num[i]);
            }
            if(k < 4) {
                printf("invalid\n");
                continue;
            }
            for(i = 1; i <= k; i++) {
                if(num[i] > 9 || num[i] == 0) {
                    printf("invalid\n");
                    break;
                }
            }
            if(i != k+1)
                continue;
            visit[num[1]] = 1;
            for(int i = 2; i <= k; i++) {
                if(visit[num[i]] != 0) {
                    flag = 0;
                    break;
                }
                if(num[i] == 1) {
                    if(num[i-1] == 3 && visit[2] == 0){
                        flag=0;
                        break;
                    }
                    else
                    if(num[i-1] == 7 && visit[4] == 0) {
                        flag=0;
                        break;
                    }
                    else
                        if(num[i-1] == 9 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 3) {
                    if(num[i-1] == 1 && visit[2] == 0){
                        flag=0;
                        break;
                    }
                    else if(num[i-1] == 9 && visit[6] == 0) {
                        flag=0;
                        break;
                    }
                    else if(num[i-1] == 7 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else
                if(num[i] == 7) {
                    if(num[i-1] == 1 && visit[4] == 0){
                        flag=0;
                        break;
                    }
                    else if(num[i-1] == 9 && visit[8] == 0){
                        flag=0;
                        break;
                    }
                    else if(num[i-1] == 3 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 9) {
                    if(num[i-1] == 7 && visit[8] == 0){
                        flag=0;
                        break;
                    }
                    else
                    if(num[i-1] == 3 && visit[6] == 0){
                        flag=0;
                        break;
                    }
                    else if(num[i-1] == 1 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 4) {
                    if(num[i-1] == 6 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 6) {
                    if(num[i-1] == 4 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 2) {
                    if(num[i-1] == 8 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                else if(num[i] == 8) {
                    if(num[i-1] == 2 && visit[5] == 0){
                        flag=0;
                        break;
                    }
                }
                visit[num[i]] = 1;
            }
            if(flag)
                printf("valid\n");
            else
                printf("invalid\n");
        }
    }
return 0;
}





