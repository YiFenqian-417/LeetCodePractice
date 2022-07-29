#include<iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int a=1,b=1,c=1;
    for(int i=1;i<num;i++){
        a=b;
        b=c;
        c=a+b;
    }
    cout<<c<<endl;
}