#include<iostream>
#include<string.h>
using namespace std;

static int all[51] = {0};
int main()
{
	int a =0;
	int b = 0;
	int n = 0;
	while(1) {
		cin>>a>>b>>n;
		memset(all, 0x00, sizeof(int)*5);
		if(a == 0 && b == 0 && n == 0) {
			break;
		}
		all[1] = 1;
		all[2] = 1;
		int i = 0;
		for(i = 3; i<51; i++) {
			all[i] = (a*all[i-1]+b*all[i-2])%7;//f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
			//all[1] = all[2];
			//all[2] = all[3];
			if(all[i] == 1 && all[i-1] == 1) {
				break;
			}
		}
		all[0] = all[i-2];		
		cout<<all[n%(i-2)]<<endl;
	}
} 