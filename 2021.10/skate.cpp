#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int funcation(vector<vector<int> >site,vector<vector<int>>&dp,int i,int j){
    if(dp[i][j]!=0)return dp[i][j];
    int len=site.size(),len1=site[0].size();
    int now = site[i][j];
    int up=0,down=0,left=0,right=0;
    if(i!=0)up=site[i-1][j];
    if(i!=len-1)down=site[i+1][j];
    if(j!=0)left=site[i][j-1];
    if(j!=len1-1)right = site[i][j+1];
    dp[i][j]=1;
    if(i!=0&&up<now){
        dp[i][j]=max(dp[i][j],funcation(site,dp,i-1,j)+1);
    }
    if(i!=len-1&&down<now){
        dp[i][j]=max(dp[i][j],funcation(site,dp,i+1,j)+1);
    }
    if(j!=0&&left<now){
        dp[i][j]=max(dp[i][j],funcation(site,dp,i,j-1)+1);
    }
    if(j!=len1-1&&right<now){
        dp[i][j]=max(dp[i][j],funcation(site,dp,i,j+1)+1);
    }
    return dp[i][j];
}


int skate(vector<vector<int> >site){
    vector<vector<int> >dp;
    int len=site.size();
    int len1=site[0].size();
    dp.resize(len);
    for(int i=0;i<len;i++){
        dp[i].resize(len1);
        for(int j=0;j<len1;j++){
            dp[i][j]=0;
        }
    }
    int max=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<len1;j++){
            funcation(site,dp,i,j);
        }
        int item = *max_element(dp[i].begin(),dp[i].end());
        if(max<item)max=item;
    } 
    return max;  
}

int main()
{
    vector<vector<int> >site;
    int m,n;
    cin>>m>>n;
    site.resize(m);
    for(int i=0;i<m;i++){
        site[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>site[i][j];
        }
    }
    cout<<skate(site)<<endl;
    return 0;
}