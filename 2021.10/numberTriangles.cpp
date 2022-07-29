#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int funcation(vector<vector<int> >triangles){
    int len =triangles.size();
    vector<vector<int> >dp(len);
    dp[0].resize(1);
    dp[0][0]=triangles[0][0];
    for(int i=1;i<len;i++){
        int len1 = triangles[i].size();
        dp[i].resize(len1);
        for(int j=0;j<len1;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]+triangles[i][j];
            }else if(j==len1-1){
                dp[i][j]=dp[i-1][j-1]+triangles[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+triangles[i][j];
            }
        }  
    }
    return *max_element(dp[len-1].begin(),dp[len-1].end());
}

int main()
{
    vector<vector<int> >triangles;
    int num;
    cin>>num;
    triangles.resize(num);
    for(int i=0;i<num;i++){
        triangles[i].resize(i+1);
        for(int j=0;j<i+1;j++){
            cin>>triangles[i][j];
        }
    }
    cout<<funcation(triangles)<<endl;
    return 0;
}