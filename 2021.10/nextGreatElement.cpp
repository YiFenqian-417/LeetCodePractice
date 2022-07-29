#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        for(int i=0;i<nums1.size();i++){
            int flag=0;
            int j=0;
            if(nums1[i]>=*max_element(nums2.begin()+i,nums2.end())){
                nums3.push_back(-1);
            }else{
                for(j=0;j<nums2.size();j++){
                    if(nums2[j]==nums1[i]){
                        flag=1;
                        break;
                    }
                }
                for(int k=j;k<nums2.size();k++){
                    if(nums2[k]>nums1[i]){
                        nums3.push_back(nums2[k]);
                        flag=0;
                        break;
                    }    
                }
                if(flag)nums3.push_back(-1);
            }
        }
        return nums3;      
    }
int main(){
    vector<int>nums1={4,1,2};
    vector<int>nums2={1,3,4,2};
    vector<int>nums3=nextGreaterElement(nums1,nums2);
}