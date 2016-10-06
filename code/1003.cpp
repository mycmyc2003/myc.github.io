#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;

static int a[100000] = {0};
static int T = 0;
static int biggest = 0;
static int s_pos = 0;
static int e_pos = 0;
/*
inline static void check(int n)
{
    if(n == 1) {
        biggest = a[1];
        s_pos = 1;
        e_pos = 1;
        return;
    }

    long sum = 0;
    for(int i = n; i>=1; i--) {
        sum += a[i];
        if(sum >= biggest) {
            biggest = sum;
            s_pos = i;
            e_pos = n;
        }
    }

}*/

int main()
{
    cin>>T;
    for(int t = 1; t<=T; t++) {
        biggest = 0;
        s_pos = 0;
        e_pos = 0;

        //int in;
        //char c;

        int cnt = 0;
        cin>>cnt;
        long long sum = 0;
        s_pos = 1;
        e_pos = 1;
        int temp_s = s_pos;
        int temp_e = e_pos;
        for(int i = 1; i<=cnt; i++) {
            cin>>a[i];
            if(i == 1) biggest = a[1];
            sum += a[i];
            if(sum >= 0) {
                temp_e = i;
                if(sum >= biggest) {
                    biggest = sum;
                    s_pos = temp_s;
                    e_pos = temp_e;
                }
            } else if(sum < 0){
                sum = 0;
                if(a[i] > biggest) {
                    biggest = a[i];
                    s_pos = i;
                    e_pos = i;
                }
                temp_s = (i+1) > cnt ? cnt : (i+1);
                temp_e = temp_s;
            }
        }
        /*while((c=getchar())!='\n')
        {
            if((c>='0'&&c<='9') || c == '-')
            {
                str += c;
            }
            else if(c ==' ')
            {
                a[cnt] = atoi(str.c_str());
                check(cnt);

                str = "";
                cnt++;
            }
        }
        a[cnt] = atoi(str.c_str());

        check(cnt);*/
        //for(int i = 1; i<= cnt; i++)
            //cout<<a[i]<<endl;
         //cout<<"cnt: "<<cnt<<endl;
         cout<<"Case "<<t<<":"<<endl;
         cout<<biggest<<" "<<s_pos<<" "<<e_pos<<endl;
         if(t != T) cout<<endl;

    }



    return 0;
}
