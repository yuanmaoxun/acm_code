#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define PI 3.1415926535898
using namespace std;
int main(){
    int t,i,j,k,m,n;
    int a[205],sum[205];
    while(~scanf("%d",&t)){
        while(t--){
            cin >> n >> m;
        for(i=0;i<n;i++)
            cin >> a[i];
           for(i=0;i<n;i++)
            sum[i]=a[i];
        for(j=0;j<n;j++)
            for(i=1;i<=m-1;i++){
               if(j-i<0)
            sum[j] += a[n-i];
            else
                sum[j]+= a[j-i];
        }
        sort(sum,sum+n);
        cout << sum[n-1]<<"\n";
        }

    }
return 0;
}
