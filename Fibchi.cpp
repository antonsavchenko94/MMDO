//#include "stdafx.h"
#include <math.h>
#include <stdio.h>
//#include <conio.h>
#include <iostream>

using namespace std;
<<<<<<< HEAD
double func(double x) {
 double rez=0;
 rez= pow(x,4.0)+(4*pow(x,3.0))-(3*x*x)-(36*x)+45;
 return rez;
}

double fibonachi(int numb)// ��������� �������
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
=======

double fibonachi(int numb)// заголовок функции
{
    double rezult = 0; // инициализируем переменную rezult значением 1
    rezult=((pow((1+sqrt(5.0))/2, numb)-pow((1-sqrt(5.0))/2, numb))/sqrt(5.0));
    return (rezult);
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
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
	
<<<<<<< HEAD

=======
/*	for (i=1;i<=n;i++)
	{
		Fibchi[i]=((pow((1+sqrt(5.0))/2, i)-pow((1-sqrt(5.0))/2, i))/sqrt(5.0));
	}*/
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
    
    	u=a+((fibonachi(n)/fibonachi(n+2))*(b-a));
    	v=a+b-u;

<<<<<<< HEAD
	fu=func(u);
	fv=func(v);


=======
	fu=pow(u,4.0)+(4*pow(u,3.0))-(3*u*u)-(36*u)+45;
	fv=pow(v,4.0)+(4*pow(v,3.0))-(3*v*v)-(36*v)+45;

	//u=a+(((3-sqrt(5.0))/2)*(b-a));
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
for (i=1;i<=n;i++)
	{
		if (fu<=fv){
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
		else {
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
	
		if (u>v ){
			u=a+((fibonachi(n-i+1)/fibonachi(n-i+3))*(b-a));  //back to this step, have problem
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

	xx=(a+b)/2;
<<<<<<< HEAD
	fx=func(xx);
=======
	fx=pow(xx,4.0)+(4*pow(xx,3.0))-(3*xx*xx)-(36*xx)+45;
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
	
		cout <<"\n"<< xx<<"\t"<<fx<<"\n";
	
	system("pause");  // by Vitalii Yatsenko
<<<<<<< HEAD
}
=======
}
>>>>>>> 021a6a1c8e35ba49d934d468d1e1a1b8bf7f8933
