<<<<<<< HEAD
#include <math.h>
#include <stdio.h>
=======
#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <conio.h>
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
#include <iostream>

using namespace std;
 
<<<<<<< HEAD
  double func(double x) {
 	double rez=0;
 	rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 	return rez;
 }
=======
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
int main(void)
{
	
	double a=1,b=2,x0,x1,x2,xx,delta,u,v;
	double e=0.0001,f,fu,fv,fx=0;
<<<<<<< HEAD
	int n = 0;
	u=a+(((3-sqrt(5.0))/2)*(b-a));
	v=a+b-u;
	fu=func(u);
	fv=func(v);
	do
		{ n++;	
=======
	u=a+(((3-sqrt(5.0))/2)*(b-a));
	v=a+b-u;
	fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
	fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
	do
		{	
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
			if(fu<=fv)
				{
					b=v;
					v=u;
					fv=fu;
					u=a+b-v;
<<<<<<< HEAD
					fu=func(u);
=======
					fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
				}
			else 
				{
					a=u;
					u=v;
					fu=fv;
					v=a+b-u;
<<<<<<< HEAD
					fv=func(v);
=======
					fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
				}
			if (u>v) 
				{
					u=a+(((3-sqrt(5.0))/2)*(b-a));
					v=a+b-u;
<<<<<<< HEAD
					fu=func(u);
					fv=func(v);
=======
					fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
					fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
				}
		}
			while (b-a>e);
			xx=(a+b)/2;
<<<<<<< HEAD
			fx=func(xx);

	
		cout << xx<<"\t"<<fx<<"\n";
		cout << "n" << n<< "\t"<<e;
	
	system("pause");  // by Vitalii Yatsenko
}
=======
			fx=pow(xx,4.0)+(4*pow(xx,3.0))-(3*xx*xx)-(36*xx)+45;

	
		cout << xx<<"\t"<<fx<<"\n";
	
	system("pause");  // by Vitalii Yatsenko
}

>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
