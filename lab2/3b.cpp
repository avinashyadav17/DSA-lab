#include<iostream>
using namespace std;
int fibotail(int n,int a=0, int b=1)
{
if (n==0)
return a;
if (n==1)
return b;

return fibotail(n-1,b,a+b);
}
int main()
{
	int n;
	cout<<"enter the term number N:" ;
   cin>>n;
	if(n<0)
	{
		cout<<"fiboniacci series is not defined for the negative number: ";
	}
	else
	{
		cout<<"fibonacci term "<< n <<" is "<<fibotail(n)<< endl;
	}
	return 0;
	
}
