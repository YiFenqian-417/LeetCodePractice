#include<iostream>
#include<vector>
using namespace std;

int maxLine(vector<int>nums1,vector<int>nums2);

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int num1Length=nums1.size();
    int num2Length=nums2.size();
    if(num1Length==0||num2Length==0)return 0;
    return maxLine(nums1,nums2);
}

int maxLine(vector<int>nums1,vector<int>nums2){
    if(nums1.size()==0||nums2.size()==0)return 0;
    else{
        int flag=1,i=0;
        for(i=0;i<nums2.size();i++){
            if(nums1[0]==nums2[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            nums1.erase(nums1.begin());
            return maxLine(nums1,nums2);
        }else{
            for(i;i>=0;i--){
                nums2.erase(nums2.begin());
            }
            return 1+maxLine(nums1,nums2);
        }
    }
}
int main(){
    vector<int>nums1={2,5,1,2,5};
    vector<int>nums2={10,5,2,1,5,2};
    int max=maxUncrossedLines(nums1,nums2);
    cout<<max<<endl;
    return 0;
}