#include<iostream>
using namespace std;
int facttail(int n,int result=1)
{
if (n==0 || n==1)
return result;

return facttail(n-1,n*result);}


int main()
{
    int n;
    cout<<"enter a positive integer";
    cin>>n;

    if(n<0)
    {
        cout<<"error: factorial is not defined for the negative numbers";

    }
    else{
    	
      cout << "Factorial of " << n << " is: " << facttail(n) << endl;

    }
return 0;
}
