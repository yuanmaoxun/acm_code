#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int i,j,k,m,n;
    int v1,v2,sum;
    int d,t;
    while(cin >> v1 >> v2){
        cin >> t >> d;
        sum = 0;
        for(i=0;i<=t-1;i++)
            sum+=min(v2+(t-i-1)*d,v1+i*d);
        printf("%d\n",sum);
    }
return 0;
}
