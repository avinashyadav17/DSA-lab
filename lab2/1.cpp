#include<iostream>
using namespace std;
int fact(int n)
{
if (n==0 || n==1)
return 1;

return n*fact(n-1);
}

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
    	
      cout << "Factorial of " << n << " is: " << fact(n) << endl;

    }
return 0;
}
