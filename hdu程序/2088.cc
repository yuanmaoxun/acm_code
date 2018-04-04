#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&(n!=0)){
		int i,v=0,k=0,a[999];
		for(i=0;i<n;i++){
			cin>>a[i];
			v+=a[i];
		}
		v=v/n;
		for(i=0;i<n;i++)
		if(a[i]>v)
		k=k+a[i]-v;
		cout<<k<<endl;
		cout<<endl;
	}
}
