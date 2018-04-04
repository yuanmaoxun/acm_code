#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    long long l1,r1,l2,r2,k;
    while(~scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&k)) {
        long long ans ;
        if(l1 >= l2 && r1 <= r2) {
            ans = r1-l1+1;
            if(k >= l1 && k <= r1)
                ans --;
        }
        else if(l1 <= l2 && r1 <= r2) {
            ans = r1-l2+1;
            if(k >= l2 && k <= r1)
                ans --;

        }
        else if(l1 <= l2 && r1 >= r2){
            ans = r2-l2+1;
            if(k >= l2 && k <= r2)
                ans --;
        }
        else if(l2 <= l1 && r2 <= r1){
            ans = r2-l1+1;
            if(k >= l1 && k <= r2)
                ans --;
        }
        else {
            ans = 0;
        }

        printf("%lld\n",max(ans,(long long)0));
    }

return 0;
}
