
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;


int main(){

#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    long long n;
    while(~scanf("%lld",&n)) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        printf("%d\n",sum);
    }

return 0;
}
