#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    int n,m;
    int num[35][35];
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d",&num[i][j]);
            }
        }
        int sum ;
        int temp;
        bool vis[35][35];
        int index;
        memset(vis,false,sizeof(vis));
        for(int i = 0; i < n; i++) {
            temp = num[i][0];
            sum = 0;
            index = 0;
            for(int j = 0; j < m; j++) {
                if(num[i][j] == temp) {
                    sum ++;
                }
                else {
                    if(sum >= 3) {
                        for(int k = index; k < j; k++) {
                            vis[i][k] = true;
                        }
                    }
                    sum = 1;
                    index = j;
                    temp = num[i][j];
                }
                if(j == m-1) {
                    if(sum >= 3) {
                        for(int k = index; k <= j; k++) {
                            vis[i][k] = true;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; i++) {
            temp = num[0][i];
            sum = 0;
            index = 0;
            for(int j = 0; j < n; j++) {
                if(num[j][i] == temp) {
                    sum ++;
                }
                else {
                    if(sum >= 3) {
                        for(int k = index; k < j; k++) {
                            vis[k][i] = true;
                        }
                    }
                    sum = 1;
                    index = j;
                    temp = num[j][i];
                }
                if(j == n-1) {
                    if(sum >= 3) {
                        for(int k = index; k <= j; k++) {
                            vis[k][i] = true;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j]) {
                    num[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j == m-1){
                    printf("%d\n",num[i][j]);
                }
                else {
                    printf("%d ",num[i][j]);
                }
            }
        }
    }

return 0;
}
