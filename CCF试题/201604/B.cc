
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
    int num[15][10];
    int drop[4][4];
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 10; j++) {
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d",&drop[i][j]);
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 0; i < 15; i++) {
        for(int j = n-1; j<n+3; j++) {

        }

    }

return 0;
}
