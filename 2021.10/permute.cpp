#include<iostream>
#include<vector>
using namespace std;

void funcation(vector<vector<int>>&ans,vector<int>&item,vector<int>&flag,vector<int>nums){
    if(item.size()==flag.size()){
        ans.push_back(item);
    }else{
        for(int i=0;i<flag.size();i++){
            if(flag[i]==1){
                item.push_back(nums[i]);
                flag[i]=0;
                funcation(ans,item,flag,nums);
                flag[i]=1;
                item.erase(item.begin()+item.size()-1);
            }
        }
    }
}

vector<vector<int> > permute(vector<int>&nums){
    int len = nums.size();
    vector<vector<int> >ans;
    vector<int>item;
    vector<int>flag(len);
    for(int i=0;i<len;i++)flag[i]=1;
    funcation(ans,item,flag,nums);
    return ans;
}

int main()
{
    vector<int>nums;
    vector<vector<int> >ans;
    for(int i=0;i<5;i++){
        nums.push_back(i+1);
    }
    ans = permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}