#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int num;
    vector<int>dp(20);
    cin>>num;
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=num;i++){
       for(int j=0;j<i;j++) {
           dp[i]+=dp[j]*dp[i-j-1];
       }
    }
    cout<<dp[num];
    return 0;
}