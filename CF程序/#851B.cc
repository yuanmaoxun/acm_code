#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;

int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }

int main(){
	long long ax,ay,bx,by,cx,cy;
	while(~scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy)) {
		double chaji = (bx-ax)*(cy-by)-(by-ay)*(cx-bx);
		if(dcmp(chaji)==0) {
			printf("No\n");
			continue;
		}
		long long lena,lenb;
		lena = (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
		lenb = (cx-bx)*(cx-bx)+(cy-by)*(cy-by);
		//cout << lena <<" "<< lenb << endl;
		if (lena == lenb) {
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}