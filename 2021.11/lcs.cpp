#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>a(num);
    vector<int>b(num);
    vector<vector<int> >dp(num+1);
    for(int i=0;i<num;i++)cin>>a[i];
    for(int i=0;i<num;i++)cin>>b[i];
    for(int i=0;i<num+1;i++){
        dp[i].resize(num+1);
        for(int j=0;j<num+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else{
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[num][num]<<endl;
    return 0;
}