#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef struct _T_ {
    char *color;
    int cnt;
}T;
static long big = 0;
static int bigpos = 0;
static T all[1000000] = {{0}} ;
static long pos[1000000] = {0};
static int N = 0;
int main()
{
    int cnt = 0;
    int len = 0;
    do {
        big = 0;
        bigpos = 0;
        cin>>N;
        if( N == 0) break;
        char temp[512] = {0};
        for(int i = 1; i<=N; i++) {
            memset(temp, 0x00, 512);
            cin>>temp;
            len = strlen(temp);
            long sum = 0;
            int s = 1;
            if(len > 0) {
                for(int j = 0; j<len; j++) {
                    sum += (temp[j]-'a')*s;
                    s++;
                }
                pos[cnt] = sum;
                cnt++;
                if(all[sum].color == NULL) {
                    all[sum].color = new char [len + 1];
                    memset(all[sum].color, 0x00, len + 1);
                    strcpy(all[sum].color, temp);
                }
                all[sum].cnt++;
                if(big < all[sum].cnt) {
                    big = all[sum].cnt;
                    bigpos = sum;
                }
            }
        }
       if(all[bigpos].color != NULL)
           cout<<all[bigpos].color<<endl;

       for(int i = 0; i<cnt; i++) {
           if(all[pos[i]].color != NULL) { delete[] all[pos[i]].color; all[pos[i]].color = NULL;}
           all[pos[i]].cnt = 0;
           pos[i] = 0;
       }
    } while(1);

    return 0;
}
