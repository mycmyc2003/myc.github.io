#include <iostream>
using namespace std;
/*
int main()
{
	int D = 0;


	static const int day = 24*60*60;
	while(1) {
		int times = 0;
		cin>>D;
		float h_d = 0;
		float f_d = 0;
		float m_d = 0;
		if(D == -1) break;
		for(int h = 0; h<24; h++)
			for(int m = 0; m< 60; m++)
				for(int s = 0; s<60; s++) {
					h_d += (h%12 + m/(60*1.0) + s/(3600*1.0))*30;
					h_d = h_d >= 360 ? 0 : h_d;
					f_d += (m + s/(60*1.0))*6;
					f_d = f_d >= 360 ? 0 : f_d;
					m_d += s*6;
					m_d = m_d >= 360 ? 0 : m_d;
					if(abs(h_d-m_d)<D || abs(h_d-m_d) > (360-D)||
						abs(m_d-f_d)<D || abs(m_d-f_d) > (360-D) ||
						abs(h_d-f_d)<D || abs(h_d-f_d) > (360-D)) {
						times++;
					}

				}
		float res = 1-((times*1.0)/day);
		//cout<<res*100<<endl;
		printf("%.3f\n",res*100);

	}
}*/

