/*
http://blog.csdn.net/allenjy123/article/details/6627751
这个题目其实就是求最近点对的距离。《算法导论》上有详细讲解，王晓东的书上也有代码。主要思想就是分治。先把n个点按x坐标排序，然后求左边n/2个和右边n/2个的最近距离，最后合并。
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