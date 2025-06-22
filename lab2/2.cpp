#include<iostream>
using namespace std;
int fibo(int n)
{
if (n==0)
return 0;
if(n==1)
return 1;

return fibo(n-1)+fibo(n-2);
}
int main()
{
	int n;
	cout<<"enter the number";
	cin>>n;
	
	if(n<0)
	{
		cout<<"fiboniacci series is not defined for the negative number: ";
	}
	else
	{
		cout<<"fibonacci term "<< n <<" is "<<fibo(n)<< endl;
	}
	return 0;
	
}
