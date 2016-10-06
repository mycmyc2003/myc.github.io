/*
http://blog.csdn.net/allenjy123/article/details/6627751
�����Ŀ��ʵ�����������Եľ��롣���㷨���ۡ�������ϸ���⣬������������Ҳ�д��롣��Ҫ˼����Ƿ��Ρ��Ȱ�n���㰴x��������Ȼ�������n/2�����ұ�n/2����������룬���ϲ���
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

int compare(const void *a, const void *b)
{
	return (((T*)a)->x - ((T*)b)->x);
}
float cal(int l, int r)
{
	double res1 = (all[r].x-all[l].x);
	double res2 = (all[r].y-all[l].y);
	return res1*res1+res2*res2;
	//return (all[r].x-all[l].x)*(all[r].x-all[l].x) + (all[r].y-all[l].y)*(all[r].y-all[l].y);
}

float go(int l, int r)
{
	int mid = l+(r-l)/2;
	if(abs(r-l)==1) return cal(l, r);
	float min_l = go(l, mid);
	float min_r = go(mid, r);
	
	return (MIN(min_l, min_r));

}

int main()
{
	int N = 0;
	while(1) {
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