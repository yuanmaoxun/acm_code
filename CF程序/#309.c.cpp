#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int A(int m);
    int C(int m);
    int i,j,k,m,n;
    int sum,ans,res;
    while(~scanf("%d",&n)){
        sum = 0;
        ans = 1;
        res = 1;
        for(i=0;i<n;i++){
            cin >> m;
            sum += m;
            for(j=1;j<=m;j++){
                if(j == m)
                   ans += A(sum) /C(m);
                else
                    ans += A(sum);
            }
        res *= ans;
        }
        cout << res%1000000007 << endl;
    }

}
int A(int m){
    int sum = 1,i;
    for(i=1;i<=m+1;i++)
        sum*=i;
    return sum;
}
int C(int m) {
    int sum = 1,i;
    for(i = 1;i<= m;i++)
        sum*= i;
    return sum;
}
