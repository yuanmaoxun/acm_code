//kengkeng
#include<bits/stdc++.h>
#define Maxn 10005
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

int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n;
    int odd[Maxn];
    int even[Maxn];
    int num[Maxn];
    int x;
    while(~scanf("%d",&n)) {
        for(int i = 0; i < n;i++) {
            scanf("%d",&num[i]);
        }
        sort(num, num + n);
        int k = 0;
        for(int i = n-1; i > (n-1)/2; i--) {
            even[k++] = num[i];
        }
        //cout <<"*" <<k<<endl;
        int j = k;
        k = 0;
        int flag = 1;
        for(int i = 0; i < n-j; i++) {
            if(!flag){
                printf(" %d ",even[k]);
                k++;
                flag = 1;
            }
            printf("%d",num[i]);
            flag = 0;
        }
        //cout <<"*" <<k <<j<<endl;
        if(k != j) {
            printf(" %d\n",even[j-1]);
        }
        else
            puts("");
    }
return 0;
}





