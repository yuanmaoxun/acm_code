#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define Maxn 1005

using namespace std;

int main(){
    int n,c;
#ifndef ONLINE_JUDGE
    freopen("D://Desktop//×ÀÃæÎÄµµ//input.txt","r",stdin);
#endif
    int time[Maxn];
    int score[Maxn];
    while(~scanf("%d%d",&n,&c)) {
        for(int i = 0; i < n; i++) {
            scanf("%d",&score[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d",&time[i]);
        }
        int sum1 = 0;
        int sum2 = 0;
        int t = 0;
        for(int i = 0; i < n; i++) {
            t+=time[i];
            sum1 += max(0,score[i]-c*t);
        }
        t = 0;
        for(int i = n-1; i >= 0; i--) {
            t+=time[i];
            sum2 += max(0,score[i]-c*t);
        }
        //cout <<sum1 <<" "<<sum2<<endl;
        if(sum1 > sum2) {
            printf("Limak\n");
        }
        else if(sum1 < sum2){
            printf("Radewoosh\n");
        }
        else
            printf("Tie\n");
    }

return 0;
}
