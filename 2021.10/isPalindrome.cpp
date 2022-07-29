#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isPalindrome(int x);

int main()
{
    cout<<isPalindrome(10)<<endl;
    return 0;
}

bool isPalindrome(int x) {
        stack<int>nums;
        vector<int>num;
        int item;
        if(x<0)return false;
        else if(x==0)return true;
        else{
            while(x!=0){
                item=x%10;
                nums.push(item);
                num.push_back(item);
                x /= 10;
           }
           int i=0;
           while(!nums.empty()){
               if(nums.top()!=num[i])return false;
               else{
                   nums.pop();
                   i++;
               }
           }
           return true;
        }
}