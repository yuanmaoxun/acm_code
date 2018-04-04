//kengkeng
#include<bits/stdc++.h>
#define Maxn 1005
#define Maxm 5005
#define INF 0xffff
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
    int num[Maxn];
    int flag[1000005];
int main() {
//    char str[Maxn];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n;
    while(~scanf("%d",&n)) {
        Clear(flag,0);
        for(int i=0; i<n; i++){
            scanf("%d",&num[i]);
            flag[num[i]]++;
        }
        int Max = 0;
        for(int i = 1; i <= 1000000; i++){
            Max = max(Max,flag[i]);
        }
        Clear(flag,0);
        for(int i=0; i<n; i++) {
            flag[num[i]]++;
            if(flag[num[i]] == Max){
                printf("%d\n",num[i]);
                break;
            }
        }
    }
return 0;
}





