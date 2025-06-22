#include <iostream>
#define n 5
using namespace std;
int queue[n];
int f=-1, r=-1;

void enqueue(int value)
{
    if(r=n-1)
    {
        cout<<"queue is full\n";
        return;
    }
    if (f==-1)
    f=0;
    r++;
    queue[r]=value;
    cout<<"value inserted"<<value <<endl;
}

void dequeue()
{
    if(f==-1 || f>r)
    {
        cout<<"queue is empty \n";
        return;

    }
    cout<<"deleted:"<<queue[f]<<endl;
    f++;
}

void display()
{
    if(f==-1 ||  f>r)
    {
        cout<<"queue is empty \n";
        return;
    }
    cout <<"queue\n";
    for(i=f;i<=r;i++)
    cout<<queue[i]<<"";
}
cout<<endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    return 0;
}