#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    int T;
    int n,k;
    int num [2000];
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d%d",&n,&k);
            for(int i = 0; i < n; i++)
                scanf("%d",&num[i]);
            int Count = 0;
            while(1) {
                next_permutation(num,num+n);
                Count++;
                if(Count == k)
                    break;
            }
            printf("%d",num[0]);
            for(int i = 1; i < n; i++){
                printf(" %d",num[i]);
            }
            cout <<endl;
        }
    }
return 0;
}
