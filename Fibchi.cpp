//#include "stdafx.h"
#include <math.h>
#include <stdio.h>
//#include <conio.h>
#include <iostream>

using namespace std;

double fibonachi(int numb)// заголовок функции
{
    double rezult = 0; // инициализируем переменную rezult значением 1
    rezult=((pow((1+sqrt(5.0))/2, numb)-pow((1-sqrt(5.0))/2, numb))/sqrt(5.0));
    return (rezult);
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
	
/*	for (i=1;i<=n;i++)
	{
		Fibchi[i]=((pow((1+sqrt(5.0))/2, i)-pow((1-sqrt(5.0))/2, i))/sqrt(5.0));
	}*/
    
    	u=a+((fibonachi(n)/fibonachi(n+2))*(b-a));
    	v=a+b-u;

	fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
	fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;

	//u=a+(((3-sqrt(5.0))/2)*(b-a));
for (i=1;i<=n;i++)
	{
		if (fu<=fv){
			b=v;
			v=u;
			fv=fu;
			u=a+b-v;
			fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;	
		}
		else {
			a=u;
			u=v;
			fu=fv;
			v=a+b-u;
			fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
		}
	
		if (u>v ){
			u=a+((fibonachi(n-i+1)/fibonachi(n-i+3))*(b-a));  //back to this step, have problem
			v=a+b-u;
			fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
			fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;
		}
	}

	xx=(a+b)/2;
	fx=pow(xx,4.0)+(4*pow(xx,3.0))-(3*xx*xx)-(36*xx)+45;
	
		cout <<"\n"<< xx<<"\t"<<fx<<"\n";
	
	system("pause");  // by Vitalii Yatsenko
}
