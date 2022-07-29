#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int funcation(vector<vector<int> >data,int times){
    vector<vector<int> >dp;
    int len = data.size();
    dp.resize(len);
    for(int i=0;i<len;i++){
        dp[i].resize(times+1);
        for(int j=0;j<times+1;j++){
            if(i==0){
                if(j<data[0][0])dp[i][j]=0;
                else dp[i][j]=data[0][1];
            }else if(j==0){
                dp[i][j]=0;
            }else{
                if(j<data[i][0])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-data[i][0]]+data[i][1]);
            }
        }
    }
    return *max_element(dp[len-1].begin(),dp[len-1].end());
}

int main()
{
    int times,num;
    vector<vector<int> >data;
    cin>>times>>num;
    data.resize(num);
    for(int i=0;i<num;i++){
        data[i].resize(2);
        cin>>data[i][0]>>data[i][1];
    }
    cout<<funcation(data,times)<<endl;
    return 0;
}