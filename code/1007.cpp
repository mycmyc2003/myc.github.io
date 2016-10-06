/*
http://blog.csdn.net/allenjy123/article/details/6627751
�����Ŀ��ʵ�����������Եľ��롣���㷨���ۡ�������ϸ���⣬������������Ҳ�д��롣��Ҫ˼����Ƿ��Ρ��Ȱ�n���㰴x��������Ȼ�������n/2�����ұ�n/2����������룬���ϲ���
����ο������
http://www.acmerblog.com/hdu-1007-Quoit-Design-1262.html
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct _T_{
	float x;
	float y;
}T;
static T all[100000] = {0};
#define MIN(a, b) (a)<(b)?(a):(b)
static T tryit[100000] = {0};
static int cnt = 0;
int compare(const void *a, const void *b)
{
	return (((T*)a)->x - ((T*)b)->x);
}
inline float cal(int l, int r)
{
	double res1 = (all[r].x-all[l].x);
	double res2 = (all[r].y-all[l].y);
	return res1*res1+res2*res2;
	//return (all[r].x-all[l].x)*(all[r].x-all[l].x) + (all[r].y-all[l].y)*(all[r].y-all[l].y);
}
inline float dis(float x1, float y1, float x2, float y2)
{
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

float go(int l, int r)
{
	int mid = l+(r-l)/2;
	if(abs(r-l)==1) return cal(l, r);
	float min_l = go(l, mid);
	float min_r = go(mid, r);
	float small = MIN(min_l, min_r);
	float ref_x = (all[r].x - all[l].x)/2;
	for(int kk = l; kk<r; kk++) 
		if(dis(all[kk].x, ref_x, all[kk].y, all[kk].y) < small)  {tryit[cnt].x = all[kk].x; tryit[cnt].y = all[kk].y; cnt++;}
	float smallest = 999999;
	float temp = 0;
	for(int i = 0; i<cnt; i++) {
		for(int j = l; j<r; j++) {
			temp = dis(tryit[i].x, all[j].x, tryit[i].y, all[j].y);
			smallest = smallest > temp ? temp : smallest;
		}
	}
	cnt = 0;
	return (MIN(smallest, small));

}

int main()
{
	int N = 0;
	while(1) {
		cnt = 0; //clear

		cin>>N;
		if(N == 0) break;
		for(int i = 0; i<N; i++) 
			cin>>all[i].x>>all[i].y;
		qsort(all, N, sizeof(T), compare);
		float res = go(0, N-1);
		//cout<<sqrt(res)/2<<endl;
		printf("%.2f\n", sqrt(res)/2);
		

	}
	
	return 0;
}