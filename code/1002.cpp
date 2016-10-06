#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static char a[1001] = {0};
static char b[1001] = {0};
static char ta[1001] = {0};
static char tb[1001] = {0};
static char c[1003] = {0};
static int lena = 0;
static int lenb = 0;

int N = 0;
int main() {
	// your code goes here
	cin>>N;
	for(int i = 0; i<N; i++) {
		cin>>ta>>tb;
		lena = strlen(ta);
		lenb = strlen(tb);

		a[0] = '0';
		int m = 0;
		while(ta[m] == '0') m++;
		for(int i = m, n= 0; m<lena; m++, n++) a[n] = ta[m];
		b[0] = '0';
		m = 0;
		while(tb[m] == '0') m++;
		for(int i = m, n= 0; m<lenb; m++, n++) b[n] = tb[m];

		lena = strlen(a);
		lenb = strlen(b);
		int posa = lena-1;
		int posb = lenb-1;
		int posc = 0;
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int more = 0;
		while(posa >= 0 || posb >= 0 || more > 0) {
			//cout<<posc<<endl;
			n1 = posa < 0 ? 0 : (a[posa] - '0');
			n2 = posb < 0 ? 0 : (b[posb] - '0');
			n3 = n1 + n2 + more;
			//cout<<"n1-"<<n1<<" n2-"<<n2<<endl;
			more = 0;
			if (n3>=10) {
               n3 -= 10;
               more = 1;
            }
            c[posc] = n3 + '0';
            posa--;// = (posa - 1) < 0 ? 0 :(posa - 1);
            posb--;// = (posb - 1) < 0 ? 0 :(posb - 1);
            posc ++;
		}
		//cout<<"posc: "<<posc<<endl;
		/*int k = posc - 1;
		while(c[k] == '0' && k > 0) {
			c[k] = 0;
			k--;
		}*/

		char *out = new char[posc+1];
		memset(out, 0x00, posc+1);
		for(int i = 0, j = posc-1; i<posc; i++, j--) {
			out[i] = c[j];
		}

		cout<<"Case "<<i+1<<":"<<endl;
		cout<<a<<" + "<<b<<" = "<<out<<endl;
		if(i != N-1)
			cout<<endl;
		delete[] out;
		memset(a, 0x00, 1001);
		memset(ta, 0x00, 1001);
		memset(tb, 0x00, 1001);
		memset(b, 0x00, 1001);
		memset(c, 0x00, 1003);
	}


	return 0;
}
