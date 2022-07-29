#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int x,y,horsex,horsey;
    vector<vector<long long> >dp;
    cin>>x>>y>>horsex>>horsey;
    dp.resize(x+1);
    for(int i=0;i<x+1;i++){
        dp[i].resize(y+1);
        for(int j=0;j<y+1;j++){
            if(i==horsex&&j==horsey)dp[i][j]=0;
            else if(abs(i-horsex)==2&&abs(j-horsey)==1)dp[i][j]=0;
            else if(abs(i-horsex)==1&&abs(j-horsey)==2)dp[i][j]=0;
            else if(i==0||j==0){
                if(i==0&&j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }   
    cout<<dp[x][y]<<endl;
    return 0;
}