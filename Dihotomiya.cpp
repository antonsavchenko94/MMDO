// #include "stdafx.h"
#include <math.h>
#include <stdio.h>
// #include <conio.h>
#include <iostream>

using namespace std;

double func(double x) {
 double rez=0;
 rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 return rez;
}

int main(void)
{
	
	double a=1,b=2,x0,x1,x2,xx,delta;
	double e=0.0001,f,f1,f2,fx=0;
	delta=e/3.0;
	do
		{
			x1=(a+b-delta)/2;
			x2=(a+b+delta)/2;
			f1=func(x1);
			f2=func(x2);
				if (f1<=f2)	{
					b=x2;
							}
				else a=x1;
		}
	while (b-a>e);

		xx=(a+b)/2;
		fx=func(xx);
		cout << xx<<"\t"<<fx<<"\n";
	
	system("pause"); //by Vitalii Yatsenko
}