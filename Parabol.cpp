#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
struct pair_0
{
   double x0, x2;
};
 
  double func(double x) {
 	double rez=0;
 	rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 	return rez;
 } 
struct pair_0 local(double a, double b, double h, double e)
{
	
	double x0=0,x1=0,x2=0,xx;
	double f1,f2,fx,rez[2];
	x0=a;
	struct pair_0 ttt;
	f1=func(x0);
	
		do {
		h=h/2;
		x2=x0+h;
		f2=func(x2);
		if (f1<=f2)
			{	h=-h;
				x2=x0+h;
				f2=func(x2);
			}
		//cout<<"\n"<<f2;
		}  while (f1<f2 || abs(h)>e);

		if (abs(h)>e){
			do{	x1=x2;
		f1=f2;
		x2=x1+h;
		f2=func(x2);
			}while(f1>=f2);
				if (h>0) 
				{
				a=x1-h;
				b=x2;}
				else {
					a=x2;
					b=x1-h;
					}
			cout<<a<<"\t"<<b;
		}
		else
		{xx=x0;
		fx=func(xx);
		rez[1]=x0;
		rez[2]=x2;
		ttt = {x0,x2};
		}
return ttt;
}



int main (void) {
 	struct pair_0 mass = local (1,2,0.01, 0.0001);
 	// cout << mass.x0<< "  "<< mass.x2;
	
	double h=0.01,a=1,b=2,x0=0,x1=0,x2=0,xx;
	double e=0.0001,f0,f1,f2,fx,x3,f3;
	bool flag;
	x0=mass.x0; x2=mass.x2; x1=x0/x2; //vdala triyka
	
	f0=func(x0);
	f1=func(x1);
	f2=func(x2);
	
	do{
		xx=(x0 + x1)/2 + ((f1 - f0)*(x2 - x0)*(x2 - x1))/(2*((f1 - f0)*(x2 - x0) - (f2 - f0)*(x1 - x0)));	
		fx=func(xx);
		if (abs(x1-xx)>=e && abs(x2-xx)>=e){
			flag=false;
				if (xx<x1){
				x3=x2;
				f3=f2;
				x2=x1;
				f2=f1;
				x1=xx;
				f1=fx;
				}
				else if (xx>x1){
				x3=x2;
				f3=f2;
				x2=xx;
				f2=fx;
				}
			if (f1>f2){
			x0=x1;
			f0=f1;
			x1=x2;
			f1=f2;
			x2=x3;
			f2=f3;
				}
		}
		else flag=true;
	}
	while (flag!=true);
		cout<<xx<<"\t"<<fx;
		
	system("pause");
}