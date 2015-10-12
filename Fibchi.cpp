//#include "stdafx.h"
#include <math.h>
#include <stdio.h>
//#include <conio.h>
#include <iostream>

using namespace std;
double func(double x) {
 double rez=0;
 rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 return rez;
}

double fibonachi(int numb)// заголовок функции
{
	int fib1 = 0, fib2 = 1;
    int fib = 0;
    int i;
    fib = 1;
 
    for (i = 0; i < numb; i++)
    {
        fib = fib2 + fib1;
        fib2 = fib1;
        fib1 = fib;
    }
    return (fib);
}
 
int main(void)
{
	int i,n=0,k=1;
	double a=1,b=2,x0,x1,x2,xx,delta,u,v;
	double e=0.0001,f,fu,fv,fx=0,Fibchi[100];

	do{
	n++;
	}
	while ((b-a)/(fibonachi(n+2))>e);
	cout<<"Count_Fibchi="<<n;
	

    
    	u=a+((fibonachi(n)/fibonachi(n+2))*(b-a));
    	v=a+b-u;

	fu=func(u);
	fv=func(v);


for (i=1;i<=n;i++)
	{
		if (fu<=fv){
			b=v;
			v=u;
			fv=fu;
			u=a+b-v;
			fu=func(u);	
		}
		else {
			a=u;
			u=v;
			fu=fv;
			v=a+b-u;
			fv=func(v);
		}
	
		if (u>v ){
			u=a+((fibonachi(n-i+1)/fibonachi(n-i+3))*(b-a));  //back to this step, have problem
			v=a+b-u;
			fu=func(u);
			fv=func(v);
		}
	}

	xx=(a+b)/2;
	fx=func(xx);
	
		cout <<"\n"<< xx<<"\t"<<fx<<"\n";
	
	system("pause");  // by Vitalii Yatsenko
}