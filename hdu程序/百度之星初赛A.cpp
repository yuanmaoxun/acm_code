#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int i,j,k,m,n,Case;
    int a[100005],b[100005];
    long long ans;
    scanf("%d",&Case); {
            for(i=1;i<=Case;i++) {
               scanf("%d",&n);
               for(j=1;j<=n;j++) {
                    scanf("%d",&a[j]);
                    b[j] = a[j];
               }
               sort(a,a+n);
               ans = 0;
               for(j=1;j<=n;j++)
                  if(labs(a[j]-b[j])>ans)
                    ans = labs(a[j]-b[j]);
                printf("Case #%d:\n%I64d\n",i,ans);
    }
            }

return 0;
}
