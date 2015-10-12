#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;
 
  double func(double x) {
 	double rez=0;
 	rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 	return rez;
 }
int main(void)
{
	
	double a=1,b=2,x0,x1,x2,xx,delta,u,v;
	double e=0.0001,f,fu,fv,fx=0;
	int n = 0;
	u=a+(((3-sqrt(5.0))/2)*(b-a));
	v=a+b-u;
	fu=func(u);
	fv=func(v);
	do
		{ n++;	
			if(fu<=fv)
				{
					b=v;
					v=u;
					fv=fu;
					u=a+b-v;
					fu=func(u);
				}
			else 
				{
					a=u;
					u=v;
					fu=fv;
					v=a+b-u;
					fv=func(v);
				}
			if (u>v) 
				{
					u=a+(((3-sqrt(5.0))/2)*(b-a));
					v=a+b-u;
					fu=func(u);
					fv=func(v);
				}
		}
			while (b-a>e);
			xx=(a+b)/2;
			fx=func(xx);

	
		cout << xx<<"\t"<<fx<<"\n";
		cout << "n" << n<< "\t"<<e;
	
	system("pause");  // by Vitalii Yatsenko
}