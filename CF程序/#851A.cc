#include <bits/stdc++.h>

int main(){

	int n,k,t;
	while(~scanf("%d%d%d",&n,&k,&t)) {
		if(t >= 1 && t < k) {
			printf("%d\n",t);
		}
		else if(t >= k && t <= n) {
			printf("%d\n",k);
		}
		else {
			printf("%d\n",k-t+n);
		}
	}
	return 0;
}