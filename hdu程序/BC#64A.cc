# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int divMod(char* ch,int num)
{
	int s = 0;
	for(int i=0;ch[i]!='\0';i++)
		s = (s*10+ch[i]-'0')%num;

	return s;
}

int main()
{
	int test,num,m;
	char list[500];
		while(~scanf("%s",list)){
            if(divMod(list,2) == 0|| divMod(list,3) == 0|| divMod(list,5) == 0)
                cout << "YES" <<endl;
            else{
                cout << "NO" <<endl;
            }
		}
	return 0;
}

