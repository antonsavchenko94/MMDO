#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
 
int main(void)
{
	
	double a=1,b=2,x0,x1,x2,xx,delta,u,v;
	double e=0.0001,f,fu,fv,fx=0;
	u=a+(((3-sqrt(5.0))/2)*(b-a));
	v=a+b-u;
	fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
	fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
	do
		{	
			if(fu<=fv)
				{
					b=v;
					v=u;
					fv=fu;
					u=a+b-v;
					fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
				}
			else 
				{
					a=u;
					u=v;
					fu=fv;
					v=a+b-u;
					fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
				}
			if (u>v) 
				{
					u=a+(((3-sqrt(5.0))/2)*(b-a));
					v=a+b-u;
					fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
					fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
				}
		}
			while (b-a>e);
			xx=(a+b)/2;
			fx=pow(xx,4.0)+(4*pow(xx,3.0))-(3*xx*xx)-(36*xx)+45;

	
		cout << xx<<"\t"<<fx<<"\n";
	
	system("pause");  // by Vitalii Yatsenko
}

