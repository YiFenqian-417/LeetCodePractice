#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
void uglyNumber(vector<int>&num){
    num.resize(1690);
    num[0]=1;
    int p2=0,p3=0,p5=0;
    int num2,num3,num5;
    for(int i=1;i<num.size();i++){
        num2=num[p2]*2;
        num3=num[p3]*3;
        num5=num[p5]*5;
        num[i]=min(min(num2,num3),num5);
        if(num[i]==num2)p2++;
        if(num[i]==num3)p3++;
        if(num[i]==num5)p5++;
    }
}

void print(vector<int>num){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
        if(i%5==0&&i!=0)cout<<endl;
    }
}


int main(){
    vector<int>num;
    uglyNumber(num);
    print(num);
    return 0;
}