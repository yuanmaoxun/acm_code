#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int i,j,k,m,n;
    long long d1, d2, d3;
    scanf("%d%d%d",&d1, &d2, &d3);
    int sum1, sum2, sum3, sum4;
    sum1 = d1+d2+d3;
    sum2 = 2 * (d1+d3);
    sum3 = 2 * (d2+d3);
    sum4 = 2* (d1+d2);
    int ans = min(sum4, min(sum1, min(sum2, sum3)));
    cout << ans;
return 0;
}
