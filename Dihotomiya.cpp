#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
 
int main(void)
{
	
	double a=1,b=2,x0,x1,x2,xx,delta;
	double e=0.0001,f,f1,f2,fx=0;
	delta=e/3.0;
	do
		{
			x1=(a+b-delta)/2;
			x2=(a+b+delta)/2;
			f1=pow(x1,4.0)+(4*pow(x1,3.0))-(3*x1*x1)-(36*x1)+45;
			f2=pow(x2,4.0)+(4*pow(x2,3.0))-(3*x2*x2)-(36*x2)+45;
				if (f1<=f2)	{
					b=x2;
							}
				else a=x1;
		}
	while (b-a>e);

		xx=(a+b)/2;
		fx=pow(xx,4.0)+(4*pow(xx,3.0))-(3*xx*xx)-(36*xx)+45;
		cout << xx<<"\t"<<fx<<"\n";
	
	system("pause"); //by Vitalii Yatsenko
}

