#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
bool judge[5000000];
int num[5000005];
int main(){
    memset(judge,false,sizeof(judge));
    num[0] = 0;
    judge[0] = true;
    for(int i = 1; i <= 500000; i++) {
        if(num[i-1]-i>0 && !judge[num[i-1]-i] ) {
            num[i] = num[i-1] - i;
            judge[num[i]] = true;
        }
        else {
            num[i] = num[i-1] + i;
            judge[num[i]] = true;
        }
    }
    int k;
    while(~scanf("%d",&k)) {
        if(k == -1)
            break;
        printf("%d\n",num[k]);
    }

return 0;
}
