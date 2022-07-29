#include<iostream>
using namespace std;

int Path(int m,int n){
        if(m==1){
            return 1;
        }else if(n==1){
            return 1;
        }else{
            return Path(m-1,n)+Path(m,n-1);
        }
}

int uniquePath(int m,int n){
    return Path(m,n);
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<uniquePath(m,n)<<endl;
    return 0;
}