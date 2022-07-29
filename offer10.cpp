#include<iostream>
#include<vector>
using namespace std;

void fib(int n);

int main()
{
    fib(100);
    return 0;
}

void fib(int n) {
    int MOD = 1000000007;
    vector<long long int>number(101);
    number[0] = 0;
    number[1] = 1;
    for(int i=2 ; i< n+1 ;i++){
        number[i] = (number[i-1] + number[i-2])% MOD ;
        cout<<i<<": "<<number[i]<<endl;
    }
}