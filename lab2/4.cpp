#include <iostream>
using namespace std;

void TOH(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        return;
    }
    TOH(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << c << endl;
    TOH(n - 1, b, a, c);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}










/*#include<iostream>
using namespace std;

void toh(int n, char src, char des, char aux)
{
    if(n == 1)
    {
        cout << "Move disk 1 from " << src << " to " << des << endl;
        return;
    }
    
    toh(n - 1, src, aux, des);  // Move n-1 disks from src to aux
    cout << "Move disk " << n << " from " << src << " to " << des << endl; // Move nth disk to des
    toh(n - 1, aux, des, src);  // Move n-1 disks from aux to des
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;  // ? Fix: take input for number of disks

    toh(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary

    return 0;
}*/
