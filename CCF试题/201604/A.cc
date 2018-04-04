#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
int T;
int num[1005];
    while(~scanf("%d",&T)) {
        for(int i = 0; i < T; i++) {
            scanf("%d",&num[i]);
        }
        if(T == 1 || T == 2) {
            printf("0\n");
            continue;
        }
        int ans = 0;
        for(int i = 1; i < T-1; i++) {
            if((num[i-1] < num[i] && num[i] > num[i+1]) || (num[i-1] > num[i] && num[i] < num[i+1]))
                ans++;
        }
        printf("%d\n",ans);
    }

return 0;
}
