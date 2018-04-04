//kengkeng
#include<stdio.h>
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

int main()
{
//    char str[Maxn];
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T,n;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&n);
            for(int i = 1; i < n; i++) {
                scanf("%d",&num[i]);
            }
            num[n] = 0;
            int flag = 1;
            for(int i = 1; i < n; i++) {
                if(num[i]) {
                    if(num[i] - num[i+1] != 1) {
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag) {
                cout<<"0"<<"\n";
            }
            else {
                int res = 0;
                for(int i = 1; i < n; i++) {
                    if(!num[i]) {
                        res++;
                    }
                }
                long long ans = 26;
                for(int i = 0; i < res; i++) {
                    ans=(ans * 25) % Mod;
                }
                cout<<ans % Mod<<"\n";
            }
        }
    }
    return 0;
}


